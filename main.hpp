#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <typeinfo>
#include <limits>
#include <fstream>
#include <sstream>
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
void loadADraw();

void drawEditor(Svg svg);

void createShape(vector<vector<Shape *> > &shapes);
Rectangle *createRectangle();
Circle *createCircle();
Stroke *createStroke();
Polygon *createPolygon();
void displayDraw(Svg svg);
void fusionDraw(Svg &svg);
void moveShapes(vector<vector<Shape *> > &shapes);
void upScaleShapes(vector<vector<Shape *> > &shapes);
void saveSvg(Svg svg);

int getValueFromUser(string userMessage);
string getStringFromUser(string userMessage);
Color getColor(string userMessage);

bool verifyStartFile(std::string line);
bool verifySVG(std::string line);

int getIntProperty(std::string line, std::string property);
std::string getProperty(std::string line, std::string property);
bool isComponent(std::string line, std::string component);
bool verifyBrackets(std::string line, std::string component);
vector<Point> getPointsFromLine(std::string line);

Color getColorFromLine (std::string line, std::string property);
Rectangle *getRectangleFromLine(std::string line);
Circle* getCircleFromLine(std::string line);
Svg getSvgFromLine(std::string line, std::string name);
Polygon *getPolygonFromLine(std::string line);
Stroke *getStrokeFromLine(std::string line);
Svg parser(std::string filename);
#endif