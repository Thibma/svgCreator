#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"
#include "point.hpp"

class Circle : public Shape {
private:
    int m_radius;
    Point m_center;

public:
    Circle(int radius, Point center, int stroke, Color strokeColor, Color fillColor);
    virtual ~Circle();

    int getRadius();
    Point getCenter();
};


#endif