#include "core/linear_algebra.h"

#include <math.h>

Vec4f vec4f(F32 x, F32 y, F32 z, F32 w) { return (Vec4f) {x, y, z, w}; }
Vec4f vec4fs(F32 scaler)                { return (Vec4f) {scaler, scaler, scaler, scaler}; }

Vec4f vec4f_add(Vec4f a, Vec4f b) { return (Vec4f) {a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w}; }
Vec4f vec4f_sub(Vec4f a, Vec4f b) { return (Vec4f) {a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w}; }
Vec4f vec4f_mul(Vec4f a, Vec4f b) { return (Vec4f) {a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w}; }
Vec4f vec4f_div(Vec4f a, Vec4f b) { return (Vec4f) {a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w}; }

Vec4f vec4f_adds(Vec4f a, F32 scaler) { return (Vec4f) {a.x + scaler, a.y + scaler, a.z + scaler, a.w + scaler}; }
Vec4f vec4f_subs(Vec4f a, F32 scaler) { return (Vec4f) {a.x - scaler, a.y - scaler, a.z - scaler, a.w - scaler}; }
Vec4f vec4f_muls(Vec4f a, F32 scaler) { return (Vec4f) {a.x * scaler, a.y * scaler, a.z * scaler, a.w * scaler}; }
Vec4f vec4f_divs(Vec4f a, F32 scaler) { return (Vec4f) {a.x / scaler, a.y / scaler, a.z / scaler, a.w / scaler}; }

F32 vec4f_magnitude(Vec4f a) { return sqrt(a.x*a.x + a.y*a.y + a.z*a.z + a.w*a.w); }
Vec4f vec4f_normalize(Vec4f a) { return vec4f_divs(a, vec4f_magnitude(a)); }
