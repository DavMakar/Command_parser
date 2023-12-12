#ifndef COMMAND_WIDGET_HPP
#define COMMAND_WIDGET_HPP

#include <QWidget>
#include <QLineEdit>
#include "CommandLog.hpp"

class CommandWidget : public QWidget {
    Q_OBJECT
public:
    CommandWidget(QWidget* parent = nullptr);

signals:
    void commandEntered(std::istream& is);
public slots:
    void logCommand(const std::string& output);
private slots:
    void executeCommand();

private:
    QLineEdit* commandBar;
    CommandLog* commandLog;    
};

#endif //COMMAND_WIDGET_HPP