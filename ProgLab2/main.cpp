#include <iostream>
#include "CLASSES.h"
using namespace std;


int main()
{
    float length;
    double angle;

    // vector1 + vector2; vector2 - vector1
    cout << "\n/*TASK 1*/" << endl;
    Vector vector1(1, 2, 3);
    Vector vector2(4,3, 5);

    (vector1 + vector2).show_plus();
    (vector1 - vector2).show_minus();

    // Vector length
    cout << "\n/*TASK 2*/" << endl;
    vector1.show_length(length);
    vector2.show_length(length);

    // Vector angle
    cout << "\n/*TASK 3*/" << endl;
    vector2.show_angle(angle, vector2);
    return 0;
}