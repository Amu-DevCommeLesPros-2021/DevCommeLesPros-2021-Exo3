#pragma once

#include "vector.h"

#include <stdlib.h>

vector make_vector(size_t const element_size, size_t const num_elements, float const growth_factor)
{
    return (vector){.element_size = element_size, .data = NULL};
}

void destroy(vector v)
{}

size_t capacity(vector const v)
{
    return 0;
}

size_t size(vector const v)
{
    return 0;
}

iterator at(vector const v, size_t index)
{
    return (iterator){.data = NULL, .owner = NULL};
}

void reserve(vector v, size_t const num_elements)
{}

void resize(vector v, size_t const num_elements)
{}

void shrink_to_fit(vector v)
{}

void assign(vector v, iterator first, iterator last)
{}

void push_back(vector v, void* data)
{}

void* pop_back(vector v)
{
    return NULL;
}

void insert(vector v, iterator const i, void* data)
{}

void erase(vector v, iterator const i)
{}

void swap(vector a, vector b)
{}

void clear(vector v)
{}

iterator begin(vector v)
{
    return (iterator){.data = NULL, .owner = NULL};
}

iterator end(vector v)
{
    return (iterator){.data = NULL, .owner = NULL};
}

void increment(iterator i, size_t const num_elements)
{}

void decrement(iterator i, size_t const num_elements)
{}
