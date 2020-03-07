#include <iostream>
#include "CLASSES.h"
using namespace std;


Vector::Vector(float init_x, float init_y, float init_z)
{
    x = init_x;
    y = init_y;
    z = init_z;
}

void Vector::show_plus()
{
    cout << "result_plus: " << "(" << x << "; " << y << "; " << z << ")" << endl;
}

void Vector::show_minus()
{
    cout << "result_minus: " << "(" << x << "; " << y << "; " << z << ")" << endl;
}

void Vector::show_length(float &reference_length)
{
    reference_length = sqrt((pow(x,2) + pow(y,2) + pow(z,2)));
    cout << "result_length: " << reference_length << endl;
}

void Vector::show_angle(double &reference_angle, const Vector &vector2)
{
    reference_angle = acos((x * vector2.x + y * vector2.y + z * vector2.z) /
            (sqrt((double)x * vector2.x + y * vector2.y + z * vector2.z) *
            sqrt((double)x * vector2.x + y * vector2.y + z * vector2.z)));
    cout << "result_angle: " << reference_angle << endl;
}

Vector Vector::operator+(const Vector& vector2)
{
    Vector result_plus;
    result_plus.x = vector2.x + x;
    result_plus.y = vector2.y + y;
    result_plus.z = vector2.z + z;
    return result_plus;
}

Vector Vector::operator-(const Vector& vector2)
{
    Vector result_minus;
    result_minus.x = vector2.x - x;
    result_minus.y = vector2.y - y;
    result_minus.z = vector2.z - z;
    return result_minus;
}