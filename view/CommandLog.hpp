#ifndef COMMANDLOG_HPP
#define COMMANDLOG_HPP

#include <QTextEdit>

class CommandLog : public QTextEdit
{
    Q_OBJECT
public:
    CommandLog(QWidget* parrent = nullptr);

public slots:
    void logCommand(const std::string& output);
};

#endif // COMMANDLOG_HPP
