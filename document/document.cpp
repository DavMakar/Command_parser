#include "Document.hpp"
#include "../serializer/iSerializer.hpp"
#include <fstream>
#include <sstream>
#include <iterator>
#include <cassert>

void Document::init()
{
    insertSlide();
}

size_t Document::addSlide()
{
    insertSlide();
    return m_slidesCount;
}

void Document::insertSlide(std::shared_ptr<Slide> slide)
{
    m_pCurrentSlide = std::move(slide);
    m_slides.push_back(m_pCurrentSlide);
    ++m_slidesCount;
}

void Document::deleteSlide(size_t idx)
{
    assert(idx > m_slidesCount);
    auto it = m_slides.erase(std::next(begin(),idx));
    if(idx < m_slidesCount){
        m_pCurrentSlide = *it;
    }else{
        m_pCurrentSlide = *std::prev(it);
    }
    --m_slidesCount;
}

std::shared_ptr<Slide> Document::getCurrentSlide()
{
    return m_pCurrentSlide;
}

void Document::changeCurrentSlide(size_t id)
{
    m_pCurrentSlide = m_slides[id];
}

void Document::accept(iSerializer &vi)
{
    // std::string type("Document");
    // vi.visit(type);
    // vi.visit(slidesCount);
    // slides.resize(slidesCount);
    // for(auto& slide : slides){
    //     if(!slide){
    //         slide = std::make_unique<Slide>();
    //     }
    //     vi.visit(*slide);
    // }
}

void Document::swap(Document &doc)
{
    using std::swap;
    std::swap(this->m_slides , doc.m_slides);
    changeCurrentSlide(0);
    std::swap(this->m_slidesCount,doc.m_slidesCount);
}

size_t Document::getSlidesCount(){
    return m_slidesCount;
}
