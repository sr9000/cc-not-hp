// CASEY MURATORI

#include "common.h"

#include <cmath>

enum shape_type : u32 {
    Shape_Square,
    Shape_Rectangle,
    Shape_Right_Triangle,
    Shape_Circle,

    Shape_Count,
};

struct shape_struct {
    shape_type Type;
    f32 Width;
    f32 Height;
};

f32 const CTable[Shape_Count] = { 1.0f, 1.0f, 0.5f, M_PI };
f32 GetAreaStructs(u32 ShapeCount, shape_struct* Shapes)
{
    f32 Accum = 0.0f;
    for (u32 ShapeIndex = 0; ShapeIndex < ShapeCount; ++ShapeIndex) {
        auto&& shape = Shapes[ShapeIndex];
        Accum += CTable[shape.Type] * shape.Width * shape.Height;
    }

    return Accum;
}