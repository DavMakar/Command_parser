#ifndef POWERPOINT_HPP
#define POWERPOINT_HPP

#include <QMainWindow>
#include "cli/controller.hpp"
#include "view/CommandLog.hpp"
#include "view/CommandBar.hpp"

class QAction;
class ItemsToolBar;
class WorkingArea;

class PowerPoint : public QMainWindow
{
    Q_OBJECT
public:
    explicit PowerPoint(QWidget *parent = nullptr);

private slots:
    void execute(std::istream& input);
    void handleToolBarActions(QAction* action);
    //void handlePoints(QPoint p);
private:
    QString command;
    ItemsToolBar* itemsTb;
    WorkingArea* workingArea;
    Controller* controller;
};

#endif // POWERPOINT_HPP
