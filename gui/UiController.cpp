#include "UiController.hpp"
#include "../Application.hpp"
#include <stdexcept>

void UiController::runCommand(std::istream &input)
{
    try{
        Application::instance()->getController().run(input);
    }catch(const std::exception& e){
        emit logOutputSignal(e.what());
    }
}

void UiController::logOutput(const std::string& message){
    emit logOutputSignal(message);
}