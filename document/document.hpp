#ifndef DOCUMENT_HPP
#define DOCUMENT_HPP

#include <unordered_map>
#include <vector>
#include "slide.hpp"

using SlideVector = std::vector<std::shared_ptr<Slide>>;

class Document{
public:
    Document();
    
    void addSlide();
    SlideVector& getSlides();
    std::shared_ptr<Slide> getSlide(int i);

    void accept(Visitor& vi) ;
    
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
    size_t slidesCount = 0; 
};

#endif //DOCUMENT_HPP