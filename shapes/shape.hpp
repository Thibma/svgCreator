#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "color.hpp"

class Shape {
private:
    int m_stroke;
    Color m_strokeColor;
    Color m_fillColor;
    
public:
    Shape(int stroke, Color strokeColor, Color fillColor);

};

#endif 