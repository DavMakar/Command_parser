#include "UiController.hpp"
#include "../Application.hpp"
#include <stdexcept>

void UiController::runCommand(std::istream &input)
{
    try{
        Application::instance()->getController().run(input);
        //QUESTION cli controller only cals once
    }catch(const std::exception& e){
        emit logOutputSignal(e.what());
    }
}

void UiController::logOutput(const std::string& message){
    emit logOutputSignal(message);
}