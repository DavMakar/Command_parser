#include "document.hpp"
#include "../serializer/Visitor.hpp"
#include <fstream>
#include <sstream>
#include <iterator>

void Document::init()
{
    addSlide();
}

void Document::addSlide()
{
    slides.push_back(std::make_shared<Slide>());
    ++slidesCount;
}

SlideVector &Document::getSlides()
{
    return slides;
}

std::shared_ptr<Slide> Document::getSlide(int i)
{
    return slides[i];
}

void Document::accept(Visitor &vi)
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
