#include "time.h"
#include <Qstring>
#include <QFont>
#include <QDebug>
#include "game.h"
#include <QLabel>
#include <QString>
#include <QPushButton>
extern Game *game;
Time::Time(QGraphicsItem * parent):QGraphicsTextItem(parent){

    setPlainText(QString("Time: ")+ QString::number(30));
    setDefaultTextColor(Qt::black);
    setFont(QFont("times",16,QFont::Bold));

    countdown = new QTimer();           //Construct the timer
    countdown->setInterval(1000);       //One second interval
    countdown->setSingleShot(false);    //Multiple shot. This means that the signal timeout will be signed each second
//    countdown ->start();
    connect(countdown,SIGNAL(timeout()),this,SLOT(timeOut())); //Connects the timeout signal to my slot timeOut
    s = 30000;

}

void Time::timeOut(){

    int seconds;
    if(s - 1000 >= 0){
        s = s -1000;
        seconds = s/1000;
        setPlainText(QString("Time: ")+QString::number(seconds));
        if(s <= 0){

          /*  int a;
            a = game->score->getScore();
            qDebug()<<a; */             //debug

            End *end = new End();
            countdown -> stop();
           // label();
            end->show();
            game->hide();

           // delete game;
        }
    }
}

/*void Time::label(){
    QLabel * label = new QLabel("  Score: "+ QString::number(a));
    label->QLabel::setFixedHeight(100);
    label->QLabel::setFixedWidth(300);
   // QPushButton btn
    label->show();
 //   delete game;


}*/
