#include "WorkingArea.hpp"
#include "../../Application.hpp"
#include <QPaintEvent>
#include <QPainter>
#include <QLabel>

WorkingArea::WorkingArea(QWidget *parent)
    : QWidget{parent}
{
    setMinimumSize(550,400);
}

void WorkingArea::paintEvent(QPaintEvent *event)
{

    auto currentSlide = Application::instance()->getDocument().getCurrentSlide();
    QImage image(size(), QImage::Format_ARGB32_Premultiplied);

    Application::instance()->getRenderer().draw(currentSlide,&image);

    QPainter widgetPainter(this);
    widgetPainter.drawRect(rect());
    widgetPainter.drawImage(0, 0, image);
}

void WorkingArea::onDocumentChanged()
{
    this->update();
}
