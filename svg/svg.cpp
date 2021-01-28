#include "svg.hpp"

Svg::Svg(int width, int height, std::string name) {
    this->m_width = width;
    this->m_height = height;
    this->m_name = name;
}

Svg::Svg(int width, int height, std::string name, std::vector<std::vector<Shape *> > shapes) {
    this->m_width = width;
    this->m_height = height;
    this->m_name = name;
    this->m_shapes = shapes;
}