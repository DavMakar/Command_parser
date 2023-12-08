#include "ActionHistory.hpp"
#include "actions/Action.hpp"

void ActionHistory::push(std::unique_ptr<Action> action)
{
    m_history.push_back(std::move(action));
    historyIter = std::prev(m_history.end());
}

void ActionHistory::undo()
{
    if(historyIter != m_history.begin()){
        (*historyIter)->unexecute();
        --historyIter;
    }
}

void ActionHistory::redo(){
    if(historyIter != std::prev(m_history.end())){
        ++historyIter;
        (*historyIter)->execute();
    }
}
