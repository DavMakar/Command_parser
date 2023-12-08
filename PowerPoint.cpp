#include "PowerPoint.hpp"
#include "view/WorkingArea.hpp"
#include "view/ItemsToolBar.hpp"
#include "Application.hpp"

#include <exception>
#include <QToolBar>
#include <QVBoxLayout>
#include <QPixmap>
#include <QMessageBox>

PowerPoint::PowerPoint(QWidget *parent)
    : QMainWindow{parent}
{
    setCentralWidget(new QWidget);
    itemsTb = new ItemsToolBar;
    addToolBar(Qt::TopToolBarArea, itemsTb);

    workingArea = new WorkingArea;
    CommandBar* commandBar = new CommandBar;
    CommandLog* commandLog = new CommandLog;

    QVBoxLayout* vLayout = new QVBoxLayout;
    vLayout->addWidget(workingArea);
    vLayout->addWidget(commandBar);
    vLayout->addWidget(commandLog);
    centralWidget()->setLayout(vLayout);

    //connect(workingArea, &WorkingArea::clickedCoord,this, &PowerPoint::handlePoints);
    connect(itemsTb, &ItemsToolBar::actionTriggered, this, &PowerPoint::handleToolBarActions);
    connect(commandBar, &CommandBar::commandEntered, this, &PowerPoint::execute);
    connect(&Application::instance()->getController(),&Controller::outputLoged , commandLog, &CommandLog::logCommand);
}

void PowerPoint::execute(std::istream& input)
{
    try{
        Application::instance()->getController().run(input);
    }catch(const std::exception& e){
        Application::instance()->getController().logOutput(e.what());
    }
}

void PowerPoint::handleToolBarActions(QAction *action)
{
        command.append("add -name ");
        if(action->text() == "1"){
            command.append("Rect");
            workingArea->setClickCount(2);
        }
        else if(action->text() == "2"){
            command.append("Circle");
            workingArea->setClickCount(2);
        }
        else if(action->text() == "3"){
            command.append("Line");
            workingArea->setClickCount(2);
        }
        else if(action->text() == "4"){
            command.append("Text");
            workingArea->setClickCount(1);
        }
}

