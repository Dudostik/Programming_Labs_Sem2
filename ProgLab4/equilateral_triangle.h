#ifndef UNTITLED2_EQUILATERAL_TRIANGLE_H
#define UNTITLED2_EQUILATERAL_TRIANGLE_H

#include "point.h"
#include "interface.h"
#include "base_class.h"

class EquilateralTriangle: public BaseClass
{
public:
    ~EquilateralTriangle() override = default;

    Point center{0, 0};
    double length = 0;

    [[nodiscard]] double square() const override;
    [[nodiscard]] double perimeter() const override;
    void draw() const override; // override
    [[nodiscard]] const char *classname() const override;
    [[nodiscard]] unsigned int size() const override;
    void initFromDialog() override;
    [[nodiscard]] double mass() const override;
    [[nodiscard]] Point position() const override;
    bool operator==(const InterfacePhysObject &ob) const override;
    bool operator<(const InterfacePhysObject &ob) const override;
};

#endif //UNTITLED2_EQUILATERAL_TRIANGLE_H
