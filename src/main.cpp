#include "mainwindow.h"
#include <QtGui/QApplication>
#include "ros/ros.h"
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "publisher");
    
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
