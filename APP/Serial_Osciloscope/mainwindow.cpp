#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    layout(new QGridLayout(this)),
    display(new Display(this))
{
    ui->setupUi(this);

    layout->addWidget(display);
    centralWidget()->setLayout(layout);

    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(update_data()));
    timer->start(10);

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
