#ifndef DOCUMENT_DIRECTOR_HPP
#define DOCUMENT_DIRECTOR_HPP

#include "document/document.hpp"
#include <memory>

class Visitor;

class Director {
public:
    static Director& getInstance() {
        static Director instance;
        return instance;
    }

    Document& getDocument();
    
    void addSlide();
    void addItemToSlide(std::unique_ptr<Item> newItem);
    void addItemToSlide(std::unique_ptr<Item> newItem, int slideId);
    void removeItemFromSlide(int itemId);
    void changeItem(int itemId, const std::vector<std::string>& arguments);
    void changeCurrentSlide(int n);
    
    void saveDocument(Visitor& vi);
    void loadDocument(Visitor& vi);

    std::string displayCurrentSlide();
    std::string displaySlideItem(int itemId);
    std::string displayAllSlides();

private:
    Director();  
    Director(const Director&) = delete;
    Director& operator=(const Director&) = delete;
private:
    int currentSlide;
    Document doc;
};

#endif  // DOCUMENT_DIRECTOR_HPP
