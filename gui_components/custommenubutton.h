#ifndef CUSTOMMENUBUTTON_H
#define CUSTOMMENUBUTTON_H

#include <QObject>
#include <QLabel>
#include <QLayout>
#include <QColor>
#include "screenscontainer.h"
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

class CustomButton : public QLabel
{
    Q_OBJECT

public:
    explicit CustomButton(QWidget *parent = 0);
    virtual ~CustomButton();
    virtual void setSelected(bool selected, bool signal) = 0;

protected:
    QPalette palette1;
};


class CustomMenuButton : public CustomButton
{
    Q_OBJECT

public:
    explicit CustomMenuButton(QWidget *parent = 0, ScreensContainer::ScreenId id = ScreensContainer::notAssigned);
    ~CustomMenuButton();

    /**
     * @brief setText
     * @param text
     */
    void setText(const QString &text);

    /**
     * @brief setImage
     * @param image
     */
    void setImage(const QPixmap &image);

    bool selected() const;
    void setSelected(bool selected, bool signal = false);


    ScreensContainer::ScreenId id() const;
    void setId(const ScreensContainer::ScreenId &id);

#ifdef TOUCH
protected:
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
#endif

signals:
     void buttonClicked(ScreensContainer::ScreenId);

public slots:

private:
    QLabel *m_image;
    QLabel *m_text;
    QVBoxLayout *m_layout;
    bool m_selected;
    ScreensContainer::ScreenId m_id;
};

#endif // CUSTOMMENUBUTTON_H
