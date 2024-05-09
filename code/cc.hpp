// CLEAN CODE

#include <cmath>

#include "common.h"

class shape_base {
public:
    shape_base() = default;
    virtual f32 Area() = 0;
};

class square : public shape_base {
public:
    explicit square(f32 SideInit)
        : Side(SideInit)
    {
    }
    f32 Area() override { return Side * Side; }

private:
    f32 Side;
};

class rectangle : public shape_base {
public:
    rectangle(f32 WidthInit, f32 HeightInit)
        : Width(WidthInit)
        , Height(HeightInit)
    {
    }
    f32 Area() override { return Width * Height; }

private:
    f32 Width, Height;
};

class right_triangle : public shape_base {
public:
    right_triangle(f32 BaseInit, f32 HeightInit)
        : Base(BaseInit)
        , Height(HeightInit)
    {
    }
    f32 Area() override { return 0.5f * Base * Height; }

private:
    f32 Base, Height;
};

class circle : public shape_base {
public:
    explicit circle(f32 RadiusInit)
        : Radius(RadiusInit)
    {
    }
    f32 Area() override { return M_PI * Radius * Radius; }

private:
    f32 Radius;
};

f32 TotalAreaVTBL(u32 ShapeCount, shape_base** Shapes)
{
    f32 Accum = 0.0f;
    for (u32 ShapeIndex = 0; ShapeIndex < ShapeCount; ++ShapeIndex) {
        Accum += Shapes[ShapeIndex]->Area();
    }

    return Accum;
}
