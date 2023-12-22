#include "SaveCommand.hpp"
#include "../../Application.hpp"
#include "../../serializer/json/Serializer.hpp"
#include <QJsonDocument>
#include <QFile>
#include <QIODevice>

SaveCommand::SaveCommand()
{
    m_arguments.initArgument("-path","new.txt");
}

void SaveCommand::exec()
{
    auto filename = m_arguments.getArgument<std::string>("-path");
    Serializer serializer;
    QJsonDocument jsonDoc;
    serializer.serializeDocument(Application::instance()->getDocument(),jsonDoc);

    QFile file(QString::fromStdString(filename));
    file.open(QIODevice::WriteOnly);
    file.write(jsonDoc.toJson(QJsonDocument::Indented));
    file.close();
    //Application::instance()->getDirector().saveDocument(Application::instance()->getDocument(), serializer);
    Application::instance()->getUiController().logOutput("save");
}

std::unique_ptr<Command> SaveCommand::clone() const{
    return std::make_unique<SaveCommand>();
}
