#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "color.hpp"

class Shape {
private:
    int m_stroke;
    Color m_strokeColor;
    Color m_fillColor;
    
// protected:
//     virtual void print(std::ostream & stream) const;
//     friend std::ostream& operator<< (std::ostream& os, const Shape& shape){
//         return os << shape;
//     }

public:
    Shape(int stroke, Color strokeColor, Color fillColor);
    virtual ~Shape();

    int getStroke() const;
    Color getStrokeColor() const;
    Color getFillColor() const;

    // friend std::ostream& operator<< (std::ostream& os, const Shape& shape){
    //     shape.print(os);
    //     return os;
    // }

};

#endif 