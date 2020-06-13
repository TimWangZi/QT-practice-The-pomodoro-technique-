#include "window.h"

Window::Window(QWidget *parent)
    : QWidget(parent) ,time(0), StartOrNot(false), timeout(20) {
    this -> setWindowTitle("计时器-debug only");
    this -> resize(200 ,200);
    this -> setWindowFlag(Qt::WindowStaysOnTopHint);
    this -> setStyleSheet("background-color: rgb(255,255,255);");


    Start.setParent(this);
    Start.move(70 ,130);
    Start.resize(60 ,30);
    Start.setText("开始");
    Start.setStyleSheet("QPushButton {"
                        "   background-color: rgb(82,181,254);"
                        "   font-family:\"Microsoft YaHei\";"
                        "   font: bold;"
                        "   color: rgb(255,255,255);"
                        "   border-style: solid;"
                        "   border-radius: 5px;"
                        "}"
                        "QPushButton:hover {"
                        "   background-color: rgb(101,200,255);"
                        "}");


    Add5Min.setParent(this);
    Add5Min.setText("+");
    Add5Min.move(40 ,20);
    Add5Min.resize(20 ,20);
    Add5Min.setStyleSheet("QPushButton {"
                        "   background-color: rgb(255,255,255);"
                        "   font-family:\"Microsoft YaHei\";"
                        "   font: bold;"
                        "   color: rgb(82,181,254);"
                        "   border-style: solid;"
                        "   border-radius: 2px;"
                        "   border-width: 1px;"
                        "}"
                        "QPushButton:pressed {"
                        "   background-color: rgb(101,200,255);"
                        "   border-color: rgb(255,255,255);"
                        "   color: rgb(255,255,255);"
                        "}");

    Min5Min.setParent(this);
    Min5Min.setText("-");
    Min5Min.move(90 ,20);
    Min5Min.resize(20 ,20);
    Min5Min.setStyleSheet("QPushButton {"
                        "   background-color: rgb(255,255,255);"
                        "   font-family:\"Microsoft YaHei\";"
                        "   font: bold;"
                        "   color: rgb(82,181,254);"
                        "   border-style: solid;"
                        "   border-radius: 2px;"
                        "   border-width: 1px;"
                        "}"
                        "QPushButton:pressed {"
                        "   background-color: rgb(101,200,255);"
                        "   border-color: rgb(255,255,255);"
                        "   color: rgb(255,255,255);"
                        "}");


    timedisplay.setParent(this);
    timedisplay.move(100 ,100);
    timedisplay.resize(100,20);
    timedisplay.setStyleSheet("QLabel {"
                              "     color:rgb(82,181,254);"
                              "     font-family:\"Microsoft YaHei\";"
                              "     font: bold 20px"
                              "}");
    timer.setParent(this);
    connect(&timer, &QTimer::timeout, this, &Window::onClockTime);
    connect(&Start, &QPushButton::released, this, &Window::startClock);
}

Window::~Window() {
    timer.stop();
}

inline void Window::onClockTime() {
    if(time < timeout){
        timedisplay.setText(QString::number(time ,10));
        time++;
    }else {
        time = 0;
        timer.stop();
        StartOrNot = false;
        timedisplay.setText(QString::number(time ,10));
        Start.setText("开始");
    }
}
inline void Window::startClock() {
    if(StartOrNot!=true){
        timer.start(1000);
        Start.setText("停止");
        StartOrNot = !StartOrNot;
    }else{
        timer.stop();
        Start.setText("开始");
        StartOrNot = !StartOrNot;
    }
}

