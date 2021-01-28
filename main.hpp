#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <string>
#include <typeinfo>

#include "shapes/point.hpp"

#include "shapes/circle.hpp"
#include "shapes/polygon.hpp"
#include "shapes/rectangle.hpp"
#include "shapes/stroke.hpp"

#include "shapes/color.hpp"

#include "svg/svg.hpp"

using namespace std;

void firstMenu();
void createADraw();

void drawEditor(Svg svg);

void createShape(vector<vector<Shape *> > &shapes);

Rectangle *createRectangle();
Circle *createCircle();
Stroke *createStroke();
Polygon *createPolygon();

int getValueFromUser(string userMessage);
string getStringFromUser(string userMessage);
Color getColor(string userMessage);
#endif