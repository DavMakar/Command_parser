#include "controller.hpp"

void Controller::run(std::istream& input){
    auto command = creator.createCommand(input);
    auto result = command->exec();
    logOutput(result);
}

void Controller::logOutput(const std::string& output)
{
    emit outputLoged(output);
}