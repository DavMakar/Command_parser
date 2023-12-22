#include "ActionHistory.hpp"
#include "actions/Action.hpp"

void ActionHistory::push(std::unique_ptr<Action> action)
{
    redoList.clear();

    undoList.push_back(std::move(action));
}

void ActionHistory::undo()
{
    if (!undoList.empty()) {
        auto it = --undoList.end();
        auto action = std::move(*it);
        undoList.erase(it);
        action->unexecute();
        redoList.push_back(std::move(action));
    }
}

void ActionHistory::redo(){
    if (!redoList.empty()) {
        auto it = --redoList.end(); 
        auto action = std::move(*it);
        redoList.erase(it);
        action->execute();
        undoList.push_back(std::move(action));
    }
}
