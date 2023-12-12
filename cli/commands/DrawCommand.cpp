#include "DrawCommand.hpp"
#include "../../Application.hpp"
#include "../../rendering/Renderer.hpp"
#include <QImage>
#include <QFile>

void DrawCommand::exec()
{
    auto currentSlide = Application::instance()->getDocument().getCurrentSlide(); 
    QFile filename("C:/Users/Davit/Desktop/CourseWorks/PowerPoint/Command_parser/img.png");
    QImage img(1336,768, QImage::Format_ARGB32_Premultiplied);
    Application::instance()->getRenderer().draw(currentSlide,&img);
    img.save(&filename,"PNG");
    Application::instance()->getUiController().logOutput("draw slide");   
}

std::unique_ptr<Command> DrawCommand::clone() const
{
    return std::make_unique<DrawCommand>();
}
