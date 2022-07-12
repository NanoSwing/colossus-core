#pragma once

#include "core/defs.h"

/*
 * Vector 2D floating point.
 */
typedef struct {
    F32 x;
    F32 y;
} Vec2f;

extern Vec2f vec2f(F32 x, F32 y);
extern Vec2f vec2fs(F32 scaler);

extern Vec2f vec2f_add(Vec2f a, Vec2f b);
extern Vec2f vec2f_sub(Vec2f a, Vec2f b);
extern Vec2f vec2f_mul(Vec2f a, Vec2f b);
extern Vec2f vec2f_div(Vec2f a, Vec2f b);

extern Vec2f vec2f_adds(Vec2f a, F32 scaler);
extern Vec2f vec2f_subs(Vec2f a, F32 scaler);
extern Vec2f vec2f_muls(Vec2f a, F32 scaler);
extern Vec2f vec2f_divs(Vec2f a, F32 scaler);

extern F32 vec2f_magnitude(Vec2f a);
extern Vec2f vec2f_normalize(Vec2f a);

extern F32 vec2f_dot(Vec2f a, Vec2f b);

/*
 * Vector 2D integer.
 */
typedef struct {
    I32 x;
    I32 y;
} Vec2i;

extern Vec2i vec2i(I32 x, I32 y);
extern Vec2i vec2is(I32 scaler);

extern Vec2i vec2i_add(Vec2i a, Vec2i b);
extern Vec2i vec2i_sub(Vec2i a, Vec2i b);
extern Vec2i vec2i_mul(Vec2i a, Vec2i b);
extern Vec2i vec2i_div(Vec2i a, Vec2i b);

extern Vec2i vec2i_adds(Vec2i a, I32 scaler);
extern Vec2i vec2i_subs(Vec2i a, I32 scaler);
extern Vec2i vec2i_muls(Vec2i a, I32 scaler);
extern Vec2i vec2i_divs(Vec2i a, I32 scaler);

extern F32 vec2i_magnitude(Vec2i a);
extern Vec2i vec2i_normalize(Vec2i a);

extern F32 vec2i_dot(Vec2i a, Vec2i b);

/*
 * Vector 3D floating point
 */
typedef struct {
    F32 x;
    F32 y;
    F32 z;
} Vec3f;

extern Vec3f vec3f(F32 x, F32 y, F32 z);
extern Vec3f vec3fs(F32 scaler);

extern Vec3f vec3f_add(Vec3f a, Vec3f b);
extern Vec3f vec3f_sub(Vec3f a, Vec3f b);
extern Vec3f vec3f_mul(Vec3f a, Vec3f b);
extern Vec3f vec3f_div(Vec3f a, Vec3f b);

extern Vec3f vec3f_adds(Vec3f a, F32 scaler);
extern Vec3f vec3f_subs(Vec3f a, F32 scaler);
extern Vec3f vec3f_muls(Vec3f a, F32 scaler);
extern Vec3f vec3f_divs(Vec3f a, F32 scaler);

extern F32 vec3f_magnitude(Vec3f a);
extern Vec3f vec3f_normalize(Vec3f a);

/*
 * Vector 4D floating point
 */
typedef struct {
    F32 x;
    F32 y;
    F32 z;
    F32 w;
} Vec4f;

extern Vec4f vec4f(F32 x, F32 y, F32 z, F32 w);
extern Vec4f vec4fs(F32 scaler);

extern Vec4f vec4f_add(Vec4f a, Vec4f b);
extern Vec4f vec4f_sub(Vec4f a, Vec4f b);
extern Vec4f vec4f_mul(Vec4f a, Vec4f b);
extern Vec4f vec4f_div(Vec4f a, Vec4f b);

extern Vec4f vec4f_adds(Vec4f a, F32 scaler);
extern Vec4f vec4f_subs(Vec4f a, F32 scaler);
extern Vec4f vec4f_muls(Vec4f a, F32 scaler);
extern Vec4f vec4f_divs(Vec4f a, F32 scaler);

extern F32 vec4f_magnitude(Vec4f a);
extern Vec4f vec4f_normalize(Vec4f a);

/*
 * 3x3 matrix floating point
 */
typedef struct {
    Vec3f a;
    Vec3f b;
    Vec3f c;
} Mat3f;

extern F32 mat3f_determinant(Mat3f mat);

extern void mat3f_from_floats(Mat3f *mat, F32 floats[3][3]);
extern void mat3f_to_floats(Mat3f mat, F32 floats[3][3]);

/*
 * 4x4 matrix floating point
 */
typedef struct {
    Vec4f a;
    Vec4f b;
    Vec4f c;
    Vec4f d;
} Mat4f;

#define mat4f_identity mat4f(vec4f(1, 0, 0, 0), vec4f(0, 1, 0, 0), vec4f(0, 0, 1, 0), vec4f(0, 0, 0, 1))

extern Mat4f mat4f(Vec4f a, Vec4f b, Vec4f c, Vec4f d);
extern Mat4f mat4f_ortho_projection(F32 left, F32 right, F32 top, F32 bottom, F32 near, F32 far);
extern void mat4f_to_floats(Mat4f mat, F32 floats[4][4]);
extern void mat4f_from_floats(Mat4f *mat, F32 floats[4][4]);
extern Mat4f mat4_inverse(Mat4f mat);
