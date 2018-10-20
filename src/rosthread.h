#ifndef ROSTHREAD_H
#define ROSTHREAD_H

#include <QString>
#include <QThread>

#include "ros/ros.h"
#include "std_msgs/String.h"

class RosThread : public QThread
{
    Q_OBJECT

public slots:
    void addLine(QString newLine);

public:
    void run();

private:
    ros::Publisher pub;
};

#endif