#pragma once

#include "core/defs.h"

/*
 * Linearly interpolate between two values.
 *
 * Args:
 * a - Starting value.
 * b - Target value.
 * t - Time.
 * 
 * Returns:
 * The value between a and b according to t.
 */
extern F32 lerp(F32 a, F32 b, F32 t);
/*
 * Fix a value between a min and a max value.
 *
 * Args:
 * value - Value to clamp.
 * min - Minimum value.
 * max - Maximum value.
 * 
 * Returns:
 * The clamped value.
 */
extern F32 clamp(F32 value, F32 min, F32 max);

/*
 * Function pointer to a compare function.
 * Compare two objects of an undefined type.
 * Used when searching to tell algorithm what object has the greatest value.
 */
typedef I32 (*bs_comp_func)(const void *_a, const void *_b);
/*
 * Search through a sorted array.
 *
 * Args:
 * arr - Array.
 * key - Object to find.
 * count - Object count in array.
 * comp_func - Compare function to know what object has greater value.
 * 
 * Returns:
 * The index of the key if found.
 * -1 if key not found.
 */
extern I32 binary_search(const void *arr, const void *key, I32 count, U64 size, bs_comp_func comp_func);

/*
 * Pre-defined compare function for integers.
 * 
 * Args:
 * _a - First object.
 * _b - Second object.
 * 
 * Returns:
 * 1 when a is greater than b.
 * 0 when they're the same.
 * -1 when b is greater than a.
 */
extern I32 comp_int(const void *_a, const void *_b);
/*
 * Pre-defined compare function for strings.
 *
 * Args:
 * _a - First object.
 * _b - Second object.
 * 
 * Returns:
 * More than 0 when a comes before b in an alphabetical order.
 * 0 when a and b are the same.
 * Less than 0 when a comes after b in an alphabetical order.
 */
extern I32 comp_str(const void *_a, const void *_b);

/*
 * Convert degrees to radians.
 *
 * Args:
 * degrees - Degrees.
 * 
 * Returns:
 * Degrees converted to radians.
 */
extern F32 rad(F32 degrees);
/*
 * Convert radians to degrees.
 *
 * Args:
 * radians - Radians.
 * 
 * Returns:
 * Radians converted to degrees.
 */
extern F32 deg(F32 radians);

/*
 * Get the time with a high resolution clock.
 *
 * Returns:
 * Time since a unspecified time.
 */
extern F64 get_time(void);
