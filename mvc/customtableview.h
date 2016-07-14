#ifndef CUSTOMTABLEVIEW_H
#define CUSTOMTABLEVIEW_H

#include <QObject>
#include <QTableView>
#include <QStyledItemDelegate>
#include <QPainter>

#define C_BLACK QColor(0,0,0)
#define C_WHITE QColor(255,255,255)
#define C_LIGHTBLUE QColor(0,141,210)
#define C_DEIFBLUE QColor(0,77,143)
#define C_DEEPGREY QColor(80,87,94)
#define C_LIGHTGREY QColor(245,245,245)
#define C_LIGHTGREY2 QColor(229,229,229)
#define C_DARKGREY QColor(192,193,195)
#define C_YELLOW QColor(255,237,0)
#define C_ORANGE QColor(239,127,26)
#define C_GREEN QColor(0,152,70)
#define C_LIME QColor(176,203,31)
#define C_RED QColor(227,30,36)
#define C_DARKRED QColor(220,0,0)

class QStyledItemDelegate;
class CustomTableView : public QTableView
{
    Q_OBJECT

public:
    CustomTableView(QWidget *parent = 0);
    void setColsWidth(const QList<int> &colsWidth);
    void scrollUp();
    void scrollDown();
    void setDelegate(int col, QStyledItemDelegate * delegate);
protected:
    void mouseReleaseEvent(QMouseEvent * event);

private slots:
    void enteredRow(const QModelIndex &index);
    void selectedRow(const QModelIndex &index);

signals:
  void enteredRow(int);
  void selectedRow(int);


private:


};

#endif // CUSTOMTABLEVIEW_H
