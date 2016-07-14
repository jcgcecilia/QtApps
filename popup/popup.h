#ifndef POPUP_H
#define POPUP_H

#include <QObject>
#include <QWidget>

class ScreensContainer;
class QVBoxLayout;

class PopUp : public QWidget
{
    Q_OBJECT
    QVBoxLayout* verticalLayout;
public:
    explicit PopUp(ScreensContainer *parent = 0);

signals:

protected:
    void showEvent(QShowEvent *ev);
    void hideEvent(QHideEvent *ev);
#ifdef KEYS
    void keyReleaseEvent(QKeyEvent *);
#endif
#ifdef TOUCH
    void mouseReleaseEvent(QMouseEvent *);
#endif
public slots:
    void showPopUp(QString text1, QString text2, QString text3);
    void showPopup(int id);
    void hidePopUp();

};

#endif // POPUP_H
