#ifndef POWERPOINT_HPP
#define POWERPOINT_HPP

#include <QMainWindow>

class QAction;
class ItemsToolBar;
class WorkingArea;
class CommandWidget;

class PowerPoint : public QMainWindow
{
    Q_OBJECT
public:
    explicit PowerPoint(QWidget *parent = nullptr);

//private slots:
    //void handleToolBarActions(QAction* action);
    //void handlePoints(QPoint p);
private:
    QString command;
    //QImage image;
    //QLabel* slideView;
    WorkingArea* slideView;
    ItemsToolBar* itemsTb;
    CommandWidget* commandWidget;
};

#endif // POWERPOINT_HPP
