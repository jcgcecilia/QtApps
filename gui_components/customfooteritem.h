#ifndef CUSTOMFOOTERITEM_H
#define CUSTOMFOOTERITEM_H

#include <QObject>
#include <QLabel>
#include "screen.h"
class CustomComboBox;

class CustomFooterItem : public QLabel
{
    Q_OBJECT

public:
    CustomFooterItem(int col, QWidget * parent = 0);
    ~CustomFooterItem();
    virtual void popUp();

    void setComboBox(CustomComboBox *comboBox);

signals:
    void footerClicked(int col);

protected:
#ifdef TOUCH
    void mouseReleaseEvent(QMouseEvent *);
#endif
private:
    int m_col;
    CustomComboBox * m_comboBox;
    bool m_comboVisible;
};

#endif // CUSTOMFOOTERITEM_H
