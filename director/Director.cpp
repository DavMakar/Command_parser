#include "Director.hpp"

#include "../serializer/TxtSerializer.hpp"
#include "../serializer/TxtDeserializer.hpp"

Director::Director():currentSlide(0)
{
    doc.init();
}

Document& Director::getDocument()
{
    return doc;
}

void Director::addSlide()
{
    doc.addSlide();
    ++currentSlide;
}

void Director::addItemToSlide(std::unique_ptr<Item> newItem)
{
    addItemToSlide(std::move(newItem),currentSlide);
}

void Director::addItemToSlide(std::unique_ptr<Item> newItem, int slideId)
{
    doc.getSlide(slideId)->addItem(std::move(newItem));
}

void Director::removeItemFromSlide(int itemId)
{
    doc.getSlide(currentSlide)->removeItem(itemId);
}

void Director::changeItem(int itemId, const std::vector<std::string>& arguments)
{
    auto item = doc.getSlide(currentSlide)->getItemById(itemId);
    for(auto it =  std::next(arguments.begin(),2); it != arguments.end(); it+=2){
        item->setAttribute(*it,*std::next(it));
    }    
}

void Director::changeCurrentSlide(int n)
{
    currentSlide = n;
}

void Director::saveDocument(SerializerVisitor& vi)
{
    vi.visit(doc);
}

void Director::loadDocument(DeserializerVisitor& vi)
{
    Document newDoc;
    vi.visit(newDoc);
    std::swap(doc,newDoc);
}

std::string Director::displayAllSlides()
{
    std::string result;
    int slideIdx{1};
    for(auto& slide:doc.getSlides()){
        result+= "slide " + std::to_string(slideIdx) + "\n";    
        for(const auto& [id,item]: *slide){
            result += std::to_string(id) + " " + item->type() + "\n";
        }
        ++slideIdx;
    }
    return result;
}

std::string Director::displayCurrentSlide()
{
    return doc.getSlide(currentSlide)->getAllItems();
}

std::string Director::displaySlideItem(int itemId)
{
    return doc.getSlide(currentSlide)->getItemById(itemId)->info();
}

