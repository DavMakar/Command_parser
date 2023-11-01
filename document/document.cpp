#include "document.hpp"
#include <fstream>
#include <sstream>
#include <iterator>

Document::Document():currentSlideId(0)
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

std::string Document::displayCurrentSlide()
{
    return currentSlide->getAllItems();
}

std::string Document::displaySlideItem(int itemId)
{
    return currentSlide->getItemById(itemId)->info();
}

std::string Document::displayAllSlides()
{
    std::string result;
    int slideIdx{};
    for(auto& slide:slides){
        result+= "slide " + std::to_string(slideIdx) + "\n";    
        for(const auto& [id,item]: *slide){
            result += std::to_string(id) + " " + item->type() + "\n";
        }
        ++slideIdx;
    }
    return result;
}

void Document::save(std::string fileName)
{
    std::ofstream documentFile("../save/"+fileName);

    int slideIndex{};

    for(auto& slide : slides){
        documentFile<< *slide <<" "<< slideIndex++ << "\n";        
        for(const auto& [id,item] : *slide){
            documentFile<<"-name "<< item->info() <<"\n";
        }
    }
}

void Document::load(std::string filename)
{
    std::ifstream documentFlie(filename);
    std::string line;
    while (getline(documentFlie,line)){
        std::istringstream iss{line};
        std::vector<std::string> arguments(std::istream_iterator<std::string>{iss},{});
        //TODO
    }   
}

void Document::setCurrentSlide(int id)
{
    currentSlideId = id;
    currentSlide = slides[currentSlideId];
}

//TODO CurrentSlide make member