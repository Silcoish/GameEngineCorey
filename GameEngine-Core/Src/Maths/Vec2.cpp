#include "Vec2.h";

namespace Silcoish
{
    namespace Maths
    {
        Vec2::Vec2()
        {
            x = 0.0f;
            y = 0.0f;
        }

        Vec2::Vec2(const float& xx, const float& yy)
        {
            x = xx;
            y = yy;
        }

        Vec2 Vec2::Add(const Vec2& vector)
        {
            x += vector.x;
            y += vector.y;

            return *this;
        }

        Vec2 Vec2::Subtract(const Vec2& vector)
        {
            x -= vector.x;
            y -= vector.y;

            return *this;
        }

        Vec2 Vec2::Multiply(const Vec2& vector)
        {
            x *= vector.x;
            y *= vector.y;

            return *this;
        }

        Vec2 Vec2::Divide(const Vec2& vector)
        {
            x /= vector.x;
            y /= vector.y;

            return *this;
        }

        Vec2& operator+(Vec2 left, const Vec2& right)
        {
            return left.Add(right);
        }

        Vec2& operator-(Vec2 left, const Vec2& right)
        {
            return left.Subtract(right);
        }

        Vec2& operator*(Vec2 left, const Vec2& right)
        {
            return left.Multiply(right);
        }

        Vec2& operator/(Vec2 left, const Vec2& right)
        {
            return left.Divide(right);
        }

        Vec2& Vec2::operator+=(const Vec2& vector)
        {
            return Add(vector);
        }

        Vec2& Vec2::operator-=(const Vec2& vector)
        {
            return Subtract(vector);
        }

        Vec2& Vec2::operator*=(const Vec2& vector)
        {
            return Multiply(vector);
        }

        Vec2& Vec2::operator/=(const Vec2& vector)
        {
            return Divide(vector);
        }

        bool Vec2::operator==(const Vec2& vector)
        {
            return x == vector.x && y == vector.y;
        }

        bool Vec2::operator!=(const Vec2& vector)
        {
            return x != vector.x || y != vector.y;
        }

        std::ostream& operator<<(std::ostream& stream, const Vec2& vector)
        {
            stream << "[" << vector.x << "," << vector.y << "]";
            return stream;
        }

    }
}