#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include <QEvent>
#include <QDebug>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    qDebug() << "MainWindow constructor";

    ui->setupUi(this);
    cv::Mat frame;
    cv::Mat grayframe;
            cv::Mat grayframe1;
            cv::Mat grayframe2;
            cv::Mat grayframe3;
            cv::Mat grayframe4;
    cv::VideoCapture cap;
    cap.open(0);

    while(cv::waitKey(27))
    {
        cap.read(frame);

         cv::Mat top_left   = frame(cv::Range(0, frame.rows / 2 - 1), cv::Range(0, frame.cols / 2 - 1));
         cv::Mat top_right = frame(cv::Range(0, frame.rows / 2 - 1), cv::Range(frame.cols / 2, frame.cols - 1));
         cv::Mat bottom_left = frame(cv::Range(frame.rows / 2, frame.rows - 1), cv::Range(0, frame.cols / 2 - 1));
         cv::Mat bottom_right = frame(cv::Range(frame.rows / 2, frame.rows - 1), cv::Range(frame.cols / 2, frame.cols - 1));

 // ......................................finding circle in allframes........................................................
        cvtColor(frame,grayframe,CV_BGR2GRAY);
        GaussianBlur(grayframe,grayframe,cv::Size(9,9),2,2);
      std::vector <cv::Vec3f> circles;
            // cv::Vector circles;

        /// Apply the Hough Transform to find the circles
        HoughCircles( grayframe, circles, CV_HOUGH_GRADIENT, 2,20,100,155,20,300 );

        /// Draw the circles detected
        for( size_t i = 0; i < circles.size(); i++ )
        {
            cv::Point  center(cvRound(circles[i][0]), cvRound(circles[i][1]));
            int radius = cvRound(circles[i][2]);
            // circle center
            circle( frame, center, 3, cv::Scalar(0,255,0), -1, 8, 0 );
            // circle outline
            circle( frame, center, radius, cv::Scalar(0,0,255), 3, 8, 0 );
            QString qstring = "0";
            emit message( qstring );
        }
           // dividing the frame into 4 parts



  // ......................................finding circle in topleft........................................................

        cvtColor(top_left ,grayframe1,CV_BGR2GRAY);
        GaussianBlur(grayframe1,grayframe1,cv::Size(9,9),2,2);
        //cv::vector<Vec3f> circles1;
          std::vector <cv::Vec3f> circles1;
           HoughCircles( grayframe1, circles1, CV_HOUGH_GRADIENT, 2,20,100,155,20,300 );

        /// Draw the circles detected
        for( size_t i = 0; i < circles1.size(); i++ )
        {
            cv::Point center(cvRound(circles1[i][0]), cvRound(circles1[i][1]));
            int radius = cvRound(circles1[i][2]);
            // circle center
            circle( top_left, center, 3, cv::Scalar(0,255,0), -1, 8, 0 );
            // circle outline
            circle( top_left, center, radius, cv::Scalar(0,0,255), 3, 8, 0 );
            QString qstring = "1";
            emit message1( qstring );
        }
 //............................. finding circle in topright..................................................................
        cvtColor(top_right ,grayframe2,CV_BGR2GRAY);
        GaussianBlur(grayframe2,grayframe2,cv::Size(9,9),2,2);
        //cv::vector<Vec3f> circles2;
          std::vector <cv::Vec3f> circles2;
           HoughCircles( grayframe2, circles2, CV_HOUGH_GRADIENT, 2,20,100,155,20,300 );

        /// Draw the circles detected
        for( size_t i = 0; i < circles2.size(); i++ )
        {
            cv::Point center(cvRound(circles2[i][0]), cvRound(circles2[i][1]));
            int radius = cvRound(circles2[i][2]);
            // circle center
            circle( top_right, center, 3, cv::Scalar(0,255,0), -1, 8, 0 );
            // circle outline
            circle( top_right, center, radius, cv::Scalar(0,0,255), 3, 8, 0 );
            QString qstring = "2";
            emit message2( qstring );
        }

   //.................................................. finding circle in bottomleft..........................................
        cvtColor(bottom_left ,grayframe3,CV_BGR2GRAY);
        GaussianBlur(grayframe3,grayframe3,cv::Size(9,9),2,2);
       // cv::vector<Vec3f> circles3;
       std::vector <cv::Vec3f> circles3;
           HoughCircles( grayframe3, circles3, CV_HOUGH_GRADIENT, 2,20,100,155,20,300 );

        /// Draw the circles detected
        for( size_t i = 0; i < circles3.size(); i++ )
        {
            cv::Point center(cvRound(circles3[i][0]), cvRound(circles3[i][1]));
            int radius = cvRound(circles3[i][2]);
            // circle center
            circle( bottom_left, center, 3, cv::Scalar(0,255,0), -1, 8, 0 );
            // circle outline
            circle(bottom_left, center, radius, cv::Scalar(0,0,255), 3, 8, 0 );
            QString qstring = "3";
            emit message3( qstring );
        }

  //.................................................. finding circle in bottomright..........................................
        cvtColor(bottom_right ,grayframe4,CV_BGR2GRAY);
        GaussianBlur(grayframe4,grayframe4,cv::Size(9,9),2,2);

   std::vector <cv::Vec3f> circles4;


           HoughCircles( grayframe4, circles4, CV_HOUGH_GRADIENT, 2,20,100,155,20,300 );

        /// Draw the circles detected
        for( size_t i = 0; i < circles4.size(); i++ )
        {
            cv::Point center(cvRound(circles4[i][0]), cvRound(circles4[i][1]));
            int radius = cvRound(circles4[i][2]);
            // circle center
            circle( bottom_right, center, 3, cv::Scalar(0,255,0), -1, 8, 0 );
            // circle outline
            circle(bottom_right, center, radius, cv::Scalar(0,0,255), 3, 8, 0 );
            QString qstring = "4";
            emit message4( qstring );
        }

        cv::imshow("Hough circles",frame);
        cv::imshow("top_left", top_left);
         cv::imshow("top_right", top_right);
        cv::imshow("bottom_left", bottom_left);
       cv::imshow("bottom_right", bottom_right);


    }
    // Create RosThread
    this->rost = new RosThread();
    connect(this, SIGNAL(message(QString)), this->rost, SLOT(addLine(QString)));
    connect(this, SIGNAL(message1(QString)), this->rost, SLOT(addLine(QString)));
    connect(this, SIGNAL(message2(QString)), this->rost, SLOT(addLine(QString)));
    connect(this, SIGNAL(message3(QString)), this->rost, SLOT(addLine(QString)));
    connect(this, SIGNAL(message4(QString)), this->rost, SLOT(addLine(QString)));
     connect(this, SIGNAL(message5(QString)), this->rost, SLOT(addLine(QString)));
     connect(this, SIGNAL(message6(QString)), this->rost, SLOT(addLine(QString)));

     // start begins periodically executing the run() function
    this->rost->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_pressed()
{

}

void MainWindow::on_pushButton_2_pressed()
{
    QString qstring = "1";
    emit message( qstring );
}

void MainWindow::on_pushButton_3_pressed()
{
    QString qstring = "2";
    emit message1( qstring );
}

void MainWindow::on_pushButton_4_pressed()
{
    QString qstring = "3";
    emit message2( qstring );
}



void MainWindow::on_pushButton_5_pressed()
{
    QString qstring = "4";
    emit message3( qstring );
}

void MainWindow::on_pushButton_6_pressed()
{
    QString qstring = "5";
    emit message4( qstring );
}

void  MainWindow::keyPressEvent(QKeyEvent * event)
{
    if(event->key()== Qt::Key_W)
    {
            QString qstring = "1";
            emit message1( qstring );

    }


    if(event->key()== Qt::Key_A)
    {
            QString qstring = "2";
            emit message2( qstring );

    }

    if(event->key()== Qt::Key_S)
    {
            QString qstring = "3";
            emit message3( qstring );

    }

    if(event->key()== Qt::Key_D)
    {
            QString qstring = "4";
            emit message4( qstring );

    }

    if(event->key()== Qt::Key_E)
    {
            QString qstring = "5";
            emit message5( qstring );

    }




}




