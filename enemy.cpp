#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QDebug>
#include <QList>
#include <stdlib.h>
#include "game.h"

extern Game * game;


Enemy::Enemy()
{
    //setting a rand int
    int randomNumber = rand() % 700;
    // pos and size
    //setRect(0,0,100,100);

    setPixmap(QPixmap(":/images/enemy.png"));
    setY(0);
    setX(randomNumber);

    //connecting slot and signal
    QTimer * movTimer = new QTimer();
    connect(movTimer,SIGNAL(timeout()),this,SLOT(move()));
    movTimer->start(10);
}

void Enemy::move()
{

    //Horizontal movement
    //Collision handling :
    //  =>Wall collision handling
    if ( x() < 1 ){direction=1;} // to right
    if ( x()+100 > 789){direction=-1;} // to left

    //  =>Enemy collision handling
    QList<QGraphicsItem *> collidingItemsList = collidingItems();
    foreach(QGraphicsItem * i , collidingItemsList)
    {
        Enemy * item= dynamic_cast<Enemy *>(i);
        if (item){
            /*if (direction == 1 && this->x()+this->100 > item->x()+3){
                //translation+switching direction on deep collision to right
                this->setX(this->x()-10);
                direction=-direction;
            }
            else if (direction == -1 && this->x() < item->x()+item->100-3){
                //translation+switching direction on deep collision to left
                this->setX(this->x()+10);
                direction=-direction;
            }
            else {*/
                //switching direction on collision with another enemy
                direction=-direction;
            /*}*/

        }
    }


    setX(x()+2*direction);

    //vertical movement
    setY(y()+0.4);

    //deleting when out of bounds
    if(y() + 100 > 600){
        game->health->decrease();
        scene()->removeItem(this);
        delete this;


    }
}
