#include "CreateSlideAction.hpp"
#include "../../document/Document.hpp"

CreateSlideAction::CreateSlideAction(Document& document)
    : m_doc(document)
{
}

void CreateSlideAction::execute()
{
    m_addedSlideId = m_doc.addSlide();
}

void CreateSlideAction::unexecute(){
    m_doc.deleteSlide(m_addedSlideId);
}
