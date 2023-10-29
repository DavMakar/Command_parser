#include "document.hpp"
#include <fstream>
#include <sstream>
#include <iterator>

Document::Document():currentSlide(0)
{
    slides.push_back(std::make_unique<Slide>());
}

std::unique_ptr<Slide>& Document::getCurrentSlide()
{
    return slides[currentSlide];
}

int Document::getCurrentSlideIndex()
{
    return currentSlide;
}

void Document::changeCurrentSlide(int n)
{
    currentSlide = n;
}

void Document::addItemToSlide(std::unique_ptr<Item> newItem)
{
    auto& currentSlide = getCurrentSlide();
    currentSlide->addItem(std::move(newItem));
}

void Document::removeItemFromSlide(int itemId)
{
    auto& currentSlide = getCurrentSlide();
    currentSlide->removeItem(itemId);
}

std::string Document::displayCurrentSlide()
{
    auto& currentSlide = getCurrentSlide();
    return currentSlide->getAllItems();
}

std::string Document::displaySlideItem(int itemId)
{
    auto& currentSlide = getCurrentSlide();
    return currentSlide->getItemById(itemId);
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
    std::ofstream documentFile(fileName);

    int slideIndex{};

    for(auto& slide : slides){
        documentFile<<"-name "<< "slide" << "\n";        
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

void Document::addItemToSlide(std::unique_ptr<Item> newItem, int slideId)
{
    slides[slideId]->addItem(std::move(newItem));
    // FIX miguce currentSlide poxenq?
}

//TODO CurrentSlide make member