#ifndef COMMANDLOG_HPP
#define COMMANDLOG_HPP

#include <QTextEdit>

class CommandLog : public QTextEdit
{
    Q_OBJECT
public:
    CommandLog(QWidget* parrent = nullptr);
};

#endif // COMMANDLOG_HPP
