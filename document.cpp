#include "document.hpp"
#include <fstream>
#include <sstream>
#include <iterator>

Document::Document():currentSlideId(0)
{
    addSlide();
    currentSlide = slides[currentSlideId];
}

std::shared_ptr<Slide> Document::getCurrentSlide()
{
    return slides[currentSlideId];
}

int Document::getCurrentSlideIndex()
{
    return currentSlideId;
}

void Document::addSlide()
{
    slides.push_back(std::make_unique<Slide>());
}

void Document::changeCurrentSlide(int n)
{
    currentSlideId = n;
    currentSlide = slides[currentSlideId];
}

void Document::addItemToSlide(std::unique_ptr<Item> newItem)
{
    addItemToSlide(std::move(newItem),currentSlideId);
}

void Document::addItemToSlide(std::unique_ptr<Item> newItem, int slideId)
{
    slides.at(slideId)->addItem(std::move(newItem));
}


void Document::removeItemFromSlide(int itemId)
{
    currentSlide->removeItem(itemId);
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


//TODO CurrentSlide make member