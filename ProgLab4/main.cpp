#include <iostream>
#include <cmath>
#include <vector>
#include "point.h"
#include "vector2d.h"
#include "interface.h"
#include "base_class.h"
#include "equilateral_triangle.h"
#include "parallelogram.h"


int main()
{
    // Keeping multiple shapes
    std::vector<BaseClass*> geoObjects;

    std::cout << "Enter the number of objects stored: ";
    int k;
    std::cin >> k;
    if (k <= 0) return 0;

    // Adding by user through a console
    for (int i = 0; i < k; ++i)
    {
        int type;
        std::cout << "\nObject types: " << std::endl;
        std::cout << "1: EquilateralTriangle" << std::endl;
        std::cout << "2: Parallelogram" << std::endl;
        do
        {
            std::cout << "Enter the type of object: ";
            std::cin >> type;
        }

        while (!(type == 1 || type == 2));

        if (type == 1)
            geoObjects.push_back(new EquilateralTriangle);
        else
            geoObjects.push_back(new Parallelogram);

        geoObjects.back()->initFromDialog();
    }

    std::cout << "\nReflection of all the shapes:" << std::endl;
    // Reflection of all the shapes
    int count = 1;
    for (auto i : geoObjects)
    {
        std::cout << count++ << "): " << i->classname() << std::endl;
        i->draw();
        std::cout << std::endl;
    }

    // Sum area of all figures
    std::cout << "\nSum area of all figures: ";
    double s = 0;
    for (auto i : geoObjects)
    {
        s += i->square();
    }
    std::cout << s << std::endl;


    // Sum perimeter of all figures
    std::cout << "Sum perimeter of all figures: ";
    s = 0;
    for (auto i : geoObjects)
    {
        s += i->perimeter();
    }
    std::cout << s << std::endl;

    // Memory occupied by all instances of classes
    std::cout << "Memory occupied by all instances of classes: ";
    unsigned int r = 0;
    for (auto i : geoObjects)
    {
        r += i->size();
    }
    std::cout << r << std::endl;

    // Object centres
    std::cout << "\nObject centres:" << std::endl;
    count = 0;
    for (auto i : geoObjects)
    {
        std::cout << ++count << ":" << std::endl;
        i->position().print();
    }

    // Removing and releasing memory
    for (auto &geoObject: geoObjects)
    {
        delete geoObject;
    }
    return 0;
}