#include "WorkingArea.hpp"
#include "../../Application.hpp"
#include <QPaintEvent>
#include <QPainter>

WorkingArea::WorkingArea(QWidget *parent)
    : QWidget{parent}
{
    setMinimumSize(200,300);
}

void WorkingArea::paintEvent(QPaintEvent *event)
{
    auto currentSlide = Application::instance()->getDocument().getCurrentSlide();
    QImage image(size(), QImage::Format_ARGB32_Premultiplied);

    Application::instance()->getRenderer().draw(currentSlide,&image);

    QPainter widgetPainter(this);
    widgetPainter.drawImage(0, 0, image);
}

void WorkingArea::onDocumnetChanged()
{
    qDebug() << "apo";
    this->update();
}
// void WorkingArea::setClickCount(int n)
// {
//     clickCount = n;
// }

// void WorkingArea::mousePressEvent(QMouseEvent *event)
// {
//     if(clickCount > 0){
//         if(event->button() == Qt::LeftButton){
//             --clickCount;
//             emit clickedCoord(event->pos());
//         }
//     }
// }
