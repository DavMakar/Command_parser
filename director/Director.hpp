#ifndef DOCUMENT_DIRECTOR_HPP
#define DOCUMENT_DIRECTOR_HPP
#include "ActionHistory.hpp"
#include <memory>

class TxtSerializer;
class TxtDeserializer;
class Document;
class Action;

class Director {
public:
    void runAction(std::unique_ptr<Action> action);
    void undoAction();
    void redoAction();
    //void changeItem(int itemId, const std::vector<std::string>& arguments);
    //TODO change argument type to Argument

    void saveDocument(Document& doc ,TxtSerializer& se);
    void loadDocument(Document& doc ,TxtDeserializer& de);

private:
    ActionHistory m_history;
};

#endif  // DOCUMENT_DIRECTOR_HPP
