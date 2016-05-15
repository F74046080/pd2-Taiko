#include "MyRect.h"
#include <QKeyEvent>
#include "bullet.h"
#include <QGraphicsScene>
#include "Enemy.h"
#include "enemy2.h"
#include <Qdebug>
//#include <QDebug>
#include "game.h"
#include <QList>
#include <typeinfo>
#include <stdlib.h> // rand


extern Game * game;

MyRect::MyRect (QGraphicsItem *parent):QGraphicsPixmapItem(parent){

    setPixmap(QPixmap(":/images/rect.jpg"));
//    drumsound = new QMediaPlayer();
//    drumsound->setMedia(QUrl("qrc:/sounds/drum.mp3"));
}
void MyRect::keyPressEvent(QKeyEvent *event){
    //qDebug()<<"MyRect knows that you pressed a key";

    if(event->key() == Qt::Key_Z){
        QList<QGraphicsItem*> colliding_items=collidingItems();
        for(int i=0, n = colliding_items.size();i<n;i++){
             if(typeid(*(colliding_items[i])) == typeid(Enemy)){
                //increase the score
                game->score->increase();

                //remove them from the scene
                scene() ->removeItem(colliding_items[i]);
                //scene() ->removeItem(this);

                delete colliding_items[i];
            //    delete this;
                return;
            }
         }
    }
    else if(event->key() == Qt::Key_X){
        QList<QGraphicsItem*> colliding_items=collidingItems();
        for(int i=0, n = colliding_items.size();i<n;i++){
             if(typeid(*(colliding_items[i])) == typeid(Enemy2)){
                //increase the score
                game->score->increase();

                //remove them from the scene
                scene() ->removeItem(colliding_items[i]);
                //scene() ->removeItem(this);

                delete colliding_items[i];
            //    delete this;
                return;
            }
         }
/*        //play drum sound
        if(drumsound->state() == QMediaPlayer::PlayingState){
            drumsound->setPosition(0);
        }
        else if (drumsound -> state() == QMediaPlayer::StoppedState){
            drumsound->play();
        }*/
    }
}


void MyRect::spawn(){
    int a = rand()%2+1;
    //create an ememy
    if(a==1){
        Enemy * enemy = new Enemy();
        scene()->addItem(enemy);
    }
    else{
        Enemy2 * enemy2 = new Enemy2();
        scene()->addItem(enemy2);
    }
}
