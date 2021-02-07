#ifndef POLYGON_HPP
#define POLYGON_HPP

#include <vector>

#include "shape.hpp"
#include "point.hpp"

class Polygon : public Shape {
private:
    int m_numbersOfPoints;
    std::vector<Point> m_points;

public:
    Polygon(int numbersOfPoints, std::vector<Point> points, int stroke, Color strokeColor, Color fillColor);
    virtual ~Polygon();

    int getNumbersOfPoints() const;
    std::vector<Point> getPoints() const;

    // Polygon operator*(int multi);				 	  	  	  	  
    // Polygon operator+(int value);
};


// Polygon operator*(const Polygon &p, int multi);
// Polygon operator*(int multi, const Polygon &p);

// Polygon operator+(const Polygon &p, int value);
// Polygon operator+(int value, const Polygon &p);
#endif