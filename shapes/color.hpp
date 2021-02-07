#ifndef COLOR_HPP
#define COLOR_HPP

#include <map>
#include <string>

class Color {

public:
    static const Color RED;
    static const Color BLUE;
    static const Color GREEN;
    static const Color WHITE;
    static const Color BLACK;
    static const Color TRANSPARENT;

    static const Color NOCOLOR;
    static const Color OTHER;

    std::string getString();
    Color();

private:
    std::string m_string;
    Color(std::string svgString);

};


#endif