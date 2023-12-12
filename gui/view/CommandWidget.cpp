#include "CommandWidget.hpp"
#include <QVBoxLayout>
#include <sstream>

CommandWidget::CommandWidget(QWidget *parent)
    : QWidget(parent)
{
    commandBar = new QLineEdit;
    commandLog = new CommandLog;

    QVBoxLayout* layout = new QVBoxLayout; 
    layout->addWidget(commandBar);
    layout->addWidget(commandLog);
    setLayout(layout);

    connect(commandBar, &QLineEdit::returnPressed, this, &CommandWidget::executeCommand);
}

void CommandWidget::executeCommand(){
    std::istringstream iss{commandBar->text().toStdString()};
    emit commandEntered(iss);
    commandBar->clear();
}

void CommandWidget::logCommand(const std::string& output){
    commandLog->append(QString::fromStdString(output));
}
