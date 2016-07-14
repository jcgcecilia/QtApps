#ifndef POPUPBUTTON_H
#define POPUPBUTTON_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include "gui_components/screenscontainer.h"

class PopupButton : public QLabel
{
    Q_OBJECT
public:
    explicit PopupButton(QWidget *parent = 0);
    void setSelected(bool selected);

    ScreensContainer::ScreenId pointerToScreen() const;
    void setPointerToScreen(const ScreensContainer::ScreenId &pointerToScreen);

#ifdef TOUCH
protected:
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
#endif

signals:
    void buttonClicked(ScreensContainer::ScreenId);

public slots:

private:
    ScreensContainer::ScreenId m_pointerToScreen;
    bool m_selected;
};

#endif // POPUPBUTTON_H
