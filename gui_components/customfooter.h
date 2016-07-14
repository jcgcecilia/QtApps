#ifndef CUSTOMFOOTER_H
#define CUSTOMFOOTER_H

#include <QObject>
#include <QWidget>
#include <QLayout>
#include "screen.h"

class CustomFooterItem;
class CustomComboBox;

class CustomFooter : public QWidget
{
    Q_OBJECT

public:
    explicit CustomFooter(Screen *parent = 0);
    ~CustomFooter();
    void initialize();
    void setText(int col, const QString &text, bool active = true);
    void setImage(int col, const QPixmap &image, bool active = true);
    void setComboBox(int col,CustomComboBox * combo , bool active = true);
    void updateFooterItem(int col, bool visible = true);
    bool isItemEnabled(int col);

signals:
    void footerItemSelected(int col);

protected:
#ifdef KEYS
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);
#endif
private slots:

private:

    QHBoxLayout * m_horizontalLayout;
    QList<CustomFooterItem *> footerItems;
    Screen * m_parentScreen;
};

#endif // CUSTOMFOOTER_H
