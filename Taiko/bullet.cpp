#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include "enemy.h"
#include <typeinfo>
#include "Game.h"

extern Game * game; //there is an external global variable

bullet::bullet(){
    // drew the rect
    setRect(50,50,10,10);

    //connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void bullet::move(){
    //if bullet collides with enemy, destroy both
    QList<QGraphicsItem*> colliding_items=collidingItems();
    for(int i=0, n = colliding_items.size();i<n;i++){
        if(typeid(*(colliding_items[i])) == typeid(Enemy)){
            //increase the score
            game->score->increase();

            //remove them from the scene
            scene() ->removeItem(colliding_items[i]);
            scene() ->removeItem(this);

            delete colliding_items[i];
            delete this;
            return;
        }
    }

    setPos(x(),y());
    if(pos().y() + rect().height()<0){
        scene()->removeItem(this);
        delete this;
     //   qDebug()<<"de";
    }
}
