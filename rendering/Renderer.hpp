#ifndef RENDERER_HPP
#define RENDERER_HPP

class Slide;
class Item;
class QPaintDevice;

#include <memory>
#include "ShapeLibrary.hpp"

class Renderer{
public:
    void draw(std::shared_ptr<Slide> , QPaintDevice*);
    void display(std::shared_ptr<Item>);
private:
    ShapeLibrary m_shapeLibrary;
};

#endif //RENDERER_HPP
