#ifndef SLIDE_VIEW_WIDGET_HPP
#define SLIDE_VIEW_WIDGET_HPP

#include <QWidget>
class QStandardItemModel;
class QTreeView;

class SlideView : public QWidget{
    Q_OBJECT
public:
    SlideView(QWidget* parent = nullptr);

private:
    void updateDocumentTree();

signals:
    void signalExpanded(int);

public slots:
    void onExpanded(const QModelIndex &index);
    void onDocumentChanged();

private:
    QStandardItemModel* model;
};

#endif //SLIDE_VIEW_WIDGET_HPP
