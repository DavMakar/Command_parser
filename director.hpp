#ifndef DOCUMENT_DIRECTOR_HPP
#define DOCUMENT_DIRECTOR_HPP

#include "item.hpp"
#include "./document/document.hpp"
#include "./serializer/serializer.hpp"

class Director{
public:
    void addSlide(Document& doc);
    void addItemToSlide(Document& doc , std::unique_ptr<Item> newItem);
    void addItemToSlide(Document& doc , std::unique_ptr<Item> newItem , int slideId);
    void removeItemFromSlide(Document& doc , int itemId);
    void changeCurrentSlide(Document& doc ,int n);
    void saveDocument(Document& doc, const std::string& filename);
    void loadDocument(Document& doc, const std::string& filename);
private:
    Serializer serialzer_;
};

#endif //DOCUMENT_DIRECTOR_HPP
