#include "WorkingArea.hpp"
#include <QMouseEvent>

WorkingArea::WorkingArea(QWidget *parent)
    : QWidget{parent}
{
    setMinimumSize(200,300);
}

void WorkingArea::setClickCount(int n)
{
    clickCount = n;
}

void WorkingArea::mousePressEvent(QMouseEvent *event)
{
    if(clickCount > 0){
        if(event->button() == Qt::LeftButton){
            --clickCount;
            emit clickedCoord(event->pos());
        }
    }
}
