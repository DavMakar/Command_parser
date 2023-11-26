#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <QObject>
#include "commandCreator.hpp"
#include "tokenizer.hpp"

class Controller: public QObject{
   Q_OBJECT
public:    
    void run(const QString& input);
    void logOutput(const std::string& output);

signals:
    void outputLoged(const std::string& output);

private:
    Tokenizer tokenizer;
    CommandCreator creator;
};

#endif //CONTROLLER_HPP
