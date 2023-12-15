#include "PowerPoint.hpp"
#include "gui/view/ItemsToolBar.hpp"
#include "gui/view/CommandWidget.hpp"
#include "gui/view/WorkingArea.hpp"
#include "Application.hpp"

#include <exception>
#include <QToolBar>
#include <QVBoxLayout>
#include <QPixmap>
#include <QMessageBox>
#include <QLabel>

PowerPoint::PowerPoint(QWidget *parent)
    : QMainWindow{parent}
{
    setCentralWidget(new QWidget);
    itemsTb = new ItemsToolBar;
    addToolBar(Qt::TopToolBarArea, itemsTb);

    slideView = new WorkingArea;
    commandWidget = new CommandWidget;

    QVBoxLayout* vLayout = new QVBoxLayout;
    vLayout->addWidget(slideView);
    vLayout->addWidget(commandWidget);
    centralWidget()->setLayout(vLayout);

    //connect(workingArea, &WorkingArea::clickedCoord,this, &PowerPoint::handlePoints);
    //connect(itemsTb, &ItemsToolBar::actionTriggered, this, &PowerPoint::handleToolBarActions);
    connect(commandWidget, &CommandWidget::commandEntered, &Application::instance()->getUiController(), &UiController::runCommand);
    connect(&Application::instance()->getUiController(), &UiController::logOutputSignal ,commandWidget, &CommandWidget::logCommand);
}


// void PowerPoint::handleToolBarActions(QAction *action)
// {
//         command.append("add -name ");
//         if(action->text() == "1"){
//             command.append("Rect");
//             workingArea->setClickCount(2);
//         }
//         else if(action->text() == "2"){
//             command.append("Circle");
//             workingArea->setClickCount(2);
//         }
//         else if(action->text() == "3"){
//             command.append("Line");
//             workingArea->setClickCount(2);
//         }
//         else if(action->text() == "4"){
//             command.append("Text");
//             workingArea->setClickCount(1);
//         }
// }

