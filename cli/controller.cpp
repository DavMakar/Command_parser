#include "controller.hpp"

void Controller::run(std::istream& input){
    auto command = creator.createCommand(input);
    command->exec();
}
