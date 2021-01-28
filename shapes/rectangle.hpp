#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"
#include "point.hpp"

class Rectangle : public Shape {
public:
    Rectangle(Point point, int width, int height, int stroke, Color strokeColor, Color fillColor);
    virtual ~Rectangle();

    Point getPoint() const;
    int getWidth() const;
    int getHeight() const;

private:
    Point m_point;
    int m_width;
    int m_height;
};

#endif