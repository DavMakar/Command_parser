#ifndef DOCUMENT_HPP
#define DOCUMENT_HPP

#include <unordered_map>
#include <vector>
#include "slide.hpp"
#include "item.hpp"

class Document{
public:
    Document();
    std::shared_ptr<Slide> getCurrentSlide();
    int getCurrentSlideIndex();

    void addSlide();
    void addItemToSlide(std::unique_ptr<Item> newItem);
    void addItemToSlide(std::unique_ptr<Item> newItem , int slideId);

    void removeItemFromSlide(int itemId);
    void changeCurrentSlide(int n);

    std::string displayCurrentSlide();
    std::string displaySlideItem(int itemId);
    std::string displayAllSlides();

    void save(std::string fileName);
    void load(std::string fileName);


    auto begin(){ return slides.begin();}
    auto end(){ return slides.end();}

    auto begin()const {return slides.cbegin();}
    auto end()const {  return slides.cend();}

    auto cbegin() const {return slides.cbegin();}
    auto cend() const {return slides.cend();}

private:
    int currentSlideId;
    std::shared_ptr<Slide> currentSlide;
    std::vector<std::shared_ptr<Slide>> slides; 
};

#endif //DOCUMENT_HPP