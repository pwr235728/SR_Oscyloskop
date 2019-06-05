#include "display.h"


Display::Display(QWidget *parent)
    : QCustomPlot(parent)
{


    addGraph();
    graph(0)->setPen(QPen(QBrush(Qt::green),2));
    addGraph();
    graph(1)->setPen(QPen(QBrush(Qt::green),2));
    // configure right and top axis to show ticks but no labels:
    // (see QCPAxisRect::setupFullAxesBox for a quicker method to do this)
    xAxis2->setVisible(true);
    xAxis2->setTickLabels(false);
    yAxis2->setVisible(true);
    yAxis2->setTickLabels(false);

    // make left and bottom axes always transfer their ranges to right and top axes:
    connect(xAxis, SIGNAL(rangeChanged(QCPRange)), xAxis2, SLOT(setRange(QCPRange)));
    connect(yAxis, SIGNAL(rangeChanged(QCPRange)), yAxis2, SLOT(setRange(QCPRange)));

    xAxis->setRange(-1.0, 1.0);
    yAxis->setRange(-1.0, 1.0);

    // set some pens, brushes and backgrounds:
    for(auto axis : axisRect(0)->axes())
    {
        axis->setBasePen(QPen(Qt::white, 1));
        axis->setTickPen(QPen(Qt::white, 1));
        axis->setSubTickPen(QPen(Qt::white, 1));
        axis->setTickLabelColor(Qt::white);
        axis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DashDotLine));
        axis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::NoPen));
        axis->grid()->setSubGridVisible(true);
        axis->setUpperEnding(QCPLineEnding::esNone);
        axis->ticker()->setTickCount(10);
     }

    setBackground(QBrush(QColor(30,30,35)));
    axisRect()->setBackground(QBrush(QColor(30,30,35)));
    axisRect()->axis(QCPAxis::atRight, 0)->setPadding(70);

    triggerTag = new AxisTag(graph(0)->valueAxis());
    triggerTag->setPen(QPen(QBrush(QColor(255,69,0)),2));
    triggerTag->setText("Trigger");
    triggerTag->updatePosition(0.0);

    /* test
    // Test
    // generate some points of data (y0 for first, y1 for second graph):
    QVector<double> x(251), y0(251);
    for (int i=0; i<250; ++i)
    {
      x[i] = i/125.0 - 1.0;
      y0[i] = qSin(i/250.0 * 6.28); // exponentially decaying cosine

    }

    plot->graph(0)->setData(x, y0);
     * */

}

int Display::AddPoints(bool new_shot, const QVector<double> &x, const QVector<double> &y)
{
    if(x.length() ==0)
        return 0;

    if(graph(0)->data()->size() > 100)
        graph(0)->data()->clear();

    graph(0)->addData(x, y);
    graph(0)->data()->sort();
    replot();
    return 1;
}
