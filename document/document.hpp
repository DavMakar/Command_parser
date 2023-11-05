#ifndef DOCUMENT_HPP
#define DOCUMENT_HPP

#include <unordered_map>
#include <vector>
#include "slide.hpp"

using SlideVector = std::vector<std::shared_ptr<Slide>>;

class Document{
public:
    Document();
    
    std::shared_ptr<Slide> getCurrentSlide();
    SlideVector& getSlides();
    int getCurrentSlideIndex();
    void setCurrentSlide(int id);

    std::string displayCurrentSlide();
    std::string displaySlideItem(int itemId);
    std::string displayAllSlides();
    
    void swap(Document& doc);
    void init();

    auto begin(){ return slides.begin();}
    auto end(){ return slides.end();}

    auto begin()const {return slides.cbegin();}
    auto end()const {  return slides.cend();}

    auto cbegin() const {return slides.cbegin();}
    auto cend() const {return slides.cend();}

private:
    int currentSlideId;
    std::shared_ptr<Slide> currentSlide;
    SlideVector slides; 
};

#endif //DOCUMENT_HPP