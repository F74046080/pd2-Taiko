#ifndef TIME_H
#define TIME_H

#include <Qtimer>
#include <QLabel>
#include <QGraphicsTextItem>
#include "End.h"



class Time: public QGraphicsTextItem{
    Q_OBJECT

public:
    Time(QGraphicsItem * parent = 0);
    QTimer *countdown;
    void label();
protected slots:
    void timeOut();
private:
    int s,a;
//    End end;

};

#endif // TIME_H
