#include "Director.hpp"
#include "../document/Document.hpp" //TODO 
#include "../serializer/TxtSerializer.hpp"
#include "../serializer/TxtDeserializer.hpp"

void Director::runAction(std::unique_ptr<Action> action)
{
    try{
        action->execute();
    }catch(const std::exception& e){
        throw std::runtime_error("Action incomplite");
    }
    history.push(action);
}

// void Director::changeItem(int itemId, const std::vector<std::string>& arguments)
// {
//     //auto item = doc.getSlide(currentSlide)->getItemById(itemId);
//     // for(auto it =  std::next(arguments.begin(),2); it != arguments.end(); it+=2){
//     //     item->setAttribute(*it,*std::next(it));
//     // }    
// }

void Director::changeCurrentSlide(size_t n)
{
    currentSlideIdx = n;
}

void Director::saveDocument(Document& doc,TxtSerializer& se)
{
    se.visit(doc);
}

void Director::loadDocument(Document& doc,TxtDeserializer& de)
{
    Document newDoc;
    de.visit(newDoc);
    std::swap(doc,newDoc);
}

std::string Director::displayAllSlides()
{
    std::string result;
    // int slideIdx{1};
    // for(auto& slide:doc.getSlides()){
    //     result+= "slide " + std::to_string(slideIdx) + "\n";    
    //     for(const auto& [id,item]: *slide){
    //         result += std::to_string(id) + " " + item->type() + "\n";
    //     }
    //     ++slideIdx;
    // }
    return result;
}

size_t &Director::getCurrentSlideIndex()
{
    return currentSlideIdx;
}

std::string Director::displayCurrentSlide()
{
    //return doc.getSlide(currentSlide)->getAllItems();
}

std::string Director::displaySlideItem(int itemId)
{
//    return doc.getSlide(currentSlide)->getItemById(itemId)->info();
}

