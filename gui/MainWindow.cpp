#include "MainWindow.hpp"
#include "view/ItemsToolBar.hpp"
#include "view/CommandWidget.hpp"
#include "view/WorkingArea.hpp"
#include "view/SlideView.hpp"
#include "../Application.hpp"

#include <QToolBar>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSplitter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent}
{
    itemsTb = new ItemsToolBar;
    addToolBar(Qt::TopToolBarArea, itemsTb);

    workingArea = new WorkingArea;
    commandWidget = new CommandWidget;
    commandWidget->setFixedHeight(120);
    slideView = new SlideView;

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(workingArea);
    layout->addWidget(commandWidget);

    QHBoxLayout* mainLayout = new QHBoxLayout;
    mainLayout->addWidget(slideView);
    mainLayout->addLayout(layout);

    QWidget* mainWidget = new QWidget(this);
    mainWidget->setLayout(mainLayout);
    setCentralWidget(mainWidget);

    connect(commandWidget, &CommandWidget::commandEntered, &Application::instance()->getUiController(), &UiController::runCommand);
    connect(&Application::instance()->getUiController(), &UiController::signalDocumentChanged ,slideView, &SlideView::onDocumentChanged);
    connect(&Application::instance()->getUiController(), &UiController::signalDocumentChanged ,workingArea, &WorkingArea::onDocumentChanged);
    connect(&Application::instance()->getUiController(), &UiController::logOutputSignal ,commandWidget, &CommandWidget::logCommand);
}

