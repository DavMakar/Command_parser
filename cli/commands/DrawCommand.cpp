#include "DrawCommand.hpp"
#include "../../Application.hpp"
#include "../../rendering/Renderer.hpp"
#include <QImage>
#include <QFile>

void DrawCommand::exec()
{
    auto currentSlide = Application::instance()->getDocument().getCurrentSlide(); 
    Renderer r;
    //QFile filename("img.png");
    QImage img(200,100, QImage::Format_ARGB32_Premultiplied);
    r.draw(currentSlide,&img);
    //img.save(&filename);
    Application::instance()->getController().logOutput("draw slide");   
}

std::unique_ptr<Command> DrawCommand::clone() const
{
    return std::make_unique<DrawCommand>();
}
