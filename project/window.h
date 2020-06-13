#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

#include <QLabel>
#include <QTimer>
#include <QPushButton>

class Window : public QWidget {
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);
    inline void onClockTime();
    inline void startClock();
    ~Window();
private:
    QPushButton Add5Min,Min5Min;
    QPushButton Start;

    QLabel timedisplay;
    QTimer timer;
    int time, timeout;
    bool StartOrNot;

/*signals:
    inline void StartClock(void);
    inline void StopClock(void);*/
};
#endif // WINDOW_H
