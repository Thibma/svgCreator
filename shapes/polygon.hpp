#ifndef POLYGON_HPP
#define POLYGON_HPP

#include <vector>

#include "shape.hpp"
#include "point.hpp"

class Polygon : public Shape {
private:
    int m_numbersOfPoints;
    std::vector<Point> m_points;

// protected:
//     void print(std::ostream& os) const{ 
//     }
//     friend std::ostream& operator<< (std::ostream& os, const Polygon& polygon){
//         return os << polygon;
//     }

public:
    Polygon(int numbersOfPoints, std::vector<Point> points, int stroke, Color strokeColor, Color fillColor);
    virtual ~Polygon();

    int getNumbersOfPoints();
    std::vector<Point> getPoints();
};

#endif