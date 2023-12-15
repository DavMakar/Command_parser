#ifndef ACTION_HISTORY_HPP
#define ACTION_HISTORY_HPP

#include <vector>
#include <memory>

class Action;

class ActionHistory{
    using ActionContainer = std::vector<std::shared_ptr<Action>>;
    using ActionIter = ActionContainer::iterator;
public:
    void push(std::unique_ptr<Action> action);
    void undo();
    void redo();
    
private:
    ActionContainer m_history;
    ActionIter historyIter;
};
#endif //ACTION_HISTORY_HPP
