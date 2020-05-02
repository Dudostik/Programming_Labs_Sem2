#ifndef UNTITLED2_VECTOR2D_H
#define UNTITLED2_VECTOR2D_H

class Vector2D
{
public:
    Point X, Y;
    [[nodiscard]] Point center() const;
    [[nodiscard]] double length() const;
    void print() const;
};

#endif //UNTITLED2_VECTOR2D_H
