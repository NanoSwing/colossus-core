#pragma once

#include "core/defs.h"

/*
 * Create a dynamic array.
 *
 * Args:
 * size - Size of the data type of the dynamic array.
 * 
 * Returns:
 * The created dynamic array.
 */
extern void *da_create(U64 size);
extern void _da_destroy(void **da);
extern void *_da_push_at(void **da, I32 index, void *data);
extern void _da_pop_at(void **da, I32 index, void *output);
/*
 * Get the amount of items stored in a dynamic array.
 *
 * Args:
 * da - Dynamic array.
 * 
 * Returns:
 * The amount of items stored.
 */
extern I64 da_count(const void *da);

/*
 * Frees all allocated memory dedicated to the dynamic array and sets the dynamic array pointer to null.
 *
 * Args:
 * da - Dynamic array.
 */
#define da_destroy(da) _da_destroy((void **) &da)

/*
 * Inserts data at the specified index in the dynamic array.
 *
 * Args:
 * da - Dynamic array.
 * index - Index.
 * data - The data to be inserted.
 * 
 * Returns:
 * The pushed item.
 */
#define da_push_at(da, index, data) ({\
        void *__da_output; \
        __typeof(data) __da_temp_data = data; \
        __da_output = _da_push_at((void **) &da, index, &__da_temp_data);\
        __da_output; \
    })
/*
 * Inserts data at the end of the dynamic array.
 *
 * Args:
 * da - Dynamic array.
 * data - Data to be inserted.
 * 
 * Returns:
 * The pushed item. 
 */
#define da_push(da, data) da_push_at(da, da_count(da), data)

/*
 * Pops an object at the specified index in the dynamic array.
 *
 * Args:
 * da - Dynamic array.
 * index - Index.
 * output - Copies the data at the index to this argument if not NULL.
 */
#define da_pop_at(da, index, output) _da_pop_at((void **) &da, index, output);
/*
 * Pops an object from the end of the dynamic array.
 *
 * Args:
 * da - Dynamic array.
 * output - Copies the data at the index to this argument if not NULL.
 */
#define da_pop(da, output) _da_pop_at((void **) &da, daCount(da) - 1, output);
