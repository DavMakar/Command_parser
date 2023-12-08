#ifndef INTERFACE_VISUAL_DISPLAYABLE
#define INTERFACE_VISUAL_DISPLAYABLE

class QPainter;
class Item;

#include <memory>

class IVisualDisplayable{
public:
    virtual void draw(QPainter* painter , std::shared_ptr<Item> item) = 0;
};

#endif //INTERFACE_VISUAL_DISPLAYABLE