#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
MainWindow::MainWindow(QSerialPort &port, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    layout(new QGridLayout(this)),
    display(new Display(this)),
    serialPort(&port)
{
    ui->setupUi(this);

    layout->addWidget(display);
    centralWidget()->setLayout(layout);

    timer = new QTimer(this);

    //connect(timer, SIGNAL(timeout()), this, SLOT(update_data()));
    //timer->start(10);

    connect(serialPort, SIGNAL(readyRead()), this, SLOT(readSerial()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_data()
{
    QVector<double> y;
    QVector<double> xt, yt;

    for(int i=0; i<500; i++){
    y.append(qSin(3.3*36.0*counter++/100.0 *3.14/180.0));// *
           //  qSin((-30 + 100.0*counter/100.0) *3.14/180.0));

    }
    trigger.AddData(y);
    trigger.read(xt, yt);

    display->AddPoints(false, xt, yt);

    timer->start(50);
    //qDebug() << "x: " << xt[0] << " y: " << yt[0] << "\n";
    //trigger.trigger_level += 0.001;
    display->triggerTag->updatePosition(trigger.trigger_level);
    display->replot();
}


void MainWindow::readSerial()
{
    if(serialPort->bytesAvailable() < 1000)
        return;

    QByteArray bytes = serialPort->readAll();
    QVector<double> good_bytes;
    QVector<double> xt, yt;

    good_bytes.reserve(bytes.size());

    for(int i=0;i<bytes.size();i++)
    {
        double val = double(uint8_t(bytes[i]));
        good_bytes.push_back((2.0*(val/255.0))-1.0);
    }

    trigger.AddData(good_bytes);
    qInfo() << good_bytes.size() << "\n";
    trigger.read(xt, yt);

    display->AddPoints(false, xt, yt);

    display->triggerTag->updatePosition(trigger.trigger_level);
    display->replot();
}
