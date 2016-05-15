#include "game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Enemy.h"
#include <stdlib.h>
#include <QImage>
#include <QBrush>

extern Time *time;

Game::Game(QWidget* parent){

    QGraphicsScene * scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/images/bg4.jpg")));

    setWindowTitle("Taiko~");
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);


    //create the player
    MyRect * rect = new MyRect();
//    setPixmap(QPixmap(":/images/rect.jpg"));
//    rect -> setRect (0,0,10,10);
//    rect->setPos(width()/2,height()-rect->rect().height());
    rect->setPos(230,235);


    //make the player focusable
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();
    // add the rect to the scene
    scene->addItem(rect);

    //create the score
    score = new Score();
    score->setPos(40,210);
    scene->addItem(score);
    
    //create the time
    time = new Time();
    time->setPos(42,243);
    scene->addItem(time);
    //time->countdown ->start();

    //spawn enemies
    QTimer  * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()),rect,SLOT(spawn()));
    timer->start(1000);

}
