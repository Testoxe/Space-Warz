#include <QTimer>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include "bullet.h"
#include "enemy.h"
#include "game.h"

extern Game * game;

Bullet::Bullet()
{
    // pos and size
    //setRect(0,0,15,40);
    setPixmap(QPixmap(":/images/bullet.png"));

    //connecting slot and signal
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(10);
}

void Bullet::move()
{

    //collision handling
    QList<QGraphicsItem *> collidingItemsList = collidingItems();
    //for (int i=0;i<collidingItemsList.size();i++){
    foreach(QGraphicsItem * i , collidingItemsList)
    {
        Enemy * item= dynamic_cast<Enemy *>(i);
        if (item)
        {
            qDebug() << "collision happened";

            //score incrementation
            game->score->increase(10);
            //removing bullet and enemy on collision
            scene()->removeItem(item);
            scene()->removeItem(this);

            delete item;
            delete this;
            return;
        }
    }



    //moving up
    setY(y()-5);
    //qDebug() << x();
    //qDebug() << y();

    // deleting when out of bounds
    if(y() < 0){
       scene()->removeItem(this);
        delete this;
    }


}

