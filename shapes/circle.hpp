#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <fstream>

#include "shape.hpp"
#include "point.hpp"

class Circle : public Shape {
private:
    int m_radius;
    Point m_center;

public:
    Circle(int radius, Point center, int stroke, Color strokeColor, Color fillColor);
    virtual ~Circle();

    int getRadius() const;
    Point getCenter() const;

    Circle operator*(int multi);				 	  	  	  	  
    Circle operator+(int value);				 	  	  	  	  

};

Circle operator*(const Circle &c, int multi);
Circle operator*(int multi, const Circle &c);

Circle operator+(const Circle &c, int value);
Circle operator+(int value, const Circle &c);

#endif