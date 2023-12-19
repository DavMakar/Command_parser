#ifndef MainWindow_HPP
#define MainWindow_HPP

#include <QMainWindow>

class QAction;
class ItemsToolBar;
class WorkingArea;
class CommandWidget;
class SlideView; 

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    QString command;
    //QImage image;
    //QLabel* slideView;
    SlideView* slideView;
    WorkingArea* workingArea;
    ItemsToolBar* itemsTb;
    CommandWidget* commandWidget;
};

#endif // MainWindow_HPP
