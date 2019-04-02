#include "masterthread.h"

#include <QSerialPort>
#include <QTime>

MasterThread::MasterThread(QObject *parent) :
    QThread(parent)
{
}

void MasterThread::start(XYSeriesIODevice* device)
{
    m_device = device;
    QThread::start();
}

MasterThread::~MasterThread()
{

}

void MasterThread::run()
{


}
