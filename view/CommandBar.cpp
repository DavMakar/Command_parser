#include "CommandBar.hpp"
#include <QKeyEvent>
#include <sstream>

CommandBar::CommandBar(QWidget* parent) : QLineEdit(parent)
{
}
void CommandBar::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return){
        std::istringstream iss{this->text().toStdString()};
        emit commandEntered(iss);
        clear();
    }
    else{
        QLineEdit::keyPressEvent(event);        
    }
}
