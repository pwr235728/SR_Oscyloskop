#ifndef TRIGGER_H
#define TRIGGER_H


#include <QVector>

class trigger
{
public:
    trigger();

    double sample_time = 0.001;
    double duration = 0.1; // 1 sekunda  poziomo
    double trigger_level = 0.0;

    QVector<double> ready_values;
    QVector<double> values_keys;

    bool wait_for_trig = true;

    int sample_number = 0;

    int read(QVector<double> &keys, QVector<double> &values);

    int get_sample_count();

    double get_sample_inc();

  double prev = 0;
    int AddData(const QVector<double> &values);
};

#endif // TRIGGER_H
