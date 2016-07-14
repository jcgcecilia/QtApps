#ifndef CUSTOMSCROLLWIDGETS_H
#define CUSTOMSCROLLWIDGETS_H

#include <QObject>
#include <QWidget>
#include <QLayout>
#include <QScrollArea>

class CustomGrid;
class CustomButton;

class CustomScrollWidgets : public QWidget
{
    Q_OBJECT
public:
    explicit CustomScrollWidgets(QWidget *parent = 0);
    void addMenuItem(CustomButton *item, int row, int col);
    void resetGrid(int row = 0, int col = 0);
signals:

public slots:

private:
    QScrollArea *m_scrollArea;
    CustomGrid *m_contentGrid;
    QWidget *m_scrollAreaWidgetContents;
};

#endif // CUSTOMSCROLLWIDGETS_H
