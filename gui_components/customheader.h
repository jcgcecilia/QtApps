#ifndef CUSTOMHEADER_H
#define CUSTOMHEADER_H

#include <QObject>
#include <QWidget>
#include <QLayout>
#include <QLabel>

class CustomHeader : public QWidget
{
    Q_OBJECT

public:
    explicit CustomHeader(QWidget *parent = 0);
    ~CustomHeader();

signals:

public slots:
    void updateHeaderText(int text);

private:
    QHBoxLayout * m_horizontalLayout;
    QWidget * m_icons;
    QLabel * m_headerText;

};

#endif // CUSTOMHEADER_H
