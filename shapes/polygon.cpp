#include "polygon.hpp"

Polygon::Polygon(int numbersOfPoints, std::vector<Point> points, int stroke, Color strokeColor, Color fillColor) : Shape(stroke, strokeColor, fillColor) {
    this->m_numbersOfPoints = numbersOfPoints;
    this->m_points = points;
}