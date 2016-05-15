#include "Score.h"
#include <QString>
#include <QFont>

Score::Score(QGraphicsItem * parent):QGraphicsTextItem(parent){
    // initialize the score to 0
    score =0;

    //draw the text
    setPlainText(QString("Score: ")+ QString::number(score));
    setDefaultTextColor(Qt::black);
    setFont(QFont("times",16,QFont::Bold));
}

void Score::increase(){
    score++;
    setPlainText(QString("Score: ")+ QString::number(score));
}

int Score::getScore(){
    return score;
}
