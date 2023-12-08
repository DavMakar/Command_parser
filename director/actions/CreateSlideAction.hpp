#ifndef CREATE_SLIDE_ACTION_HPP
#define CREATE_SLIDE_ACTION_HPP

#include "Action.hpp"
#include <memory>

class Document;

class CreateSlideAction : public Action{
public:
    CreateSlideAction(Document& document );
    void execute() override;
    void unexecute() override;
private:
    Document& m_doc;
    size_t m_addedSlideId;
};

#endif //CREATE_SLIDE_ACTION_HPP