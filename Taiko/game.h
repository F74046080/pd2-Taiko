#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "myrect.h"
#include "score.h"
#include "time.h"

class Game: public QGraphicsView{
public:
    Game(QWidget * parent =0);

    QGraphicsScene *scene;
    MyRect * rect;
    Score * score;
    Time * time;
};


#endif // GAME_H
