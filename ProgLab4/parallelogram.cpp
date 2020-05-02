#include <iostream>
#include "parallelogram.h"

[[nodiscard]] double Parallelogram::square() const
{
    return a.center().distance_to_point(b.center()) * a.length();
}

[[nodiscard]] double Parallelogram::perimeter() const
{
    return a.length() + b.length() + a.X.distance_to_point(b.X) + a.Y.distance_to_point(b.Y);
}

void Parallelogram::draw() const
{
    std::cout << "The first base of the parallelogram" << std::endl;
    a.print();
    std::cout << "\nThe second base of the parallelogram" << std::endl;
    b.print();
}

[[nodiscard]] const char *Parallelogram::classname() const
{
    return "Parallelogram";
}

[[nodiscard]] unsigned int Parallelogram::size() const
{
    return sizeof(*this);
}

void Parallelogram::initFromDialog()
{
    std::cout << "Initialization" << std::endl;
    std::cout << "The first base of the parallelogram" << std::endl;
    std::cout << "Enter the coordinates of the first point through the space:";
    a.X.InitFromDialog();

    std::cout << "Enter the coordinates of the second point through the space: ";
    a.Y.InitFromDialog();

    std::cout << "\nThe second base of the parallelogram" << std::endl;
    std::cout << "Enter the coordinates of the first point through the space:";
    b.X.InitFromDialog();

    std::cout << "Enter the coordinates of the second point through the space: ";
    b.Y.InitFromDialog();
}

[[nodiscard]] double Parallelogram::mass() const
{
    return square();
}

[[nodiscard]] Point Parallelogram::position() const
{
    Vector2D temp{a.X, b.Y};
    return temp.center();
}

bool Parallelogram::operator==(const InterfacePhysObject &ob) const
{
    return this->mass() == ob.mass();
}

bool Parallelogram::operator<(const InterfacePhysObject &ob) const
{
    return this->mass() < ob.mass();
}