#include "vector.h"

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Nombre total de tests.
int const tests_total = 85;

// Nombre total de tests exécutés. 
int tests_executed = 0;

// Pour chaque test qui réussi, cette variable sera incrémentée de 1.
// Le but est de la garder égale à test_executes.
int tests_successful = 0;

// Incrémente le nombre de test exécutés de 1.
// Si le test réussi, incrémente le nombre de tests réussis de 1.
#define TEST(x) printf("%s:%d:0 %*s : ", __FILE__, __LINE__, __LINE__ < 100 ? -41 : -40, #x); \
                tests_executed += 1;    \
                if(x)                   \
                {                       \
                    tests_successful += 1; \
                    printf("[SUCCES]\n");\
                }                       \
                else                    \
                {                       \
                    printf("[ECHEC]\n");\
                }

// Affiche le sommaire des résultats des tests.
void print_summary()
{
    printf("---\n%-20s : %d\n%-20s : %2d\n%-20s : %2d\n", "Nombre de tests", "Tests executes", "Tests reussis", tests_total, tests_executed, tests_successful);
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
        vector v0 = make_vector(sizeof(int), 0, growth_factor_doubling);

        // Tests intrusifs.
        TEST((v0.data == NULL));
        TEST((v0.element_size == sizeof(int)));

        // Tests avec l'interface.
        TEST((size(v0) == 0));
        TEST((capacity(v0) == 0));
        
        destroy(&v0);


        vector v1 = make_vector(sizeof(int), 1, growth_factor_doubling);

        TEST((v1.data != NULL));
        TEST((v1.element_size == sizeof(int)));
        TEST((size(v1) == 1));
        TEST((capacity(v1) == 1));

        destroy(&v1);

        vector v10 = make_vector(sizeof(int), 10, growth_factor_doubling);

        TEST((v10.data != NULL));
        TEST((v10.element_size == sizeof(int)));
        TEST((size(v10) == 10));
        TEST((capacity(v10) == 10));

        destroy(&v10);
    }


    // Tests de base entre itérateurs.
    {
        vector v0 = make_vector(sizeof(int), 0, growth_factor_doubling);
        vector v1 = make_vector(sizeof(int), 1, growth_factor_doubling);
        vector v10 = make_vector(sizeof(int), 10, growth_factor_doubling);


        iterator const b0 = begin(&v0);
        iterator const e0 = end(&v0);
        TEST((compare(b0, e0) == 0));


        iterator b1 = begin(&v1);
        iterator const e1 = end(&v1);
        TEST((compare(b1, e1) < 0));
        TEST((compare(e1, b1) > 0));

        increment(&b1, 1);
        TEST((compare(b1, e1) == 0));
        decrement(&b1, 1);
        TEST((compare(b1, e1) < 0));

        iterator i = at(&v1, 0);
        TEST((compare(i, b1) == 0));
        increment(&i, 1);
        TEST((compare(i, e1) == 0));
        decrement(&i, 1);
        TEST((compare(i, b1) == 0));


        iterator b10 = begin(&v10);
        iterator const e10 = end(&v10);
        TEST((compare(b10, e10) < 0));
        TEST((compare(e10, b10) > 0));

        increment(&b10, 1);
        TEST((compare(b10, e10) < 0));
        increment(&b10, 1);
        TEST((compare(b10, e10) < 0));
        increment(&b10, 8);
        TEST((compare(b10, e10) == 0));

        i = at(&v10, 0);
        iterator const i1 = at(&v10, 1);
        iterator const i9 = at(&v10, 9);
        TEST((compare(i, i1) < 0));
        increment(&i, 1);
        TEST((compare(i, i1) == 0));
        increment(&i, 8);
        TEST((compare(i, i9) == 0));


        destroy(&v0);
        destroy(&v1);
        destroy(&v10);
    }

    // Tests des fonctions 'push_back' et 'pop_back'.
    {
        vector v = make_vector(sizeof(int), 0, growth_factor_doubling);

        int const n22 = 22;
        push_back(&v, &n22);
        TEST((size(v) == 1));
        TEST((capacity(v) == 1));

        int r = *(int*)pop_back(&v);
        TEST((r == n22));
        TEST((size(v) == 0));
        TEST((capacity(v) == 1));


        int const n33 = 33, n0 = 0;
        push_back(&v, &n33);
        push_back(&v, &n0);
        push_back(&v, &n0);
        push_back(&v, &n0);
        push_back(&v, &n0);
        TEST((size(v) == 5));
        TEST((capacity(v) == 8));

        pop_back(&v);
        pop_back(&v);
        pop_back(&v);
        pop_back(&v);
        r = *(int*)pop_back(&v);
        TEST((r == n33));
        TEST((size(v) == 0));
        TEST((capacity(v) == 8));

        destroy(&v);
    }

    // Tests des fonctions 'insert', 'erase' et 'value'.
    {
        vector v = make_vector(sizeof(int), 0, growth_factor_doubling);

        // À la fin de cette boucle, le vecteur sera [0, 1, 2, 3, 4].
        for(int n = 4; n >= 0; --n)
        {
            insert(&v, begin(&v), &n);
            TEST((size(v) == 5 - n));
        }

        // Teste que les valeurs sont les bonnes.
        for(int n = 0; n != 5; ++n)
        {
            TEST((*(int*)value(at(&v, n)) == n));
        }

        // Efface une à une les valeurs en commencant du début.
        for(int n = 0; n != 5; ++n)
        {
            TEST((*(int*)value(begin(&v)) == n));
            erase(&v, begin(&v));
            TEST((size(v) == 4 - n));
        }

        // À la fin de cette boucle, le vecteur sera [0, 1, 2, 3, 4].
        for(int n = 0; n != 5; ++n)
        {
            insert(&v, end(&v), &n);
        }
        TEST((size(v) == 5));

        // Efface aléatoirement certains éléments.
        erase(&v, at(&v, 2));   // Il nous reste : [0, 1, 3, 4]
        TEST((*(int*)value(at(&v, 2)) == 3));
        TEST((size(v) == 4));

        erase(&v, at(&v, 0));   // Il nous reste : [1, 3, 4]
        TEST(*(int*)value(begin(&v)) == 1);
        TEST((size(v) == 3));

        erase(&v, at(&v, 0));   // Il nous reste : [3, 4]
        TEST(*(int*)value(at(&v, 1)) == 4);
        TEST((size(v) == 2));

        destroy(&v);
    }

    // Tests des fonctions 'assign', 'clear' et 'swap'.
    {
        vector v = make_vector(sizeof(int), 0, growth_factor_doubling);

        // À la fin de cette boucle, le vecteur sera [0, 1, 2, 3, 4].
        for(int n = 4; n >= 0; --n)
        {
            insert(&v, begin(&v), &n);
        }

        // Crée 'v_copie' et y affecte l'entièreté de 'v'.
        vector v_copie = make_vector(sizeof(int), 0, growth_factor_doubling);
        assign(&v_copie, begin(&v), end(&v));

        // Teste que les valeurs sont les bonnes.
        TEST((size(v_copie) == 5));
        for(int n = 0; n != 5; ++n)
        {
            TEST((*(int*)value(at(&v_copie, n)) == n));
        }

        // Après 'clear', la taille est de zéro mais la capacité reste inchangée.
        size_t const old_capacity = capacity(v);
        clear(&v);  // v = []
        TEST((size(v) == 0));
        TEST((capacity(v) == old_capacity));
        TEST((compare(begin(&v), end(&v)) == 0));

        // Échange les deux vecteurs.
        swap(&v, &v_copie);     // v = [0, 1, 2, 3, 4], v_copie = []
        TEST((size(v) == 5));
        TEST((size(v_copie) == 0));

        // Affecte les deux dernières valeurs de 'v' à 'v_copie'.
        iterator i = end(&v);
        decrement(&i, 2);
        assign(&v_copie, i, end(&v));
        TEST((size(v_copie) == 2));
        TEST((*(int*)value(at(&v_copie, 0)) == 3));
        TEST((*(int*)value(at(&v_copie, 1)) == 4));
        // Et 'v' reste inchangé.
        TEST((size(v) == 5));
        TEST((*(int*)value(at(&v, 0)) == 0));
        TEST((*(int*)value(at(&v, 1)) == 1));

        // 'swap' sur un même vecteur ne doit avoir aucun effet.
        swap(&v_copie, &v_copie);
        TEST((size(v_copie) == 2));
        TEST((*(int*)value(at(&v_copie, 0)) == 3));
        TEST((*(int*)value(at(&v_copie, 1)) == 4));

        destroy(&v);
        destroy(&v_copie);
    }

    // Tests des fonctions 'resize', 'reserve' et 'shrink_to_fit'.
    {

    }

    print_summary();

    return tests_total - tests_successful;
}
