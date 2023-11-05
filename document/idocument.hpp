#ifndef DOCUMENT_INTERFACE_HPP
#define DOCUMENT_INTERFACE_HPP

#include <memory>
#include <vector>
#include "slide.hpp"

using SlideVector = std::vector<std::shared_ptr<Slide>>;

class IDocument{
public:
    virtual std::shared_ptr<Slide> getCurrentSlide()= 0;
    virtual SlideVector& getSlides() = 0;
    virtual int getCurrentSlideIndex() = 0;
    virtual void setCurrentSlide(int id) = 0;  
    virtual std::string displayCurrentSlide() = 0;
    virtual std::string displaySlideItem(int itemId)= 0;
    virtual std::string displayAllSlides() = 0;
};

#endif //DOCUMENT_INTERFACE_HPP
