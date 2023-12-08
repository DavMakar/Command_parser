#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <QApplication>
#include "director/Director.hpp"
#include "document/Document.hpp"
#include "cli/controller.hpp"

class Application : public QApplication{
public: 
    static Application* instance()
    {
        return dynamic_cast<Application*>(QApplication::instance());
    }

    Application(int argc, char** argv)
    :QApplication(argc,argv){
        m_document.init();
        setApplicationName("PowerPoint");
    }

    int exec(){
        return QApplication::exec();   
    }
    void quit(){
        QApplication::quit();
    }

    Document& getDocument(){
        return m_document;
    }

    Director& getDirector(){
        return m_director;
    }

    Controller& getController(){
        return m_controller;
    }

private:
    Director m_director;
    Document m_document;
    Controller m_controller;
};

#endif // APPLICATION_HPP
