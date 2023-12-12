#ifndef DOCUMENT_HPP
#define DOCUMENT_HPP

#include <unordered_map>
#include <vector>
#include "slide.hpp"

using SlideVector = std::vector<std::shared_ptr<Slide>>;

class Document{
public:
    Document() = default;
    
    size_t addSlide();
    void deleteSlide(size_t id);
    std::shared_ptr<Slide> getCurrentSlide();
    void changeCurrentSlide(size_t id);
    size_t getSlidesCount();

    void accept(iSerializer& vi) ;
    
    void swap(Document& doc);
    void init();

    auto begin(){ return slides.begin();}
    auto end(){ return slides.end();}

    auto begin()const {return slides.cbegin();}
    auto end()const {  return slides.cend();}

    auto cbegin() const {return slides.cbegin();}
    auto cend() const {return slides.cend();}

private:
    SlideVector slides;
    std::shared_ptr<Slide> currentSlide;
    size_t slidesCount = 0; 
};

#endif //DOCUMENT_HPP