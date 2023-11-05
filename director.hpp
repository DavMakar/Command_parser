#ifndef DOCUMENT_DIRECTOR_HPP
#define DOCUMENT_DIRECTOR_HPP

#include "item.hpp"
#include "./document/idocument.hpp"
#include "./serializer/serializer.hpp"

class Director{
public:
    void addSlide(IDocument& doc);
    void addItemToSlide(IDocument& doc , std::unique_ptr<Item> newItem);
    void addItemToSlide(IDocument& doc , std::unique_ptr<Item> newItem , int slideId);
    void removeItemFromSlide(IDocument& doc , int itemId);
    void changeCurrentSlide(IDocument& doc ,int n);
    void saveDocument(IDocument& doc, const std::string& filename);
    void loadDocument(IDocument& doc, const std::string& filename);
private:
    Serializer serialzer_;
};

#endif //DOCUMENT_DIRECTOR_HPP
