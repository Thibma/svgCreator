#ifndef POINT_HPP
#define POINT_HPP

class Point {
private:
    int m_x;
    int m_y;

public:
    Point(int x, int y);
    Point();

    int getX() const;
    int getY() const;

};

#endif