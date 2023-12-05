#ifndef DOCUMENT_DIRECTOR_HPP
#define DOCUMENT_DIRECTOR_HPP

#include <memory>
#include <stack>
#include "Action.hpp"

class TxtSerializer;
class TxtDeserializer;
class Document;

class Director {
public:
    void runAction(std::unique_ptr<Action> action);
    //void changeItem(int itemId, const std::vector<std::string>& arguments);
    //TODO change argumet type to Argument
    void changeCurrentSlide(size_t n);

    void saveDocument(Document& doc ,TxtSerializer& se);
    void loadDocument(Document& doc ,TxtDeserializer& de);

    //TODO deprecated
    [[deprecated("rendering")]] std::string displayCurrentSlide();
    [[deprecated("rendering")]] std::string displaySlideItem(int itemId);
    [[deprecated("rendering")]] std::string displayAllSlides();

    size_t& getCurrentSlideIndex();

private:
    size_t currentSlideIdx = 0;
    std::stack<std::unique_ptr<Action>> history;         
};

#endif  // DOCUMENT_DIRECTOR_HPP
