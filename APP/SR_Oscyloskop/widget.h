#ifndef WIDGET_H
#define WIDGET_H


#include <QtWidgets/QWidget>
#include <QtCharts/QChartGlobal>
#include <QtSerialPort>

QT_CHARTS_BEGIN_NAMESPACE
class QLineSeries;
class QChart;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class XYSeriesIODevice;

class QAudioInput;
class QAudioDeviceInfo;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QSerialPort &port, QWidget *parent = nullptr);
    ~Widget();

private:
    XYSeriesIODevice *m_device = nullptr;
    QChart *m_chart;
    QLineSeries *m_series ;
    QSerialPort *m_port;
};


#endif // WIDGET_H
