#ifndef CUSTOMCOMBOBOX_H
#define CUSTOMCOMBOBOX_H

#include <QObject>
#include <QWidget>
#include "gui_components/custommenubutton.h"
#include "gui_components/customgrid.h"

class QLabel;

class CustomComboBoxItem: public CustomButton
{
    Q_OBJECT
 public:
    CustomComboBoxItem(int _id, QWidget  * parent);
    ~CustomComboBoxItem();
//    void setText(const QString &);
    virtual void setSelected(bool selected, bool signal);

protected:
#ifdef TOUCH
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseDoubleClickEvent(QMouseEvent *);
#endif

signals:
    void selectioItemPressed(int _id);

 private:
    int m_id;
};

class CustomComboBox : public QWidget
{
    Q_OBJECT

public:
    CustomComboBox(QWidget * parent);
//    void showPopup();

    void init();
    void addMenuItem(CustomComboBoxItem *item, int row);
protected:
    void showEvent(QShowEvent *);
    void hideEvent(QHideEvent *);
#ifdef KEYS
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);
#endif

private:
    CustomGrid m_selectionListContainer;
};

#endif // CUSTOMCOMBOBOX_H
