#ifndef UNTITLED2_POINT_H
#define UNTITLED2_POINT_H

class Point
{
public:
    double x, y;
    void InitFromDialog();
    [[nodiscard]] double distance_to_point(Point A) const;
    void print() const;
};


#endif //UNTITLED2_POINT_H
