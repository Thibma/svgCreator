#include "shape.hpp"

Shape::Shape(int stroke, Color strokeColor, Color fillColor) {
    this->m_stroke = stroke;
    this->m_strokeColor = strokeColor;
    this->m_fillColor = fillColor;
}

Shape::~Shape() { }

int Shape::getStroke() const {
    return this->m_stroke;
}

Color Shape::getStrokeColor() const {
    return this->m_strokeColor;
}

Color Shape::getFillColor() const {
    return this->m_fillColor;
}