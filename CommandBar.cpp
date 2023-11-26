#include "CommandBar.hpp"
#include <QKeyEvent>

CommandBar::CommandBar(QWidget* parent) : QLineEdit(parent)
{
}
void CommandBar::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()){
        case Qt::Key_Enter:
            emit commandEntered(this->text());
            clear();
            break;
        case Qt::Key_Return:
            emit commandEntered(this->text());
            clear();
            break;
        default:
            QLineEdit::keyPressEvent(event);
    }
}
