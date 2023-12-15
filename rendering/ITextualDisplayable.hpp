#ifndef INTERFACE_TEXTUAL_DISPLAYABLE
#define INTERFACE_TEXTUAL_DISPLAYABLE

#include <iostream>
#include <memory>
class Item;

class ITextualDisplayable{
public:
    virtual void print(std::shared_ptr<Item> item) = 0;
};

#endif //INTERFACE_TEXTUAL_DISPLAYABLE