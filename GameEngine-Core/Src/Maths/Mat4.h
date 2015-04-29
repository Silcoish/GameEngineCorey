#pragma once

#include "Vec3.h";
#include "Vec4.h";
#include "MathFunctions.h";

//Column Major
namespace Silcoish
{
    namespace Maths
    {
        struct Mat4
        {
            union
            {
                float elements[4 * 4];
                Vec4 columns[4];
            };

            Mat4();
            Mat4(float diagonal);

            static Mat4 identity();
            Mat4& multiply(const Mat4& other);

            static Mat4 orthographic(float left, float right, float bottom, float top, float near, float far);
            static Mat4 perspective(float fov, float aspectRation, float near, float far);

            static Mat4 translation(const Vec3& translation);
            static Mat4 rotation(float angle, const Vec3& axis);
            static Mat4 scale(const Vec3& scale);

            friend Mat4 operator*(Mat4 left, const Mat4& right);
            Mat4& operator*=(const Mat4& other);

        };
    }
}