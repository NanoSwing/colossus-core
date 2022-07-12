#include "core/da.h"

#include "core/defs.h"
#include "core/utils.h"
#include "core/logger.h"

#include <malloc.h>
#include <string.h>

static const I32 INITIAL_DA_CAPACITY = 8;

typedef struct {
    U64 capacity;
    I64 count;
    U64 size;
} DAheader;
#define get_head(da) (DAheader *) (da - sizeof(DAheader));

void *da_create(U64 size)
{
    DAheader *head = malloc(sizeof(DAheader) + size * INITIAL_DA_CAPACITY);

    head->capacity = INITIAL_DA_CAPACITY;
    head->count = 0;
    head->size = size;

    return (((void *) head) + sizeof(DAheader));
}

void _da_destroy(void **da)
{
    DAheader *head = get_head(*da);

    free(head);

    *da = NULL;
}

void *_da_push_at(void **da, I32 index, void *data)
{
    DAheader *head = get_head(*da);
    // Resize the array when full
    if (head->count == (I64) head->capacity) {
        head->capacity *= 2;
        head = realloc(head, head->capacity * head->size + sizeof(DAheader));
        *da = ((void *) head) + sizeof(DAheader);
    }

    index = clamp(index, 0, head->count);

    // Move everything forward one slot
    memcpy(*da + (index + 1) * head->size, *da + index * head->size, head->count - index);
    // Place data into the desired index
    memcpy(*da + index * head->size, data, head->size);

    head->count++;

    return (*da + index * head->size);
}

void _da_pop_at(void **da, I32 index, void *output)
{
    DAheader *head = get_head(*da);

    if (head->count == 0) {
        log_warn("Can't pop from an empty array.");
        return;
    }

    // Resize the array if neccessary
    if (head->count == (I64) head->capacity / 2 && head->capacity != 8) {
        head->capacity /= 2;
        head = realloc(head, head->capacity * head->size + sizeof(DAheader));
        *da = ((void *) head) + sizeof(DAheader);
    }
    
    index = clamp(index, 0, head->count);

    // Put the popped item in output if available
    if (output != NULL) {
        memcpy(output, *da + index * head->size, head->size);
    }

    memcpy(*da + index * head->size, *da + (index + 1) * head->size, (head->count - index) * head->size);

    head->count--;
}

I64 da_count(const void *da)
{
    DAheader *head = get_head(da);

    return head->count;
}
