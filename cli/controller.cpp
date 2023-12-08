#include "controller.hpp"

void Controller::run(std::istream& input){
    auto command = creator.CreateSlideCommand(input);
    command->exec();
}

void Controller::logOutput(const std::string& output)
{
    emit outputLoged(output);
}