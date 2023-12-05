#include "CreateSlideAction.hpp"
#include "../document/Document.hpp"

CreateSlideAction::CreateSlideAction(size_t& currentIdx,std::shared_ptr<Document> document)
    : m_currentIdx(currentIdx), m_doc(document)
{
}

void CreateSlideAction::execute()
{
    size_t slideIdx = m_doc->addSlide();
    m_currentIdx = slideIdx;
}

void CreateSlideAction::unexecute(){
    m_doc->deleteSlide(m_currentIdx);
    --m_currentIdx;
}
