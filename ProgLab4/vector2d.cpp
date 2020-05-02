#include <iostream>
#include "point.h"
#include "vector2d.h"


[[nodiscard]] Point Vector2D::center() const
{
    return {(X.x + Y.x) / 2.0, (X.y + Y.y) / 2.0};
}


[[nodiscard]] double Vector2D::length() const
{
    return X.distance_to_point(Y);
}


void Vector2D::print() const
{
    std::cout << "First point coordinates:";
    X.print();
    std::cout << "Second point coordinates:";
    Y.print();
}