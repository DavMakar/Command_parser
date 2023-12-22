#include "Document.hpp"
#include "../serializer/iSerializer.hpp"
#include <fstream>
#include <sstream>
#include <iterator>
#include <cassert>

void Document::init()
{
    addSlide();
}


size_t Document::addSlide()
{
    currentSlide = std::make_shared<Slide>();
    slides.push_back(currentSlide);
    return ++slidesCount;
}

void Document::appendSlide(std::shared_ptr<Slide> slide)
{
    slides.push_back(slide);
    ++slidesCount;
}

void Document::deleteSlide(size_t idx)
{
    assert(idx > slidesCount);
    auto it = slides.erase(std::next(begin(),idx));
    if(idx < slidesCount){
        currentSlide = *it;
    }else{
        currentSlide = *std::prev(it);
    }
    --slidesCount;
}

std::shared_ptr<Slide> Document::getCurrentSlide()
{
    return currentSlide;
}

void Document::changeCurrentSlide(size_t id)
{
    currentSlide = slides[id]; 
}

void Document::accept(iSerializer &vi)
{
    std::string type("Document");
    vi.visit(type);
    vi.visit(slidesCount);
    slides.resize(slidesCount);
    for(auto& slide : slides){
        if(!slide){
            slide = std::make_unique<Slide>();
        }
        vi.visit(*slide);
    }
}

void Document::swap(Document &doc)
{
    using std::swap;
    std::swap(this->slides , doc.slides);
    slidesCount = doc.getSlidesCount();
}

size_t Document::getSlidesCount(){
    return slidesCount;
}