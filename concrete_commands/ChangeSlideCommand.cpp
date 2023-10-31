#include "ChangeSlideCommand.hpp"

std::string ChangeSlideCommand::exec(Document &doc)
{
    auto id = *std::next(arguments_.begin());
    doc.changeCurrentSlide(std::stoi(id));
    return "slide changed"; //TODO return from changeCurrentSlide
}

std::unique_ptr<Command> ChangeSlideCommand::clone() const
{
    return std::make_unique<ChangeSlideCommand>();
}
