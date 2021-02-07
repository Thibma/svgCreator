#ifndef STROKE_HPP
#define STROKE_HPP

#include "shape.hpp"
#include "point.hpp"

class Stroke : public Shape {
private:
    Point m_firstPoint;
    Point m_secondPoint;

public:
    Stroke(Point firstPoint, Point secondPoint, int stroke, Color strokeColor, Color fillColor);
    virtual ~Stroke();

    Point getFirstPoint();
    Point getSecondPoint();
};


#endif