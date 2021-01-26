#include "point.hpp"

Point::Point(int x, int y) {
    this->m_x = x;
    this->m_y = y;
}

Point::Point() {
    this->m_x = 0;
    this->m_y = 0;
}

int Point::getX() const {
    return this->m_x;
}

int Point::getY() const {
    return this->m_y;
}