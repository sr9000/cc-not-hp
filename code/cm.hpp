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
f32 GetAreaStructs4(u32 ShapeCount, shape_struct* Shapes)
{
    f32 Accum1 = 0.0f;
    f32 Accum2 = 0.0f;
    f32 Accum3 = 0.0f;
    f32 Accum4 = 0.0f;
    for (u32 ShapeIndex = 0; ShapeIndex < ShapeCount; ShapeIndex += 4) {
        auto&& shape1 = Shapes[ShapeIndex + 0];
        auto&& shape2 = Shapes[ShapeIndex + 1];
        auto&& shape3 = Shapes[ShapeIndex + 2];
        auto&& shape4 = Shapes[ShapeIndex + 3];
        Accum1 += CTable[shape1.Type] * shape1.Width * shape1.Height;
        Accum2 += CTable[shape2.Type] * shape2.Width * shape2.Height;
        Accum3 += CTable[shape3.Type] * shape3.Width * shape3.Height;
        Accum4 += CTable[shape4.Type] * shape4.Width * shape4.Height;
    }

    return Accum1 + Accum2 + Accum3 + Accum4;
}