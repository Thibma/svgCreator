#include "color.hpp"

Color::Color(std::string svgString) {
    this->m_string = svgString;
}

Color::Color() {
    this->m_string = "null";
}

std::string Color::getString() {
    return this->m_string;
}

const Color Color::RED = Color("red");
const Color Color::BLUE = Color("blue");
const Color Color::GREEN = Color("green");
const Color Color::WHITE = Color("white");
const Color Color::BLACK = Color("black");
const Color Color::TRANSPARENT = Color("transparent");

const Color Color::NOCOLOR = Color("null");