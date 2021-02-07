#include "stroke.hpp"

Stroke::Stroke(Point firstPoint, Point secondPoint, int stroke, Color strokeColor, Color fillColor) : Shape(stroke, strokeColor, fillColor) {
    this->m_firstPoint = firstPoint;
    this->m_secondPoint = secondPoint;
}

Stroke::~Stroke() {
    
}

Point Stroke::getFirstPoint() const{
    return this->m_firstPoint;
}

Point Stroke::getSecondPoint() const {
    return this->m_secondPoint;
}

Stroke Stroke::operator*(int multi) {
        Color strokeColor = this->getStrokeColor();
        Color fillColor = this->getFillColor();
        int stroke = this->getStroke();

        int x2 = this->getSecondPoint().getX() * multi;
        int y2 = this->getSecondPoint().getY() * multi;
        Point firstPoint = this->getFirstPoint();
        Point secondPoint = Point(x2, y2);

        Stroke result = Stroke(firstPoint, secondPoint, stroke, strokeColor, fillColor);
        return result;
}
 
Stroke operator*(const Stroke &str, int multi){
    int stroke = str.getStroke();
    Color strokeColor = str.getStrokeColor();
    Color fillColor = str.getFillColor();

    int x2 = str.getSecondPoint().getX() * multi;
    int y2 = str.getSecondPoint().getY() * multi;
    Point firstPoint = str.getFirstPoint();
    Point secondPoint = Point(x2, y2);

    Stroke result = Stroke(firstPoint, secondPoint, stroke, strokeColor, fillColor);
    return result;
}
 
Stroke operator*(int multi, const Stroke &str){
    return { str * multi };
}

Stroke Stroke::operator+(int value) {
        Color strokeColor = this->getStrokeColor();
        Color fillColor = this->getFillColor();
        int stroke = this->getStroke();

        int x2 = this->getSecondPoint().getX() + value;
        int y2 = this->getSecondPoint().getY() + value;

        int x1 = this->getFirstPoint().getX() + value;
        int y1 = this->getFirstPoint().getY() + value;
        Point firstPoint = Point(x1, y1);
        Point secondPoint = Point(x2, y2);

        Stroke result = Stroke(firstPoint, secondPoint, stroke, strokeColor, fillColor);
        return result;
}
 
Stroke operator+(const Stroke &str, int value){
    int stroke = str.getStroke();
    Color strokeColor = str.getStrokeColor();
    Color fillColor = str.getFillColor();

    int x2 = str.getSecondPoint().getX() + value;
    int y2 = str.getSecondPoint().getY() + value;

    int x1 = str.getFirstPoint().getX() + value;
    int y1 = str.getFirstPoint().getY() + value;
    Point firstPoint = Point(x1, y1);
    Point secondPoint = Point(x2, y2);

    Stroke result = Stroke(firstPoint, secondPoint, stroke, strokeColor, fillColor);
    return result;
}
 
Stroke operator+(int value, const Stroke &str){
    return { str * value };
}