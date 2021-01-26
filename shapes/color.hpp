#ifndef COLOR_HPP
#define COLOR_HPP

#include <map>
#include <string>

enum Color {
    red,
    blue,
    green,
    white,
    dark,
    transparent
};

std::map<Color, std::string> colors = {
    { red, "red" },
    { blue, "blue" },
    { green, "green" },
    { white, "white" },
    { dark, "dark" },
    { transparent, "transparent" }
};

#endif