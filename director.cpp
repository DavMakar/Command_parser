#include "director.hpp"

void Director::addSlide(IDocument& doc)
{
    doc.getSlides().push_back(std::make_shared<Slide>());
}

void Director::addItemToSlide(IDocument& doc, std::unique_ptr<Item> newItem)
{
    addItemToSlide(doc, std::move(newItem), doc.getCurrentSlideIndex());
}

void Director::addItemToSlide(IDocument& doc, std::unique_ptr<Item> newItem, int slideId)
{
    doc.getSlides().at(slideId)->addItem(std::move(newItem));
}

void Director::removeItemFromSlide(IDocument& doc, int itemId)
{
    doc.getCurrentSlide()->removeItem(itemId);
}

void Director::changeCurrentSlide(IDocument& doc, int n)
{
    doc.setCurrentSlide(n);
}
