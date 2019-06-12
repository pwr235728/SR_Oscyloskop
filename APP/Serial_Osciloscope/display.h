#ifndef DISPLAY_H
#define DISPLAY_H

#include <QWidget>

#include "qcustomplot.h"
#include "axistag.h"

class Display : public QCustomPlot
{
    Q_OBJECT

public:
    explicit Display(QWidget *parent = nullptr);


    int AddPoints(bool new_shot, const QVector<double> &x, const QVector<double> &y);
    AxisTag *triggerTag = nullptr;
private:
    static const int sample_count = 2000;
    QCPCurve *newCurve = nullptr;
    int counter = 0;


};

#endif // DISPLAY_H
