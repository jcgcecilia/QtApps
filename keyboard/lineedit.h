#ifndef LINEEDIT_H
#define LINEEDIT_H
#include <QLineEdit>
#include <QKeyEvent>

class LineEdit : public QLineEdit
{
    Q_OBJECT
public:
    LineEdit( QWidget * parent);
    ~LineEdit();

public slots:
     void pressKey(QString text);

private:
//    QPixmap *mNormal;
    QString mText;
};

#endif // LINEEDIT_H
