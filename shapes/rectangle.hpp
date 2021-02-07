#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <fstream>

#include "shape.hpp"
#include "point.hpp"

class Rectangle : public Shape {
public:
    Rectangle(Point point, int width, int height, int stroke, Color strokeColor, Color fillColor);
    virtual ~Rectangle();

    Point getPoint() const;
    int getWidth() const;
    int getHeight() const;

    Rectangle operator*(int multi);				 	  	  	  	  
    Rectangle operator+(int value);				 	  	  	  	  

private:
    Point m_point;
    int m_width;
    int m_height;
};

Rectangle operator*(const Rectangle &rect, int multi);
Rectangle operator*(int multi, const Rectangle &rect);

Rectangle operator+(const Rectangle &rect, int value);
Rectangle operator+(int value, const Rectangle &rect);

#endif