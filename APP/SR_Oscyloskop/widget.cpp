#include "widget.h"
#include "xyseriesiodevice.h"

#include <QtMultimedia/QAudioDeviceInfo>
#include <QtMultimedia/QAudioInput>

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QtCharts/QValueAxis>

#include <QtWidgets/QVBoxLayout>
#include <QtSerialPort>
QT_CHARTS_USE_NAMESPACE

Widget::Widget(QSerialPort &port, QWidget *parent) :
    QWidget(parent),
    m_chart(new QChart),
    m_series(new QLineSeries)
{
    QChartView *chartView = new QChartView(m_chart);
    chartView->setMinimumSize(800, 600);
    m_chart->addSeries(m_series);
    QValueAxis *axisX = new QValueAxis;
    axisX->setRange(0, XYSeriesIODevice::sampleCount);
    axisX->setLabelFormat("%g");
    axisX->setTitleText("Samples");
    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(-1, 1);
    axisY->setTitleText("raw input value");
    m_chart->setAxisX(axisX, m_series);
    m_chart->setAxisY(axisY, m_series);
    m_chart->legend()->hide();
    m_chart->setTitle("Data from the MCU (" + port.portName() + ')');

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(chartView);

    QAudioFormat formatAudio;
    formatAudio.setSampleRate(8000);
    formatAudio.setChannelCount(1);
    formatAudio.setSampleSize(8);
    formatAudio.setCodec("audio/pcm");
    formatAudio.setByteOrder(QAudioFormat::LittleEndian);
    formatAudio.setSampleType(QAudioFormat::UnSignedInt);

    m_port = &port;
    m_device = new XYSeriesIODevice(m_series, this);
    m_device->open(QIODevice::WriteOnly);

    m_audioInput->start(m_device);
}

Widget::~Widget()
{
    m_audioInput->stop();
    m_device->close();
}
