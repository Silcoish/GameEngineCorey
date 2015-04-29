#pragma once
#include <iostream>

namespace Silcoish
{
    namespace Maths
    {
        struct Vec3
        {
            float x, y, z;

            Vec3();
            Vec3(const float& xx, const float& yy, const float& zz);

            Vec3 Add(const Vec3& vector);
            Vec3 Subtract(const Vec3& vector);
            Vec3 Multiply(const Vec3& vector);
            Vec3 Divide(const Vec3& vector);

            friend Vec3& operator+(Vec3 left, const Vec3& right);
            friend Vec3& operator-(Vec3 left, const Vec3& right);
            friend Vec3& operator*(Vec3 left, const Vec3& right);
            friend Vec3& operator/(Vec3 left, const Vec3& right);

            Vec3& operator+=(const Vec3& vector);
            Vec3& operator-=(const Vec3& vector);
            Vec3& operator*=(const Vec3& vector);
            Vec3& operator/=(const Vec3& vector);

            bool operator==(const Vec3& vector);
            bool operator!=(const Vec3& vector);

            friend std::ostream& operator<<(std::ostream& stream, const Vec3& vector);

        };

    }
}