#include "vector.h"

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Nombre total de tests.
int const tests_total = 66;

// Nombre total de tests exécutés. 
int tests_executed = 0;

// Pour chaque test qui réussi, cette variable sera incrémentée de 1.
// Le but est de la garder égale à test_executes.
int tests_successful = 0;

// Incrémente le nombre de test exécutés de 1.
// Si le test réussi, incrémente le nombre de tests réussis de 1.
#define TEST(x) tests_executed += 1;    \
                if(x)                   \
                {                       \
                    tests_successful += 1; \
                    printf("[SUCCES] ");\
                }                       \
                else                    \
                {                       \
                    printf("[ECHEC ] ");\
                }                       \
                printf("%s:%d:0 : %s\n", __FILE__, __LINE__, #x);

// Affiche le sommaire des résultats des tests.
void print_summary()
{
    printf("---\nNombre de tests\t:%d\nTests executes\t:%2d\nTests reussis\t:%2d\n", tests_total, tests_executed, tests_successful);
}

// Fonction à executer lors d'une segmentation fault.
// On imprime les résultats obtenus jusqu'à lors et on arrête immédiatement le programme.
void segfault_sigaction(int signal, siginfo_t *si, void *arg)
{
    printf("[SEGFAULT]\n");
    print_summary();
    exit(tests_total - tests_successful);
}

int main()
{
    // Mise en place de la fonction à exécuter lors d'une segmentation fault.
    struct sigaction sa;
    memset(&sa, 0, sizeof(struct sigaction));
    sigemptyset(&sa.sa_mask);
    sa.sa_sigaction = segfault_sigaction;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGSEGV, &sa, NULL);

    float const growth_factor_doubling = 2.;

    // Tests de la fonction 'make_vector', 'size' et 'capacity'.
    {
        vector const v0 = make_vector(sizeof(int), 0, growth_factor_doubling);

        // Tests intrusifs.
        TEST((v0.data == NULL));
        TEST((v0.element_size == sizeof(int)));

        // Tests avec l'interface.
        TEST((size(v0) == 0));
        TEST((capacity(v0) == 0));
        
        destroy(v0);


        vector const v1 = make_vector(sizeof(int), 1, growth_factor_doubling);

        TEST((v1.data != NULL));
        TEST((v1.element_size == sizeof(int)));
        TEST((size(v1) == 1));
        TEST((capacity(v1) == 1));

        destroy(v1);

        vector const v10 = make_vector(sizeof(int), 10, growth_factor_doubling);

        TEST((v10.data != NULL));
        TEST((v10.element_size == sizeof(int)));
        TEST((size(v10) == 10));
        TEST((capacity(v10) == 10));

        destroy(v10);
    }


    // Tests de base entre itérateurs.
    {
        vector const v0 = make_vector(sizeof(int), 0, growth_factor_doubling);
        vector const v1 = make_vector(sizeof(int), 1, growth_factor_doubling);
        vector const v10 = make_vector(sizeof(int), 10, growth_factor_doubling);


        iterator const b0 = begin(v0);
        iterator const e0 = end(v0);
        TEST((compare(b0, e0) == 0));


        iterator b1 = begin(v1);
        iterator const e1 = end(v1);
        TEST((compare(b1, e1) < 0));
        TEST((compare(e1, b1) > 0));

        increment(b1, 1);
        TEST((compare(b1, e1) == 0));
        decrement(b1, 1);
        TEST((compare(b1, e1) < 0));

        iterator i = at(v1, 0);
        TEST((compare(i, begin(v1)) == 0));
        increment(i, 1);
        TEST((compare(i, end(v1)) == 0));
        decrement(i, 1);
        TEST((compare(i, begin(v1)) == 0));


        iterator b10 = begin(v10);
        iterator const e10 = end(v10);
        TEST((compare(b10, e10) < 0));
        TEST((compare(e10, b10) > 0));

        increment(b10, 1);
        TEST((compare(b10, e10) < 0));
        increment(b10, 1);
        TEST((compare(b10, e10) < 0));
        increment(b10, 8);
        TEST((compare(b10, e10) == 0));

        destroy(v0);
        destroy(v1);
        destroy(v10);
    }

    print_summary();

    return tests_total - tests_successful;
}
