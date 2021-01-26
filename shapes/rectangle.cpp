#include "rectangle.hpp"

Rectangle::Rectangle(Point point, int width, int height, int stroke, Color strokeColor, Color fillColor) : Shape(stroke, strokeColor, fillColor) {
    this->m_point = point;
    this->m_height = height;
    this->m_width = width;
}

Point Rectangle::getPoint() const {
    return this->m_point;
}

int Rectangle::getWidth() const {
    return this->m_width;
}

int Rectangle::getHeight() const {
    return this->m_height;
}