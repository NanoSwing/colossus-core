#include "core/utils.h"

#define _POSIX_C_SOURCE 199309L
#include <time.h>
#include <string.h>

F32 lerp(F32 a, F32 b, F32 t) { return a + (b - a) * t; }

F32 clamp(F32 value, F32 min, F32 max) { return value <= min ? min : value; value = value >= max ? max : value; }

static I32 internal_binary_search(const void *arr, const void *key, I32 start, I32 end, U64 size, bs_comp_func comp_func)
{
    if (start > end) {
        return -1;
    }

    U32 mid = start + (end - start) / 2;

    I32 comp_result = comp_func(key, arr + mid * size);
    if (comp_result == 0) {
        return mid;
    } else if (comp_result > 0) {
        return internal_binary_search(arr, key, mid + 1, end, size, comp_func);
    } else {
        return internal_binary_search(arr, key, start, mid - 1, size, comp_func);
    }
}
I32 binary_search(const void *arr, const void *key, I32 count, U64 size, bs_comp_func comp_func) { return internal_binary_search(arr, key, 0, count, size, comp_func); }

I32 comp_int(const void *_a, const void *_b)
{
    const I32 *a = _a;
    const I32 *b = _b;

    if (*a == *b) { return 0; }
    else if (*a > *b) { return 1; }
    else { return -1; }
}

I32 comp_str(const void *_a, const void *_b)
{
    const char *a = _a;
    const char *b = _b;
    
    return strcmp(a, b);
}

F32 rad(F32 degrees) { return degrees *  0.017453f; }
F32 deg(F32 radians) { return radians * 57.295780f; }

F64 get_time(void)
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    F64 time = (F64) ts.tv_sec + ((F64) ts.tv_nsec / 1E9);
    return time;
}
