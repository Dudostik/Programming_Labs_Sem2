#ifndef PROGLAB2_CLASSES_H
#define PROGLAB2_CLASSES_H


class Vector
{
public:
    explicit Vector(float init_x = 0, float init_y = 0, float init_z = 0);
    Vector operator+(const Vector &vector2);
    Vector operator-(const Vector &vector2);
    void show_plus();
    void show_minus();
    void show_length(float &reference_length);
    void show_angle(double &reference_angle, const Vector &vector2);

private:
    float x;
    float y;
    float z;
};


#endif //PROGLAB2_CLASSES_H
