#ifndef UI_CONTROLLER_HPP
#define UI_CONTROLLER_HPP

#include <iosfwd>
#include <QObject>

class UiController : public QObject{
    Q_OBJECT
public slots:
    void runCommand(std::istream& input);

public:
    void logOutput(const std::string& message);
    void documentChanged();
signals:
    void signalDocumentChanged();
    void logOutputSignal(const std::string& message);
};

#endif //UI_CONTROLLER_HPP