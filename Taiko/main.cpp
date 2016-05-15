#include "mainwindow.h"
#include <QApplication>
/*include <QGraphicsScene>
#include "MyRect.h"
#include <QGraphicsView>
#include <QTimer>*/
#include "Game.h"

Game * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // Game * game;
//    game = new Game();
    //game -> show();

 /*   QGraphicsScene * scene = new QGraphicsScene();

    MyRect * rect = new MyRect();
    rect -> setRect (0,0,100,100);

    scene->addItem(rect);

    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();

    QGraphicsView * view = new QGraphicsView();

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->setScene(scene);
    view->show();
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);

    rect->setPos(view->width()/2,view->height()-rect->rect().height());

    //spawn enemies
    QTimer  * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()),rect,SLOT(spawn()));
    timer->start(1000);
*/

    return a.exec();
}
