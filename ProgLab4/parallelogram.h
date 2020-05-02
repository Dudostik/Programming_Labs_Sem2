#ifndef UNTITLED2_PARALLELOGRAM_H
#define UNTITLED2_PARALLELOGRAM_H

#include "point.h"
#include "vector2d.h"
#include "interface.h"
#include "base_class.h"


class Parallelogram: public BaseClass
{
public:
    ~Parallelogram() override = default;

    // Let the parallelogram set through two co-directed vectors denoting its foundations
    Vector2D a{{0, 0}, {0, 0}};
    Vector2D b{{0, 0}, {0, 0}};

    [[nodiscard]] double square() const override;

    [[nodiscard]] double perimeter() const override;

    void draw() const override;

    [[nodiscard]] const char *classname() const override;

    [[nodiscard]] unsigned int size() const override;

    void initFromDialog() override;

    [[nodiscard]] double mass() const override;

    [[nodiscard]] Point position() const override;

    bool operator==(const InterfacePhysObject &ob) const override;

    bool operator<(const InterfacePhysObject &ob) const override;
};


#endif //UNTITLED2_PARALLELOGRAM_H
