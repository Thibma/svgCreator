#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <fstream>

#include "shape.hpp"
#include "point.hpp"

class Circle : public Shape {
private:
    int m_radius;
    Point m_center;

protected:
    // void print(std::ostream& os) const{ 
    //     os << "<circle ";
    //     os << "cx=\"" + this->getCenter().getX();
    //     os << "\" cy=\"" + this->getCenter().getY();
    //     os << "\" r=\"" + this->getRadius();
    //     os << "\" fill=\"" + this->getFillColor().getString();
    //     os << "\" stroke=\"" + this->getStroke();
    //     os << "\" stroke-width=\"" + this->getStrokeColor().getString();
    //     os << "\" />" << std::endl;
    // }

    // friend std::ostream& operator<< (std::ostream& os, const Circle& circle){
    //     return os << circle;
    // }

public:
    Circle(int radius, Point center, int stroke, Color strokeColor, Color fillColor);
    virtual ~Circle();

    int getRadius() const;
    Point getCenter() const;



};


#endif