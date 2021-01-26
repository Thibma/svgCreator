#ifndef POLYGON_HPP
#define POLYGON_HPP

#include <vector>

#include "shape.hpp"
#include "point.hpp"

class Polygon : Shape {
private:
    int m_numbersOfPoints;
    std::vector<Point> m_points;

public:
    Polygon(int numbersOfPoints, std::vector<Point> points, int stroke, Color strokeColor, Color fillColor);
}

#endif