#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QObject>
#include <QDebug>
#include <QTimer>
#include "mainwindow.h"
#include "player.h"
#include "bullet.h"
#include "enemy.h"
#include "score.h"
#include "health.h"



class Game: public QGraphicsView
{


public:
    Game();

    QGraphicsScene * scene;
    QGraphicsRectItem * ship;
    Score * score;
    Health * health;
};
#endif // GAME_H
