#include "shape.hpp"

Shape::Shape(int stroke, Color strokeColor, Color fillColor) {
    this->m_stroke = stroke;
    this->m_strokeColor = strokeColor;
    this->m_fillColor = fillColor;
}