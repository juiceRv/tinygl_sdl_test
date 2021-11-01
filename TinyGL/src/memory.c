/*
 * Memory allocator for TinyGL
 */
#include "zgl.h"

/* modify these functions so that they suit your needs */

void gl_free(void *p)
{
    free(p);
    // extern void juicevm_free(void* p);
    // juicevm_free(p);
}

void *gl_malloc(int size)
{
    return malloc(size);
    // extern void* juicevm_malloc(size_t bytes);
    // return juicevm_malloc(size);
}

void *gl_zalloc(int size)
{
    return calloc(1, size);
    // extern void* juicevm_calloc(size_t nelem, size_t elem_size);
    // return juicevm_calloc(1, size);
}
