#ifndef MainWindow_HPP
#define MainWindow_HPP

#include <QMainWindow>

class QAction;
class ItemsToolBar;
class WorkingArea;
class CommandWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

//private slots:
    //void handleToolBarActions(QAction* action);
    //void handlePoints(QPoint p);
private:
    QString command;
    //QImage image;
    //QLabel* slideView;
    WorkingArea* workingArea;
    ItemsToolBar* itemsTb;
    CommandWidget* commandWidget;
};

#endif // MainWindow_HPP
