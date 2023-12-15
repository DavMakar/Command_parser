#include "CommandWidget.hpp"
#include <QVBoxLayout>
#include <sstream>

CommandWidget::CommandWidget(QWidget *parent)
    : QWidget(parent)
{
    commandLine = new QLineEdit;
    commandLog = new CommandLog;

    QVBoxLayout* layout = new QVBoxLayout; 
    layout->addWidget(commandLine);
    layout->addWidget(commandLog);
    setLayout(layout);

    connect(commandLine, &QLineEdit::returnPressed, this, &CommandWidget::executeCommand);
}

void CommandWidget::executeCommand(){
    std::istringstream iss{commandLine->text().toStdString()};
    emit commandEntered(iss);
    commandLine->clear();
}

void CommandWidget::logCommand(const std::string& output){
    commandLog->append(QString::fromStdString(output));
}
