#include "rosthread.h"

#include <QDebug>


void RosThread::run()
{
    qDebug() << "RosThread run called";

    ros::NodeHandle n;
    pub = n.advertise<std_msgs::String>("awesome_topic", 10000);
    ros::spin();
}
void RosThread::addLine(QString newLine)
{
    ros::Rate rate(0);
    std_msgs::String msg;
    msg.data= newLine.toUtf8().constData();
    pub.publish(msg);
}

