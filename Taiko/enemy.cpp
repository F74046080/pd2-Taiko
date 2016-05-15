#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h> // rand

Enemy::Enemy():QObject(),QGraphicsPixmapItem(){
    //set random position
//    int random_number = rand () % 700;
    setPos(800,185);

    // drew the rect
    //setRect(45,15,30,30);
    setPixmap(QPixmap(":/images/red.png"));

    //connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Enemy::move(){
    //move enemy left
    setPos(x()-9,y());
    if(pos().x()/* + rect().height()*/<130){
        scene()->removeItem(this);
        delete this;
    }
}
