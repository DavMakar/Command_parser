#include "LoadCommand.hpp"
#include <QFile>
#include <QIODevice>
#include <QJsonDocument>
#include "../../Application.hpp"
//#include "../../serializer/TxtDeserializer.hpp"
#include "../../serializer/json/Deserializer.hpp"

LoadCommand::LoadCommand()
{
    m_arguments.initArgument("-file", "new.txt");
}

void LoadCommand::exec()
{
    auto filename = m_arguments.getArgument<std::string>("-file");
    QFile file(QString::fromStdString(filename));
    file.open(QIODevice::ReadOnly);
    QJsonDocument jsonDoc =  QJsonDocument::fromJson(file.readAll());
    
    Deserializer deserializer;
    auto newDoc =  deserializer.deserializeDocument(jsonDoc);

    Application::instance()->getDocument().swap(*newDoc);
    //Application::instance()->getDirector().loadDocument(Application::instance()->getDocument(),deserializer);
    Application::instance()->getUiController().logOutput("loaded");
}

std::unique_ptr<Command> LoadCommand::clone() const
{
    return std::make_unique<LoadCommand>();
}
