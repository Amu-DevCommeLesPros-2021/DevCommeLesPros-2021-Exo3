#pragma once

#include <stdlib.h>

// Contient de zéro à N éléments, chacun de taille 'element_size' dans un seul
// bloc de mémoire contigue.
// Au moment de créer un nouveau vecteur, 'element_size' est donné et ne changera 
// pas pour ce vecteur. Bien entendu, d'autres vecteur peuvent être créés avec un 
// 'element_size' différent.
// Le bloc de mémoire contigue pointé par 'data' est toujours d'au moins 'N * element_size'.
// Si, au moment d'ajouter un nouvel élément, le bloc de mémoire alloué est de 
// taille insuffisante le bloc sera redimensionné par un facteur donné ('growth_factor'
// de la fonction 'make_vector').
// Réf. : https://fr.cppreference.com/w/cpp/container/vector
typedef struct vector
{
    size_t const element_size;
    void *data;

    // D'autre membres peuvent être ajoutés, si nécessaire.
} vector;

// Un itérateur est l'abstraction d'un index dans un vecteur.
// Il peut être incrémenté, décrémenté, comparé avec un autre itérateur et 
// servira d'interface avec les fonctions algorithmiques dans le prochain exercice.
// Les fonctions qui utilisent les itérateur prennent typiquement deux itérateurs 
// 'first' et 'last' et l'itérateur 'last' n'est pas inclus. Il fait office de 
// sentinelle. Exprimé mathématiquement : "[first, last[" plutôt que "[first, last]".
typedef struct iterator
{
    void *data;
    vector const* owner;

    // D'autre membres peuvent être ajoutés, si nécessaire.
} iterator;


// Crée un vecteur dont la taille des éléments contenus est de 'element_size'.
// 'num_elements' est le nombre d'éléments pour lequel de la mémoire doit d'ores 
// et déjà être réservée.
// 'growth_factor' est le facteur de croissance par lequel il faut redimensionner 
// le bloc de mémoire quand celui-ci est trop petit. Typiquement 1,5 ou 2,0.
// Renvoie le vecteur nouvellement créé.
vector make_vector(size_t const element_size, size_t const num_elements, float const growth_factor);

// Libère la mémoire utilsée par le vecteur.
void destroy(vector* v);

// Renvoie le nombre courant d'éléments dans un vecteur.
size_t size(vector const* v);

// Renvoie le nombre d'éléments qui peuvent être stocké dans le bloc de mémoire.
// En tout temps, la capacité est égale ou plus grande que le nombre courant
// d'éléments.
size_t capacity(vector const* v);


// Si la capacité est moindre que demandé, redimensionne le bloc de mémoire 
// pour pouvoir contenir *exactement* 'num_elements' éléments. Le nombre courant 
// d'éléments reste inchangé.
// Si la capacité est plus que demandé, n'a aucun effet.
void reserve(vector* v, size_t const num_elements);

// Si le vecteur contient moins d'éléments que demandé, redimensionne le bloc 
// de mémoire pour contenir *exactement* 'num_elements' éléments. Le nombre courant 
// d'éléments reste inchangé.
// Si le vecteur contient plus d'éléments que demandé, seul les 'num_elements' 
// premiers éléments sont préservés et le nombre courant d'éléments devient 'num_elements'.
// La capacité reste inchangé.
void resize(vector* v, size_t const num_elements);

// Si la capacité est plus grande que le nombre d'éléments courant, redimensionne le bloc 
// de mémoire pour contenir *exactement* le nombre d'éléments courant.
void shrink_to_fit(vector* v);


// Remplace le contenu de 'v' par les éléments contenus entre 'first' et 'last'. 
// 'last' n'est pas inclus.
void assign(vector* v, iterator first, iterator last);

// Ajoute un nouvel élément à la fin du vecteur.
void push_back(vector* v, void* data);

// Enlève le dernier élément du vecteur.
// Renvoie la valeur de ce dernier élément.
void* pop_back(vector* v);

// Ajoute un nouvel élément au vecteur immédiatement après l'itérateur donné.
void insert(vector* v, iterator const i, void const* data);

// Enlève l'élément à l'itérateur donné.
void erase(vector* v, iterator const i);

// Échange le contenu de deux vecteurs.
void swap(vector* a, vector* b);


// Vide le vecteur de son contenu mais garde le bloc de mémoire intact en réserve.
void clear(vector* v);


// Renvoie un itérateur qui se trouve au tout début du vecteur.
iterator begin(vector const* v);

// Renvoie un itérateur qui se trouve à un élément au-delà de la fin du vecteur.
iterator end(vector const* v);

// Renvoie un itérateur correspondant à l'élément à 'index donné.
// 
iterator at(vector const* v, size_t const index);

// Si 'a' précède 'b', renvoie un nombre négatif.
// Si 'a' égale 'b', renvoie zéro.
// Si 'a' succède 'b', renvoie un nombre positif.
int compare(iterator const* a, iterator const* b);

// Avance un itérateur de 'num_elements' éléments.
void increment(iterator* i, size_t const num_elements);

// Recule un itérateur de 'num_elements' éléments.
void decrement(iterator* i, size_t const num_elements);
