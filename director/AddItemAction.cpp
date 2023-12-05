#include "AddItemAction.hpp"
#include "../document/slide.hpp"

AddItemAction::AddItemAction(std::shared_ptr<Slide> slide, std::shared_ptr<Item> item)
    :m_slide(slide), m_item(item)
{
}

void AddItemAction::execute()
{
    m_itemId = m_slide->addItem(m_item);    
}

void AddItemAction::unexecute()
{
    m_slide->removeItem(m_itemId);
}