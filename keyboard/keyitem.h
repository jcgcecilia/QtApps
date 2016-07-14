#ifndef KEYITEM_H
#define KEYITEM_H

#include <QObject>
#include <QWidget>
#include <QString>
#include <QLabel>

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

#include <QEvent>

class KeyItem : public QLabel
{
    Q_OBJECT
public:
    explicit KeyItem(const QString &text, QWidget *parent = NULL);
    void setSelected(bool selected);

#ifdef TOUCH
protected:
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
#endif

signals:
    void keyBoardPressed(QString value);
private:
    QString m_text;
    QPixmap m_image;

};

#endif // KEYITEM_H
