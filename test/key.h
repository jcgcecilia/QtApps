#ifndef KEY_H
#define KEY_H

#include <QWidget>

namespace Ui {
class Key;
}

class Key : public QWidget
{
    Q_OBJECT

public:
    explicit Key(QWidget *parent = 0);
    ~Key();

private:
    Ui::Key *ui;
};

#endif // KEY_H
