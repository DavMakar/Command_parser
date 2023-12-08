#ifndef RENDERER_HPP
#define RENDERER_HPP

class Slide;
class Item;
class QPaintDevice;

#include <memory>

class Renderer{
public:
    void draw(std::shared_ptr<Slide> , QPaintDevice*);
    void display(std::shared_ptr<Item>);
};

#endif //RENDERER_HPP
