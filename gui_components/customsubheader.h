#ifndef CUSTOMSUBHEADER_H
#define CUSTOMSUBHEADER_H

#include <QObject>
#include <QWidget>

class CustomSubheader : public QWidget
{
    Q_OBJECT
public:
    explicit CustomSubheader(QWidget *parent = 0);
    ~CustomSubheader();

signals:

public slots:
};

#endif // CUSTOMSUBHEADER_H
