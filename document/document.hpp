#ifndef DOCUMENT_HPP
#define DOCUMENT_HPP

#include <unordered_map>
#include <vector>
#include "idocument.hpp"

class Document : public IDocument{
public:
    Document();
    std::shared_ptr<Slide> getCurrentSlide() override;
    SlideVector& getSlides() override;
    int getCurrentSlideIndex() override;
    void setCurrentSlide(int id) override;
    
    std::string displayCurrentSlide() override;
    std::string displaySlideItem(int itemId) override;
    std::string displayAllSlides() override;

    void save(std::string fileName) override;
    void load(std::string fileName) override;

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