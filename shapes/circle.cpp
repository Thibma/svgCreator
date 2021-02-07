#include "circle.hpp"

Circle::Circle(int radius, Point center, int stroke, Color strokeColor, Color fillColor) : Shape(stroke, strokeColor, fillColor) {
    this->m_radius = radius;
    this->m_center = center;
}

Circle::~Circle() {
    
}

int Circle::getRadius() const{
    return this->m_radius;
}

Point Circle::getCenter() const{
    return this->m_center;
}

Circle Circle::operator*(int multi) {
        Color strokeColor = this->getStrokeColor();
        Color fillColor = this->getFillColor();
        int stroke = this->getStroke();
        int radius = this->getRadius() * multi;

        Circle result = Circle(radius, m_center, stroke, strokeColor, fillColor);
        return result;
}
 
Circle operator*(const Circle &c, int multi){
    Color strokeColor = c.getStrokeColor();
    Color fillColor = c.getFillColor();
    Point center = c.getCenter();
    int stroke = c.getStroke();
    int radius = c.getRadius() * multi;

    Circle result = Circle(radius, center, stroke, strokeColor, fillColor);
    return result;
}
 
Circle operator*(int multi, const Circle &c){
    return { c * multi };
}

Circle Circle::operator+(int value) {
    Color strokeColor = this->getStrokeColor();
    Color fillColor = this->getFillColor();
    int stroke = this->getStroke();
    int radius = this->getRadius();
    int x = this->getCenter().getX() + value;
    int y = this->getCenter().getY() + value;
    Point center = Point(x, y);

    Circle result = Circle(radius, center, stroke, strokeColor, fillColor);
    return result;
}
 
Circle operator+(const Circle &c, int value){
    Color strokeColor = c.getStrokeColor();
    Color fillColor = c.getFillColor();
    int stroke = c.getStroke();
    int radius = c.getRadius();
    int x = c.getCenter().getX() + value;
    int y = c.getCenter().getY() + value;
    Point center = Point(x, y);

    Circle result = Circle(radius, center, stroke, strokeColor, fillColor);
    return result;
}
 
Circle operator+(int value, const Circle &c){
    return { c + value };
}