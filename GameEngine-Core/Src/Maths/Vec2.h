#pragma once
#include <iostream>

namespace Silcoish
{
    namespace Maths
    {
        struct Vec2
        {
            float x, y;

            Vec2();
            Vec2(const float& xx, const float& yy);

            Vec2 Add(const Vec2& vector);
            Vec2 Subtract(const Vec2& vector);
            Vec2 Multiply(const Vec2& vector);
            Vec2 Divide(const Vec2& vector);

            friend Vec2& operator+(Vec2 left, const Vec2& right);
            friend Vec2& operator-(Vec2 left, const Vec2& right);
            friend Vec2& operator*(Vec2 left, const Vec2& right);
            friend Vec2& operator/(Vec2 left, const Vec2& right);

            Vec2& operator+=(const Vec2& vector);
            Vec2& operator-=(const Vec2& vector);
            Vec2& operator*=(const Vec2& vector);
            Vec2& operator/=(const Vec2& vector);

            bool operator==(const Vec2& vector);
            bool operator!=(const Vec2& vector);

            friend std::ostream& operator<<(std::ostream& stream, const Vec2& vector);

        };

    }
}