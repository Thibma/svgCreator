#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"
#include "point.hpp"

class Rectangle : Shape {
public:
    Rectangle(Point point, int width, int height);

private:
    Point m_point;
    int m_width;
    int m_height;
};

#endif