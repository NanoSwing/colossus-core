#include "core/linear_algebra.h"

#include <string.h>

Mat4f mat4f(Vec4f a, Vec4f b, Vec4f c, Vec4f d) { return (Mat4f) {a, b, c, d}; }
Mat4f mat4f_ortho_projection(F32 left, F32 right, F32 top, F32 bottom, F32 near, F32 far)
{
    // Stolen from: http://learnwebgl.brown37.net/08_projections/projections_ortho.html
    Mat4f proj = mat4f_identity;

    F32 mid_x = (left + right) * 0.5f;
    F32 mid_y = (bottom + top) * 0.5f;
    F32 mid_z = (-near + -far) * 0.5f;
    proj.a.w = -mid_x;
    proj.b.w = -mid_y;
    proj.c.w = -mid_z;

    F32 scale_x = 2.0f / (right - left);
    F32 scale_y = 2.0f / (top - bottom);
    F32 scale_z = 2.0f / (far - near);
    proj.a.x = scale_x;
    proj.b.y = scale_y;
    proj.c.z = scale_z;

    return proj;
}
void mat4f_to_floats(Mat4f mat, F32 floats[4][4]) { memcpy(floats, &mat, sizeof(Mat4f)); }
void mat4f_from_floats(Mat4f *mat, F32 floats[4][4]) { memcpy(mat, floats, sizeof(Mat4f)); }
Mat4f mat4_inverse(Mat4f mat)
{
    // https://semath.info/src/inverse-cofactor-ex4.html

    // Create 3x3 matrix from an origin
    F32 m_f[4][4][3][3] = {0};
    F32 a_f[4][4];
    mat4f_to_floats(mat, a_f);
    const Vec2i start_origin = vec2i(2, 2);
    Vec2i origin = start_origin;

    for (I32 i = 0; i < 4; i++) {
        for (I32 j = 0; j < 4; j++) {
            origin.x = (I32) (start_origin.x + i) % 4;
            origin.y = (I32) (start_origin.y + j) % 4;
            for (I32 y = -1; y < 2; y++) {
                for (I32 x = -1; x < 2; x++) {
                    m_f[i][j][x + 1][y + 1] = a_f[(origin.x + x + 4) % 4][(origin.y + y + 4) % 4];
                }
            }
        }
    }

    F32 adj[4][4];
    for (I32 y = 0; y < 4; y++) {
        for (I32 x = 0; x < 4; x++) {
            Mat3f m;
            mat3f_from_floats(&m, m_f[x][y]);
            adj[x][y] = mat3f_determinant(m);
        }
    }

    F32 det = 0;
    det += mat.a.x * adj[0][0];
    det -= mat.b.x * adj[0][1];
    det += mat.c.x * adj[0][2];
    det -= mat.d.x * adj[0][3];

    I32 counter = 0;
    B8 neg = false;
    for (I32 y = 0; y < 4; y++) {
        for (I32 x = 0; x < 4; x++) {
            if (counter == 4) {
                counter = 0;
                neg = !neg;
            }
            if (neg) {
                adj[x][y] = -adj[x][y];
            }
            neg = !neg;
            counter++;
        }
    }

    for (I32 y = 0; y < 4; y++) {
        for (I32 x = 0; x < 4; x++) {
            adj[x][y] /= det;
        }
    }

    Mat4f ret;
    mat4f_from_floats(&ret, adj);
    return ret;
}