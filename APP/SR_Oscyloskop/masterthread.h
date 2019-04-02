#ifndef MASTERTHREAD_H
#define MASTERTHREAD_H

#include <QThread>
#include "xyseriesiodevice.h"
class MasterThread : public QThread
{
    Q_OBJECT

public:
    explicit MasterThread(QObject *parent = nullptr);
    ~MasterThread();

    void start(XYSeriesIODevice* device);
signals:
    void response(const QString &s);
    void error(const QString &s);

private:
    void run() override;

    XYSeriesIODevice* m_device;
};

#endif // MASTERTHREAD_H
