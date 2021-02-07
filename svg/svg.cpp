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

std::string Svg::getName() {
    return this->m_name;
}

int Svg::getWidth() {
    return this->m_width;
}

int Svg::getHeight() {
    return this->m_height;
}

std::vector<std::vector<Shape *> > &Svg::getShapes() {
    return this->m_shapes;
}

void Svg::setShapes(std::vector<std::vector<Shape *> > shapes) {
    this->m_shapes = shapes;
}

// void Svg::save(){
//     std::ofstream MyFile(getName() + ".svg");
//     MyFile << "<?xml version=\"1.0\" standalone=\"no\"?>" << std::endl;
//     MyFile << "<svg width=\"" << getWidth() << "cm\" height=\"" << getHeight() << "cm\" version=\"1.1\"" << std::endl;
    
//     std::vector<std::vector<Shape *>>::const_iterator shapes; 
//     std::vector<Shape *>::const_iterator shape; 

//     for(shapes = m_shapes.begin(); shapes != m_shapes.end(); ++shapes){

//          for (shape = shapes->begin(); shape != shapes->end(); ++shape)
//          { 
//             std::cout << *shape << std::endl;
//             MyFile << *shape << std::endl;
//          } 
//     }

//     MyFile.close();
// }