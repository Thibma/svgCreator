#include "rectangle.hpp"

Rectangle::Rectangle(Point point, int width, int height, int stroke, Color strokeColor, Color fillColor) : Shape(stroke, strokeColor, fillColor) {
    this->m_point = point;
    this->m_height = height;
    this->m_width = width;
}

Rectangle::~Rectangle() {
    
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

Rectangle Rectangle::operator*(int multi) {
        Color strokeColor = this->getStrokeColor();
        Color fillColor = this->getFillColor();
        int stroke = this->getStroke();
        int width = m_width * multi;
        int height = m_height * multi;

        Rectangle result = Rectangle(m_point, width, height, stroke, strokeColor, fillColor);
        return result;
}
 
Rectangle operator*(const Rectangle &rect, int multi){

    Point point = rect.getPoint();
    Color strokeColor = rect.getStrokeColor();
    Color fillColor = rect.getFillColor();
    int stroke = rect.getStroke();
    int width = rect.getWidth() * multi;
    int height = rect.getHeight() * multi;

    Rectangle result = Rectangle(point, width, height, stroke, strokeColor, fillColor);
    return result;
}
 
Rectangle operator*(int multi, const Rectangle &rect){
    return { rect * multi };
}

Rectangle Rectangle::operator+(int value) {
        Color strokeColor = this->getStrokeColor();
        Color fillColor = this->getFillColor();
        int stroke = this->getStroke();
        int width = m_width + value;
        int height = m_height + value;

        Rectangle result = Rectangle(m_point, width, height, stroke, strokeColor, fillColor);
        return result;
}
 
Rectangle operator+(const Rectangle &rect, int value){

    Point point = rect.getPoint();
    Color strokeColor = rect.getStrokeColor();
    Color fillColor = rect.getFillColor();
    int stroke = rect.getStroke();
    int width = rect.getWidth() + value;
    int height = rect.getHeight() + value;

    Rectangle result = Rectangle(point, width, height, stroke, strokeColor, fillColor);
    return result;
}
 
Rectangle operator+(int value, const Rectangle &rect){
    return { rect + value };
}