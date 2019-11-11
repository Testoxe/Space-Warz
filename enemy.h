#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Enemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
    int direction = 1;
    //int flagStillColliding = 0;
public:
    Enemy();
public slots:
    void move();
};




#endif // ENEMY_H
