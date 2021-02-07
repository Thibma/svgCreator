#include "polygon.hpp"

Polygon::Polygon(int numbersOfPoints, std::vector<Point> points, int stroke, Color strokeColor, Color fillColor) : Shape(stroke, strokeColor, fillColor) {
    this->m_numbersOfPoints = numbersOfPoints;
    this->m_points = points;
}

Polygon::~Polygon() {
    
}

int Polygon::getNumbersOfPoints() const {
    return this->m_numbersOfPoints;
}

std::vector<Point> Polygon::getPoints() const{
    return this->m_points;
}

// Polygon Polygon::operator*(int value) {
//     Color strokeColor = this->getStrokeColor();
//     Color fillColor = this->getFillColor();
//     int stroke = this->getStroke();
//     std::vector<Point> points;

//     for(std::vector<Point>::iterator i = this->getPoints().begin() ; i != this->getPoints().end(); i++){
//         points.push_back(Point(i->getX() * value, i->getY() * value));
//     }

//     Polygon result = Polygon(this->getNumbersOfPoints(), points, stroke, strokeColor, fillColor);
//     return result;
// }
 
// Polygon operator*(const Polygon &c, int value){
//     Color strokeColor = c.getStrokeColor();
//     Color fillColor = c.getFillColor();
//     int stroke = c.getStroke();
//     std::vector<Point> points;

//     for(std::vector<Point>::iterator i = c.getPoints().begin() ; i != c.getPoints().end(); i++){
//         points.push_back(Point(i->getX() * value, i->getY() * value));
//     }

//     Polygon result = Polygon(c.getNumbersOfPoints(), points, stroke, strokeColor, fillColor);
//     return result;
// }
 
 
// Polygon operator*(int multi, const Polygon &p){
//     return { p * multi };
// }

// Polygon Polygon::operator+(int value) {
//     Color strokeColor = this->getStrokeColor();
//     Color fillColor = this->getFillColor();
//     int stroke = this->getStroke();
//     std::vector<Point> points;

//     for(std::vector<Point>::iterator i = this->getPoints().begin() ; i != this->getPoints().end(); i++){
//         points.push_back(Point(i->getX() + value, i->getY() + value));
//     }

//     Polygon result = Polygon(this->getNumbersOfPoints(), points, stroke, strokeColor, fillColor);
//     return result;
// }
 
// Polygon operator+(const Polygon &c, int value){
//     Color strokeColor = c.getStrokeColor();
//     Color fillColor = c.getFillColor();
//     int stroke = c.getStroke();
//     std::vector<Point> points;

//     for(std::vector<Point>::iterator i = c.getPoints().begin() ; i != c.getPoints().end(); i++){
//         points.push_back(Point(i->getX() + value, i->getY() + value));
//     }

//     Polygon result = Polygon(c.getNumbersOfPoints(), points, stroke, strokeColor, fillColor);
//     return result;
// }
 
// Polygon operator+(int value, const Polygon &p){
//     return { p + value };
// }