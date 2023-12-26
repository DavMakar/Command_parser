#include "LoadCommand.hpp"
#include <QFile>
#include <QIODevice>
#include <QJsonDocument>
#include "../../Application.hpp"
#include "../../serializer/json/Deserializer.hpp"

LoadCommand::LoadCommand()
{
    m_arguments.initArgument("-path", "new.txt");
}

void LoadCommand::exec()
{
    auto filename = m_arguments.getArgument<std::string>("-path");
    QFile file(QString::fromStdString(filename));
    file.open(QIODevice::ReadOnly);
    QJsonDocument jsonDoc =  QJsonDocument::fromJson(file.readAll());
    file.close();
    
    Deserializer deserializer;
    auto newDoc =  deserializer.deserializeDocument(jsonDoc);

    Application::instance()->getDocument().swap(*newDoc);
    Application::instance()->getUiController().logOutput("loaded");
}

std::unique_ptr<Command> LoadCommand::clone() const
{
    return std::make_unique<LoadCommand>();
}
