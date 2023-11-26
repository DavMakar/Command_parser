#ifndef COMMANDBAR_HPP
#define COMMANDBAR_HPP

#include <QLineEdit>

class QKeyEvent;

class CommandBar : public QLineEdit
{
    Q_OBJECT

public:
    CommandBar(QWidget *parrent = nullptr);

protected:
    void keyPressEvent(QKeyEvent* event) override;

signals:
    void commandEntered(const QString& line);
};

#endif // COMMANDBAR_HPP