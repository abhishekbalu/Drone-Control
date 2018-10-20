#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QThread>

#include "rosthread.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:
    void message(QString msg);
    void message1(QString msg);
    void message2(QString msg);
    void message3(QString msg);
    void message4(QString msg);
    void message5(QString msg);
    void message6(QString msg);


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:

    
private slots:





    void on_pushButton_3_pressed();

    void on_pushButton_pressed();

    void on_pushButton_2_pressed();

    void on_pushButton_4_pressed();

    void on_pushButton_5_pressed();

    void on_pushButton_6_pressed();


private:
    Ui::MainWindow *ui;
    RosThread *rost;
    void  keyPressEvent(QKeyEvent * event);

};

#endif // MAINWINDOW_H
