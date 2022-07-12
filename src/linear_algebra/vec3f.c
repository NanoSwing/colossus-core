#include "linear_algebra.h"

#include <math.h>

Vec3f vec3f(F32 x, F32 y, F32 z) { return (Vec3f) {x, y, z}; }
Vec3f vec3fs(F32 scaler)         { return (Vec3f) {scaler, scaler, scaler}; }

Vec3f vec3f_add(Vec3f a, Vec3f b) { return (Vec3f) {a.x + b.x, a.y + b.y, a.z + b.z}; }
Vec3f vec3f_sub(Vec3f a, Vec3f b) { return (Vec3f) {a.x - b.x, a.y - b.y, a.z - b.z}; }
Vec3f vec3f_mul(Vec3f a, Vec3f b) { return (Vec3f) {a.x * b.x, a.y * b.y, a.z * b.z}; }
Vec3f vec3f_div(Vec3f a, Vec3f b) { return (Vec3f) {a.x / b.x, a.y / b.y, a.z / b.z}; }

Vec3f vec3f_adds(Vec3f a, F32 scaler) { return (Vec3f) {a.x + scaler, a.y + scaler, a.z + scaler}; }
Vec3f vec3f_subs(Vec3f a, F32 scaler) { return (Vec3f) {a.x - scaler, a.y - scaler, a.z - scaler}; }
Vec3f vec3f_muls(Vec3f a, F32 scaler) { return (Vec3f) {a.x * scaler, a.y * scaler, a.z * scaler}; }
Vec3f vec3f_divs(Vec3f a, F32 scaler) { return (Vec3f) {a.x / scaler, a.y / scaler, a.z / scaler}; }

F32 vec3f_magnitude(Vec3f a) { return sqrt(a.x*a.x + a.y*a.y + a.z*a.z); }
Vec3f vec3f_normalize(Vec3f a) { return vec3f_divs(a, vec3f_magnitude(a)); }
