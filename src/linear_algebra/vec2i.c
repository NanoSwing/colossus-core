#include "core/linear_algebra.h"

#include <math.h>

Vec2i vec2i(I32 x, I32 y) { return (Vec2i) {x, y}; }
Vec2i vec2is(I32 scaler)  { return (Vec2i) {scaler, scaler}; }

Vec2i vec2i_add(Vec2i a, Vec2i b) { return (Vec2i) {a.x + b.x, a.y + b.y}; }
Vec2i vec2i_sub(Vec2i a, Vec2i b) { return (Vec2i) {a.x - b.x, a.y - b.y}; }
Vec2i vec2i_mul(Vec2i a, Vec2i b) { return (Vec2i) {a.x * b.x, a.y * b.y}; }
Vec2i vec2i_div(Vec2i a, Vec2i b) { return (Vec2i) {a.x / b.x, a.y / b.y}; }

Vec2i vec2i_adds(Vec2i a, I32 scaler) { return (Vec2i) {a.x + scaler, a.y + scaler}; }
Vec2i vec2i_subs(Vec2i a, I32 scaler) { return (Vec2i) {a.x - scaler, a.y - scaler}; }
Vec2i vec2i_muls(Vec2i a, I32 scaler) { return (Vec2i) {a.x * scaler, a.y * scaler}; }
Vec2i vec2i_divs(Vec2i a, I32 scaler) { return (Vec2i) {a.x / scaler, a.y / scaler}; }

F32 vec2i_magnitude(Vec2i a)   { return sqrtf(a.x*a.x + a.y*a.y); }
Vec2i vec2i_normalize(Vec2i a) { return vec2i_divs(a, vec2i_magnitude(a)); }

F32 vec2i_dot(Vec2i a, Vec2i b) { return a.x*b.x + a.y*b.y;  }
