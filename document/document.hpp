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
    void insertSlide(std::shared_ptr<Slide> slide = std::make_shared<Slide>());
    void deleteSlide(size_t id);
    void changeCurrentSlide(size_t id);

    std::shared_ptr<Slide> getCurrentSlide();
    size_t getSlidesCount();

    void accept(iSerializer& vi) ;
    
    void swap(Document& doc);
    void init();

    auto begin(){ return m_slides.begin();}
    auto end(){ return m_slides.end();}

    auto begin()const {return m_slides.cbegin();}
    auto end()const {  return m_slides.cend();}

    auto cbegin() const {return m_slides.cbegin();}
    auto cend() const {return m_slides.cend();}
 
private:
    SlideVector m_slides;
    std::shared_ptr<Slide> m_pCurrentSlide;
    size_t m_slidesCount = 0; 
};

#endif //DOCUMENT_HPP