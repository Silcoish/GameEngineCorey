#include "Vec3.h";

namespace Silcoish
{
    namespace Maths
    {
        Vec3::Vec3()
        {
            x = 0.0f;
            y = 0.0f;
            z = 0.0f;
        }

        Vec3::Vec3(const float& xx, const float& yy, const float& zz)
        {
            x = xx;
            y = yy;
            z = zz;
        }

        Vec3 Vec3::Add(const Vec3& vector)
        {
            x += vector.x;
            y += vector.y;
            z += vector.z;

            return *this;
        }

        Vec3 Vec3::Subtract(const Vec3& vector)
        {
            x -= vector.x;
            y -= vector.y;
            z -= vector.z;

            return *this;
        }

        Vec3 Vec3::Multiply(const Vec3& vector)
        {
            x *= vector.x;
            y *= vector.y;
            z *= vector.z;

            return *this;
        }

        Vec3 Vec3::Divide(const Vec3& vector)
        {
            x /= vector.x;
            y /= vector.y;
            z /= vector.z;

            return *this;
        }

        Vec3& operator+(Vec3 left, const Vec3& right)
        {
            return left.Add(right);
        }

        Vec3& operator-(Vec3 left, const Vec3& right)
        {
            return left.Subtract(right);
        }

        Vec3& operator*(Vec3 left, const Vec3& right)
        {
            return left.Multiply(right);
        }

        Vec3& operator/(Vec3 left, const Vec3& right)
        {
            return left.Divide(right);
        }

        Vec3& Vec3::operator+=(const Vec3& vector)
        {
            return Add(vector);
        }

        Vec3& Vec3::operator-=(const Vec3& vector)
        {
            return Subtract(vector);
        }

        Vec3& Vec3::operator*=(const Vec3& vector)
        {
            return Multiply(vector);
        }

        Vec3& Vec3::operator/=(const Vec3& vector)
        {
            return Divide(vector);
        }

        bool Vec3::operator==(const Vec3& vector)
        {
            return x == vector.x && y == vector.y && z == vector.z;
        }

        bool Vec3::operator!=(const Vec3& vector)
        {
            return x != vector.x || y != vector.y || z != vector.z;
        }

        std::ostream& operator<<(std::ostream& stream, const Vec3& vector)
        {
            stream << "[" << vector.x << "," << vector.y << "," << vector.z << "]";
            return stream;
        }

    }
}