#include "vector_api.h"

#include "vector_types.h"

#include <stdlib.h>

vector make_vector(size_t const element_size, size_t const num_elements, float const growth_factor)
{
    return (vector){
            .element_size = element_size, 
            .data = NULL
            };
}

void destroy(vector* v)
{}

size_t capacity(vector const v)
{
    return 0;
}

size_t size(vector const v)
{
    return 0;
}

void reserve(vector* v, size_t const num_elements)
{}

void resize(vector* v, size_t const num_elements)
{}

void shrink_to_fit(vector* v)
{}

void push_back(vector* v, void const* data)
{}

void* pop_back(vector* v)
{
    return NULL;
}

void assign(vector* v, iterator first, iterator last)
{}

void swap(vector* a, vector* b)
{}

void clear(vector* v)
{}

iterator begin(vector const* v)
{
    return (iterator){
            .element = NULL
            };
}

iterator end(vector const* v)
{
    return (iterator){
            .element = NULL
            };
}

iterator at(vector const* v, size_t const index)
{
    return (iterator){
            .element = NULL
            };
}

void* value(iterator const i)
{
    return NULL;
}

void set(iterator i, void const* data)
{}

void insert(vector* v, iterator const i, void const* data)
{}

void erase(vector* v, iterator const i)
{}


int compare(iterator const a, iterator const b)
{
    return 0;
}

void increment(iterator* i, size_t const num_elements)
{}

void decrement(iterator* i, size_t const num_elements)
{}
