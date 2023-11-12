#include "document.hpp"
#include <fstream>
#include <sstream>
#include <iterator>

Document::Document():currentSlideId(0)
{
}

void Document::init()
{
    slides.push_back(std::make_shared<Slide>());
    currentSlide = slides[currentSlideId];
}

std::shared_ptr<Slide> Document::getCurrentSlide()
{
    return slides[currentSlideId];
}

SlideVector& Document::getSlides()
{
    return slides;
}

int Document::getCurrentSlideIndex()
{
    return currentSlideId;
}

void Document::swap(Document &doc)
{
    std::swap(this->currentSlide , doc.currentSlide);
    std::swap(this->currentSlideId, doc.currentSlideId);
    std::swap(this->slides , doc.slides);
}

void Document::setCurrentSlide(int id)
{
    currentSlideId = id - 1;
    currentSlide = slides[currentSlideId];
}