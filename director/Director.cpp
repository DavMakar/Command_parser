#include "Director.hpp"
#include "actions/Action.hpp"
#include "../document/Document.hpp" //TODO 
#include "../serializer/TxtSerializer.hpp"
#include "../serializer/TxtDeserializer.hpp"

void Director::runAction(std::unique_ptr<Action> action)
{
    try{
        action->execute();
    }catch(const std::exception& e){
        throw std::runtime_error("Action incomplite");
    }
    m_history.push(std::move(action));
}

void Director::undoAction()
{
    m_history.undo();
}

void Director::redoAction()
{
    m_history.redo();
}

// void Director::changeItem(int itemId, const std::vector<std::string>& arguments)
// {
//     //auto item = doc.getSlide(currentSlide)->getItemById(itemId);
//     // for(auto it =  std::next(arguments.begin(),2); it != arguments.end(); it+=2){
//     //     item->setAttribute(*it,*std::next(it));
//     // }    
// }

void Director::saveDocument(Document& doc,TxtSerializer& se)
{
    se.visit(doc);
}

void Director::loadDocument(Document& doc,TxtDeserializer& de)
{
    Document newDoc;
    de.visit(newDoc);
    std::swap(doc,newDoc);
}
