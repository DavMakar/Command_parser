#ifndef DOCUMENT_HPP
#define DOCUMENT_HPP

#include <unordered_map>
#include <vector>
#include "slide.hpp"
#include "item.hpp"

class Document{
public:
    Document();
    std::unique_ptr<Slide>& getCurrentSlide();
    int getCurrentSlideIndex();
    void addItemToSlide(std::unique_ptr<Item> newItem);
    void addItemToSlide(std::unique_ptr<Item> newItem , int slideId);
    void removeItemFromSlide(int itemId);
    std::string displayCurrentSlide();
    std::string displaySlideItem(int itemId);
    std::string displayAllSlides();
    void save(std::string fileName);
    void load(std::string fileName);

    void changeCurrentSlide(int n);
private:
    int currentSlide;
    std::vector<std::unique_ptr<Slide>> slides; 
};

#endif //DOCUMENT_HPP