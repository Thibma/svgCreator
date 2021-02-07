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

    Point getFirstPoint() const; 
    Point getSecondPoint() const;

    Stroke operator*(int multi);	
    Stroke operator+(int value);	

};


Stroke operator*(const Stroke &str, int multi);
Stroke operator*(int multi, const Stroke &str);

Stroke operator+(const Stroke &str, int value);
Stroke operator+(int value, const Stroke &str);

#endif