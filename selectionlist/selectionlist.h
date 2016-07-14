#ifndef SELECTIONLIST_H
#define SELECTIONLIST_H

#include <QObject>
#include <QWidget>
#include "gui_components/customcombobox.h"


class SelectionList : public QWidget
{
    Q_OBJECT
public:
    explicit SelectionList(QWidget *parent = 0);
    void setComboBox(CustomComboBox *comboBox);
    void popUp();

protected:
#ifdef KEYS
/*    void keyPressEvent(QKeyEvent * ev);
    void keyReleaseEvent(QKeyEvent *ev)
*/;
#endif

#ifdef TOUCH
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
#endif
signals:

public slots:
    void selectionItemSelected(int id);

protected:
    CustomComboBox * m_comboBox;
    bool m_comboVisible;
//    CustomGrid m_selectionListContainer;
};

#endif // SELECTIONLIST_H
