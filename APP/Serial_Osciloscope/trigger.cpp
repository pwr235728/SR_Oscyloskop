#include "trigger.h"
#include <QDebug>
trigger::trigger()
{

}
int trigger::read(QVector<double> &keys, QVector<double> &values)
{
    keys.append(values_keys);
    values.append(ready_values);
    ready_values.clear();
    values_keys.clear();

    return 1;
}

int trigger::get_sample_count()
{
    return int(duration/sample_time);
}

double trigger::get_sample_inc()
{
    return 2.0 / get_sample_count();
}


int trigger::AddData(const QVector<double> &values)
{
    double inc = get_sample_inc();


    for(auto val : values)
    {
        if(wait_for_trig)
        {
            if(prev < trigger_level && val >= trigger_level)
            {
                wait_for_trig = false;
            }
        }
        if(!wait_for_trig)
        {
            ready_values.append(prev);
            values_keys.append((sample_number*inc) - 1.0);

            if(++sample_number > get_sample_count())
            {
                wait_for_trig = true;
                sample_number = 0;
                prev = 2;
                return 1;
            }
            qDebug() << " prev: " << prev << " c: " << val <<"\n";
        }
        prev = val;
    }

    return values.size();
}
