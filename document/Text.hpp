#ifndef TEXT_ITEM_HPP
#define TEXT_ITEM_HPP

#include "item.hpp"
#include "Point.hpp"

class Text : public Item{
public:
    Text();
    Text(Point location, std::string text , int fontSize);

    Point location_;
    std::string text_;
    int fontSize_;
};

#endif //TEXT_ITEM_HPP