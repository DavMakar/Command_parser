#include "director.hpp"

void Director::addSlide(Document& doc)
{
    doc.getSlides().push_back(std::make_shared<Slide>());
    doc.setCurrentSlide(doc.getCurrentSlideIndex()+1);
}

void Director::addItemToSlide(Document& doc, std::unique_ptr<Item> newItem)
{
    addItemToSlide(doc, std::move(newItem), doc.getCurrentSlideIndex());
}

void Director::addItemToSlide(Document& doc, std::unique_ptr<Item> newItem, int slideId)
{
    doc.getSlides().at(slideId)->addItem(std::move(newItem));
}

void Director::removeItemFromSlide(Document& doc, int itemId)
{
    doc.getCurrentSlide()->removeItem(itemId);
}

void Director::changeCurrentSlide(Document& doc, int n)
{
    doc.setCurrentSlide(n);
}

void Director::saveDocument(Document &doc, const std::string &filename)
{
    serialzer_.save(doc, filename);
}

void Director::loadDocument(Document &doc, const std::string &filename)
{
    Document newDoc;
    serialzer_.load(newDoc, filename);
    doc.swap(newDoc);
}
