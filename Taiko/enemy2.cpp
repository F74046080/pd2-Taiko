#include "enemy2.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h> // rand

Enemy2::Enemy2():QObject(),QGraphicsPixmapItem(){
    //set random position
//    int random_number = rand () % 700;
    setPos(800,185);

    // drew the rect
    //setRect(45,15,30,30);
    setPixmap(QPixmap(":/images/yellow2.png"));

    //connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Enemy2::move(){
    //move enemy left
    setPos(x()-10,y());
    if(pos().x()/* + rect().height()*/<130){
        scene()->removeItem(this);
        delete this;
    }
}
