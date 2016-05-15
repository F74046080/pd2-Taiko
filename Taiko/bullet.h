#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>

class bullet: public QObject,public QGraphicsRectItem{
    Q_OBJECT
public:
    bullet();
public slots:
    void move();

};

#endif // BULLET_H
