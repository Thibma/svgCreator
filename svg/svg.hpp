#ifndef SVG_HPP
#define SVG_HPP

#include <vector>
#include <string>

#include "../shapes/shape.hpp"

class Svg {
private:
    int m_width;
    int m_height;
    std::string m_name;
    std::vector<std::vector<Shape *> > m_shapes;

public:
    Svg(int width, int height, std::string name);
    Svg(int width, int height, std::string name, std::vector<std::vector<Shape *> > shapes);

    std::string getName();
    int getWidth();
    int getHeight();

    std::vector<std::vector<Shape *> > &getShapes();
    void setShapes(std::vector<std::vector<Shape *> > shapes);
};

#endif