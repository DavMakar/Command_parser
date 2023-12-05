#include "Document.hpp"
#include "../serializer/iSerializer.hpp"
#include <fstream>
#include <sstream>
#include <iterator>

void Document::init()
{
    addSlide();
}

size_t Document::addSlide()
{
    slides.push_back(std::make_shared<Slide>());
    return ++slidesCount;
}

void Document::deleteSlide(size_t idx)
{
    slides.erase(std::next(begin(),idx));
    --slidesCount;
}

SlideVector &Document::getSlides()
{
    return slides;
}

std::shared_ptr<Slide> Document::getSlide(int i)
{
    return slides[i];
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
    std::swap(this->slides , doc.slides);
}
