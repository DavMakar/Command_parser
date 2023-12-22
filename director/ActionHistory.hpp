#ifndef ACTION_HISTORY_HPP
#define ACTION_HISTORY_HPP

#include <list>
#include <memory>

#include "actions/Action.hpp"

class ActionHistory{
    using ActionList = std::list<std::unique_ptr<Action>>;
public:
    void push(std::unique_ptr<Action> action);
    void undo();
    void redo();
    
private:
    ActionList undoList;
    ActionList redoList;
};
#endif //ACTION_HISTORY_HPP 
