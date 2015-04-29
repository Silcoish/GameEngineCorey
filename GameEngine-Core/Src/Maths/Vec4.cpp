#include "Vec4.h";

namespace Silcoish
{
    namespace Maths
    {
        Vec4::Vec4(const float& xx, const float& yy, const float& zz, const float& ww)
        {
            x = xx;
            y = yy;
            z = zz;
            w = ww;
        }

        Vec4 Vec4::Add(const Vec4& vector)
        {
            x += vector.x;
            y += vector.y;
            z += vector.z;
            w += vector.w;

            return *this;
        }

        Vec4 Vec4::Subtract(const Vec4& vector)
        {
            x -= vector.x;
            y -= vector.y;
            z -= vector.z;
            w -= vector.w;

            return *this;
        }

        Vec4 Vec4::Multiply(const Vec4& vector)
        {
            x *= vector.x;
            y *= vector.y;
            z *= vector.z;
            w *= vector.w;

            return *this;
        }

        Vec4 Vec4::Divide(const Vec4& vector)
        {
            x /= vector.x;
            y /= vector.y;
            z /= vector.z;
            w /= vector.w;

            return *this;
        }

        Vec4& operator+(Vec4 left, const Vec4& right)
        {
            return left.Add(right);
        }

        Vec4& operator-(Vec4 left, const Vec4& right)
        {
            return left.Subtract(right);
        }

        Vec4& operator*(Vec4 left, const Vec4& right)
        {
            return left.Multiply(right);
        }

        Vec4& operator/(Vec4 left, const Vec4& right)
        {
            return left.Divide(right);
        }

        Vec4& Vec4::operator+=(const Vec4& vector)
        {
            return Add(vector);
        }

        Vec4& Vec4::operator-=(const Vec4& vector)
        {
            return Subtract(vector);
        }

        Vec4& Vec4::operator*=(const Vec4& vector)
        {
            return Multiply(vector);
        }

        Vec4& Vec4::operator/=(const Vec4& vector)
        {
            return Divide(vector);
        }

        bool Vec4::operator==(const Vec4& vector)
        {
            return x == vector.x && y == vector.y && z == vector.z && w == vector.w;
        }

        bool Vec4::operator!=(const Vec4& vector)
        {
            return x != vector.x || y != vector.y || z != vector.z || w != vector.w;
        }

        std::ostream& operator<<(std::ostream& stream, const Vec4& vector)
        {
            stream << "[" << vector.x << "," << vector.y << "," << vector.z << "," << vector.w << "]";
            return stream;
        }

    }
}