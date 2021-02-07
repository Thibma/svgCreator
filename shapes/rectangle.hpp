#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <fstream>

#include "shape.hpp"
#include "point.hpp"

class Rectangle : public Shape {
// protected:
//     void print(std::ostream& os) const { 
//         os << "<rect ";
//         os << "x=\"" + this->getPoint().getX();
//         os << "\" cx=\"" + this->getPoint().getX();
//         os << "\" width\"" + this->getWidth();
//         os << "\" width\"" + this->getHeight();
//         os << "\" fill=\"" + this->getFillColor().getString();
//         os << "\" stroke=\"" + this->getStroke();
//         os << "\" stroke-width=\"" + this->getStrokeColor().getString();
//         os << "\" />" << std::endl;
//     }

//     friend std::ostream& operator<< (std::ostream& os, const Rectangle& rect){
//         return os << rect;
//     }

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