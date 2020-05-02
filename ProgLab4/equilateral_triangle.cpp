#include <iostream>
#include "equilateral_triangle.h"

[[nodiscard]] double EquilateralTriangle::square() const // override
{
    return (length * sqrt((3 * pow(length,2))/4))/2;
}

[[nodiscard]] double EquilateralTriangle::perimeter() const // override
{
    return 3 * length;
}

void EquilateralTriangle::draw() const // override
{
    std::cout << "Triangle center: ";
    center.print();
    std::cout << "The length of the base: " << length << std::endl;
}

[[nodiscard]] const char *EquilateralTriangle::classname() const // override
{
    return "EquilateralTriangle";
}

[[nodiscard]] unsigned int EquilateralTriangle::size() const // override
{
    return sizeof(*this);
}

void EquilateralTriangle::initFromDialog() // override
{
    std::cout << "Initialization" << std::endl;
    std::cout << "Enter the coordinates of the center point through the gaps:";
    center.InitFromDialog();
    std::cout << "Enter the length of the triangle edge: ";
    std::cin >> length;
}

[[nodiscard]] double EquilateralTriangle::mass() const // override
{
    return square();
}

[[nodiscard]] Point EquilateralTriangle::position() const // override
{
    return center;
}

bool EquilateralTriangle::operator==(const InterfacePhysObject &ob) const // override
{
    return this->mass() == ob.mass();
}

bool EquilateralTriangle::operator<(const InterfacePhysObject &ob) const // override
{
    return this->mass() < ob.mass();
}
