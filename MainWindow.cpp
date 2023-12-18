#include "MainWindow.hpp"
#include "gui/view/ItemsToolBar.hpp"
#include "gui/view/CommandWidget.hpp"
#include "gui/view/WorkingArea.hpp"
#include "Application.hpp"

#include <QToolBar>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent}
{
    setCentralWidget(new QWidget);
    itemsTb = new ItemsToolBar;
    addToolBar(Qt::TopToolBarArea, itemsTb);

    workingArea = new WorkingArea;
    commandWidget = new CommandWidget;

    QVBoxLayout* vLayout = new QVBoxLayout;
    vLayout->addWidget(workingArea);
    
    vLayout->addWidget(commandWidget);
    centralWidget()->setLayout(vLayout);

    //connect(workingArea, &WorkingArea::clickedCoord,this, &MainWindow::handlePoints);
    //connect(itemsTb, &ItemsToolBar::actionTriggered, this, &MainWindow::handleToolBarActions);
    
    connect(commandWidget, &CommandWidget::commandEntered, &Application::instance()->getUiController(), &UiController::runCommand);
    connect(&Application::instance()->getUiController(), &UiController::signalDocumentChanged ,workingArea, &WorkingArea::onDocumnetChanged);
    connect(&Application::instance()->getUiController(), &UiController::logOutputSignal ,commandWidget, &CommandWidget::logCommand);
}

