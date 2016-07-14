#ifndef BUSINESSDATAMODEL_H
#define BUSINESSDATAMODEL_H

#include <QObject>

class BusinessDataModel : public QObject
{
    Q_OBJECT
public:
    explicit BusinessDataModel(QObject *parent = 0);

signals:

public slots:
};

#endif // BUSINESSDATAMODEL_H
