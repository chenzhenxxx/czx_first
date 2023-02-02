//C++运算符及其重载
#include <iostream>
#include <string>

struct Vector2
{
    float x, y;

    Vector2(float x, float y)
         : x(x),y(y) {}

    Vector2 Add(const Vector2& other) const
    {
        return Vector2(x + other.x,y + other.y);
    }
    Vector2 Multiply(const Vector2& other) const
    {
        return Vector2(x * other.x,y * other.y);
    }

    Vector2 operator+(const Vector2& other) const
    {
        return Add(other);
    }
    Vector2 operator*(const Vector2& other) const
    {
        return Multiply(other);
    }
    bool operator==(const Vector2& other) const
    {
        return x == other.x && y == other.y;
    }
    bool operator!=(const Vector2& other) const
    {
        return !operator==(other);
    }

};
std::ostream& operator<<(std::ostream& stream, const Vector2& other)
    {
        stream << other.x << "," <<other.y;
        return stream;
    }