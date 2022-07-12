#include "core/linear_algebra.h"

#include <string.h>

F32 mat3f_determinant(Mat3f mat) { return mat.a.x*mat.b.y*mat.c.z + mat.b.x*mat.c.y*mat.a.z + mat.c.x*mat.a.y*mat.b.z - mat.c.x*mat.b.y*mat.a.z - mat.b.x*mat.a.y*mat.c.z - mat.a.x*mat.c.y*mat.b.z; }

extern void mat3f_from_floats(Mat3f *mat, F32 floats[3][3])
{
    memcpy(mat, floats, sizeof(Mat3f));
}
extern void mat3f_to_floats(Mat3f mat, F32 floats[3][3])
{
    memcpy(floats, &mat, sizeof(Mat3f));
}
