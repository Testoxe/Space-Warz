#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "player.h"
#include "bullet.h"
#include "enemy.h"
#include "health.h"


Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    bulletSound = new QMediaPlayer();
    bulletSound->setMedia(QUrl("qrc:/sounds/bullet.wav"));
}

void Player::keyPressEvent(QKeyEvent * event)
{

    if(event->key() == Qt::Key_Left && x() > 0){
        this->setX(x()-20);
        //qDebug() << "To the left";
    }
    else if(event->key() == Qt::Key_Right && x()/*+rect().width()*/ < 700){
        this->setX(x()+20);
        //qDebug() << "To the right";
    }
    else if(event->key() == Qt::Key_Space){
        Bullet * bullet = new Bullet();
        bullet->setX(x()+45);
        bullet->setY(500);
        //bullet->setOffset(/*x()+45*/500,/*y()+40*/500);
        bullet->setScale(0.1);
        //qDebug() << x();
        //qDebug() << y();

        bullet->x();
        bullet->y();
        scene()->addItem(bullet);

        if (bulletSound->state() == QMediaPlayer::PlayingState){
            bulletSound->setPosition(0);
        }
        else if (bulletSound->state() == QMediaPlayer::StoppedState){
            bulletSound->play();
            //qDebug() << "Bullet sound played !";
        }



    }
}

void Player::spawn()
{
    //test
    //checking if the ship is focused
    //qDebug() << "Focus on the ship: " << this->hasFocus();


    //----------------------------------------------------------------------------------
    //Enemy
    //------------------------------------------------
    //spawning enemy
    Enemy * enemy = new Enemy();

    //resizing enemy
    enemy->setScale(0.355);

    //adding enemy to the scene
    scene()->addItem(enemy);

    //collision on creation: handling
    QList<QGraphicsItem *> collidingItemsList = enemy->collidingItems();
    foreach(QGraphicsItem * i , collidingItemsList)
    {
        Enemy * item= dynamic_cast<Enemy *>(i);
        if (item){
            //qDebug() << "creation happened between :";
            //qDebug() << item->x();
            //qDebug() << enemy->x();
            if (enemy->x() < 350) enemy->setX(enemy->x()+150);
            if (enemy->x() >= 350) enemy->setX(enemy->x()-150);
            //qDebug() << "New enemy x is :";
            //qDebug() << enemy->x();
        }
    }
    //----------------------------------------------------------------------------------





}
