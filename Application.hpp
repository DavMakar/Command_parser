#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <QApplication>
#include "director/Director.hpp"
#include "document/Document.hpp"
#include "cli/controller.hpp"
#include "gui/UiController.hpp"
#include "rendering/Renderer.hpp"

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
    Renderer& getRenderer(){
        return m_renderer;
    }

    UiController& getUiController(){
        return m_uiController;
    }

private:
    Director m_director;
    Document m_document;
    Controller m_controller;
    UiController m_uiController;
    Renderer m_renderer;
};

#endif // APPLICATION_HPP
