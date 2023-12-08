#ifndef GO_SLIDE_ACTION_HPP
#define GO_SLIDE_ACTION_HPP

#include "Action.hpp"
#include <memory>

class Document;
class Slide;

class GoSlideAction : public Action{
public:
    GoSlideAction(Document& doc, size_t id);  
    void execute() override;
    void unexecute() override;
private:
    Document& m_doc;
    std::shared_ptr<Slide> m_currentSlide;
    size_t m_id;
};

#endif //GO_SLIDE_ACTION_HPP
