#include "stroke.hpp"

Stroke::Stroke(Point firstPoint, Point secondPoint, int stroke, Color strokeColor, Color fillColor) : Shape(stroke, strokeColor, fillColor) {
    this->m_firstPoint = firstPoint;
    this->m_secondPoint = secondPoint;
}

Stroke::~Stroke() {
    
}