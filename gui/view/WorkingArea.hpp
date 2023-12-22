#ifndef WORKING_AREA_HPP
#define WORKING_AREA_HPP

#include <QWidget>
#include <QList>

class QLabel;
class QScrollArea;

class WorkingArea : public QWidget
{
    Q_OBJECT
public:
    explicit WorkingArea(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent* event);

public slots:
    void onDocumentChanged();
};

#endif // WORKING_AREA_HPP
