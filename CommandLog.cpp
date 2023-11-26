#include "CommandLog.hpp"
#include <QPalette>

CommandLog::CommandLog(QWidget *parrent): QTextEdit(parrent)
{
    this->setReadOnly(true);

    QPalette pal = this->palette();
    pal.setColor(QPalette::Base, Qt::black);
    pal.setColor(QPalette::Text, Qt::yellow);
    this->setPalette(pal);
}

void CommandLog::logCommand(const std::string& command)
{
    this->append(QString::fromStdString(command));
}
