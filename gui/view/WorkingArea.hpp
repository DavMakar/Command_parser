#ifndef WORKING_AREA_HPP
#define WORKING_AREA_HPP

#include <QWidget>
#include <QList>

class WorkingArea : public QWidget
{
    Q_OBJECT
public:
    explicit WorkingArea(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent* event);

public slots:
    void onDocumentChanged();
// signals:
//     void clickedCoord(QPoint point);
// protected:
//     void mousePressEvent(QMouseEvent* event);

private:
    int clickCount = 0;
};

#endif // WORKING_AREA_HPP
