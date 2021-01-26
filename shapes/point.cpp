#include "point.hpp"

Point::Point(int x, int y) {
    m_x = x;
    m_y = y;
}

int Point::getX() const {
    return m_x;
}

int Point::getY() const {
    return m_y;
}