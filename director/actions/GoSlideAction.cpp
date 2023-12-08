#include "GoSlideAction.hpp"

#include "../../document/Document.hpp"

GoSlideAction::GoSlideAction(Document &doc, size_t id)
    : m_doc(doc), m_id(id)
{
    m_currentSlide = doc.getCurrentSlide(); 
}

void GoSlideAction::execute()
{
    m_doc.changeCurrentSlide(m_id);
}

void GoSlideAction::unexecute()
{
    m_doc.getCurrentSlide() = m_currentSlide;
}
