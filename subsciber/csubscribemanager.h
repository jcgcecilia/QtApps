#ifndef CSUBSCRIBEMANAGER_H
#define CSUBSCRIBEMANAGER_H

#include <QObject>

class CSubscribeManager : public QObject
{
    Q_OBJECT
public:
    explicit CSubscribeManager(QObject *parent = 0);

signals:

public slots:
};

#endif // CSUBSCRIBEMANAGER_H