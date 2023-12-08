#ifndef ADD_ITEM_ACTION_HPP
#define ADD_ITEM_ACTION_HPP

#include "Action.hpp"
#include <memory>
class Item;
class Slide;

class AddItemAction : public Action{
public:
    AddItemAction(std::shared_ptr<Slide> slide, std::unique_ptr<Item> item);  
    void execute() override;
    void unexecute() override;
private:
    std::shared_ptr<Slide> m_slide;
    std::shared_ptr<Item> m_item;
    int m_itemId;
};

#endif //ADD_ITEM_ACTION_HPP
