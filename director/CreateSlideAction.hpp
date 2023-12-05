#ifndef CREATE_SLIDE_ACTION_HPP
#define CREATE_SLIDE_ACTION_HPP

#include "Action.hpp"
#include <memory>

class Document;

class CreateSlideAction : public Action{
public:
    CreateSlideAction(size_t& currentIdx ,std::shared_ptr<Document> document );
    void execute() override;
    void unexecute() override;
private:
    std::shared_ptr<Document> m_doc;
    size_t& m_currentIdx;
};

#endif //CREATE_SLIDE_ACTION_HPP