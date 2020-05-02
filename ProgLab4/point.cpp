#include <iostream>
#include "point.h"

void Point::InitFromDialog()
{
    std::cin >> x >> y;
}

[[nodiscard]] double Point::distance_to_point(Point A) const
{
    return sqrt((x - A.x) * (x - A.x) + (y - A.y) * (y - A.y));
}

void Point::print() const
{
    std::cout << "(" << x << "; " << y << ")" << std::endl;
}

