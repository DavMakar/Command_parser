#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "item.hpp"
#include <unordered_set>

class Rect: public Item{
public:
    Rect();
    std::string className() override;
    std::string info() override;
    std::string getAttrbute(std::string key) override;
    void setAttribute(std::string key , std::string value) override;
    std::unique_ptr<Item> clone() override;
};

#endif //RECTANGLE_HPP
