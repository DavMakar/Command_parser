#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <QApplication>
#include "director/Director.hpp"
#include "document/Document.hpp"
#include "cli/controller.hpp"

class Application : public QApplication{
public: 
    static Application& instance(int argc = 0 , char** argv = nullptr)
    {
        static Application app(argc,argv);
        return app;
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
    Application(int argc, char** argv)
    :QApplication(argc,argv){
        setApplicationName("PowerPoint");
    }

private:
    Director m_director;
    Document m_document;
    Controller m_controller;
};

#endif // APPLICATION_HPP