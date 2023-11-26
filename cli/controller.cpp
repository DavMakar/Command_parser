#include "controller.hpp"

void Controller::run(const QString& input){
    auto inputTokens = tokenizer.splitInput(input);
    std::string commandName = inputTokens.front();
    auto command = creator.createCommand(commandName,
                                        {std::next(inputTokens.begin()),inputTokens.end()});
    auto result = command->exec();
    logOutput(result);
}

void Controller::logOutput(const std::string& output)
{
    emit outputLoged(output);
}
