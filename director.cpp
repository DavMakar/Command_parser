#include "director.hpp"

#include "serializer/serializer.hpp"

Director::Director()
{
    doc.init();
}

Document& Director::getDocument()
{
    return doc;
}

void Director::addSlide()
{
    doc.getSlides().push_back(std::make_shared<Slide>());
    doc.setCurrentSlide(doc.getCurrentSlideIndex()+1);
}

void Director::addItemToSlide(std::unique_ptr<Item> newItem)
{
    addItemToSlide(std::move(newItem), doc.getCurrentSlideIndex());
}

void Director::addItemToSlide(std::unique_ptr<Item> newItem, int slideId)
{
    doc.getSlides().at(slideId)->addItem(std::move(newItem));
}

void Director::removeItemFromSlide(int itemId)
{
    doc.getCurrentSlide()->removeItem(itemId);
}

void Director::changeItem(int itemId, const std::vector<std::string>& arguments)
{
    // auto item = doc.getCurrentSlide()->getItemById(itemId);
    // for(auto it =  std::next(arguments.begin(),2); it != arguments.end(); it+=2){
    //     item->setAttribute(*it,*std::next(it));
    // }    
}

void Director::changeCurrentSlide(int n)
{
    doc.setCurrentSlide(n);
}

void Director::saveDocument(Serializer &saver, const std::string &filename)
{
    saver.save(filename);
}

void Director::loadDocument(Serializer& loader,const std::string &filename)
{
    loader.load(filename);
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
    return doc.getCurrentSlide()->getAllItems();
}

std::string Director::displaySlideItem(int itemId)
{
    return doc.getCurrentSlide()->getItemById(itemId)->info();
}

