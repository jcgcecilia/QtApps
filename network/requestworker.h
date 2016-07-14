#ifndef REQUESTWORKER_H
#define REQUESTWORKER_H

#include <QObject>
#include <QTimer>

class DataRequest;
class NetworkManager;

class RequestWorker : public QObject
{
    Q_OBJECT

public:
    explicit RequestWorker(DataRequest *_request = NULL, NetworkManager * manager = NULL);
    virtual ~RequestWorker();

   virtual void execute() = 0;

    QByteArray getData() const;
    void setData(const QByteArray &value);

    void setTimeout(int timeout);

    DataRequest *getInputrequest() const;
    void setInputrequest(DataRequest *value);


    bool isBeingUsed() const;
    void setIsBeingUsed(bool isBeingUsed);

    bool isDeletable() const;
    void setIsDeletable(bool isDeletable);

signals:
    void executionFinished(RequestWorker *);
    void executionFinished(QByteArray);
    void workerDone(DataRequest *);

public slots:
    virtual void done() = 0;

private slots:
    virtual void finish() = 0;

protected:
    QTimer timer;
    QByteArray data;
    DataRequest * inputrequest;
    bool mIsBeingUsed;
    bool mIsDeletable;
    NetworkManager * m_manager;
};

#endif // REQUESTWORKER_H
