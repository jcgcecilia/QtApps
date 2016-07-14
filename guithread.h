#ifndef GUITHREAD_H
#define GUITHREAD_H

#include <QWidget>
#include <QThread>

class GuiThread : public QWidget
{
    Q_OBJECT

public:
    explicit GuiThread();
    void setUp(QThread &cThread);

signals:

public slots:
    void StartGui();
};

#endif // GUITHREAD_H
