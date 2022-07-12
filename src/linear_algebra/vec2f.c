#include "core/linear_algebra.h"

#include <math.h>

Vec2f vec2f(F32 x, F32 y) { return (Vec2f) {x, y}; }
Vec2f vec2fs(F32 scaler)  { return (Vec2f) {scaler, scaler}; }

Vec2f vec2f_add(Vec2f a, Vec2f b) { return (Vec2f) {a.x + b.x, a.y + b.y}; }
Vec2f vec2f_sub(Vec2f a, Vec2f b) { return (Vec2f) {a.x - b.x, a.y - b.y}; }
Vec2f vec2f_mul(Vec2f a, Vec2f b) { return (Vec2f) {a.x * b.x, a.y * b.y}; }
Vec2f vec2f_div(Vec2f a, Vec2f b) { return (Vec2f) {a.x / b.x, a.y / b.y}; }

Vec2f vec2f_adds(Vec2f a, F32 scaler) { return (Vec2f) {a.x + scaler, a.y + scaler}; }
Vec2f vec2f_subs(Vec2f a, F32 scaler) { return (Vec2f) {a.x - scaler, a.y - scaler}; }
Vec2f vec2f_muls(Vec2f a, F32 scaler) { return (Vec2f) {a.x * scaler, a.y * scaler}; }
Vec2f vec2f_divs(Vec2f a, F32 scaler) { return (Vec2f) {a.x / scaler, a.y / scaler}; }

F32 vec2f_magnitude(Vec2f a)   { return sqrtf(a.x*a.x + a.y*a.y); }
Vec2f vec2f_normalize(Vec2f a) { return vec2f_divs(a, vec2f_magnitude(a)); }

F32 vec2f_dot(Vec2f a, Vec2f b) { return a.x*b.x + a.y*b.y;  }
