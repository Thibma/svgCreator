#include "circle.hpp"

Circle::Circle(int radius, Point center, int stroke, Color strokeColor, Color fillColor) : Shape(stroke, strokeColor, fillColor) {
    this->m_radius = radius;
    this->m_center = center;
}

Circle::~Circle() {
    
}

int Circle::getRadius() {
    return this->m_radius;
}

Point Circle::getCenter() {
    return this->m_center;
}