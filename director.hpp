#ifndef DOCUMENT_DIRECTOR_HPP
#define DOCUMENT_DIRECTOR_HPP

#include "item.hpp"
#include "./document/idocument.hpp"

class Director{
public:
    void addSlide(IDocument& doc);
    void addItemToSlide(IDocument& doc , std::unique_ptr<Item> newItem);
    void addItemToSlide(IDocument& doc , std::unique_ptr<Item> newItem , int slideId);
    void removeItemFromSlide(IDocument& doc , int itemId);
    void changeCurrentSlide(IDocument& doc ,int n);
};

#endif //DOCUMENT_DIRECTOR_HPP
