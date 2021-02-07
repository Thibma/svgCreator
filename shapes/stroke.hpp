#ifndef STROKE_HPP
#define STROKE_HPP

#include "shape.hpp"
#include "point.hpp"

class Stroke : public Shape {
private:
    Point m_firstPoint;
    Point m_secondPoint;

// protected:
//     void print(std::ostream& os) const{ 
//     }

//     friend std::ostream& operator<< (std::ostream& os, const Stroke& stroke){
//         return os << stroke;
//     }

public:
    Stroke(Point firstPoint, Point secondPoint, int stroke, Color strokeColor, Color fillColor);
    virtual ~Stroke();

    Point getFirstPoint();
    Point getSecondPoint();
};




#endif