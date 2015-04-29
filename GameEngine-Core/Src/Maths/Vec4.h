#pragma once
#include <iostream>

namespace Silcoish
{
    namespace Maths
    {
        struct Vec4
        {
            float x, y, z, w;

            Vec4() = default;
            Vec4(const float& xx, const float& yy, const float& zz, const float& ww);

            Vec4 Add(const Vec4& vector);
            Vec4 Subtract(const Vec4& vector);
            Vec4 Multiply(const Vec4& vector);
            Vec4 Divide(const Vec4& vector);

            friend Vec4& operator+(Vec4 left, const Vec4& right);
            friend Vec4& operator-(Vec4 left, const Vec4& right);
            friend Vec4& operator*(Vec4 left, const Vec4& right);
            friend Vec4& operator/(Vec4 left, const Vec4& right);

            Vec4& operator+=(const Vec4& vector);
            Vec4& operator-=(const Vec4& vector);
            Vec4& operator*=(const Vec4& vector);
            Vec4& operator/=(const Vec4& vector);

            bool operator==(const Vec4& vector);
            bool operator!=(const Vec4& vector);

            friend std::ostream& operator<<(std::ostream& stream, const Vec4& vector);

        };

    }
}