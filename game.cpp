#include "game.h"
#include <QDebug>
#include <QMediaPlayer>
#include <QGraphicsPixmapItem>

Game::Game()
{
    //Creating the scene
    QGraphicsScene * scene = new QGraphicsScene();

    //Creating the spaceship
    Player * ship = new Player();

    //Placement and dimensions
    //ship->setRect(0,0,100,100);
    ship->setPixmap(QPixmap(":/images/player.png"));

    //Putting the ship on the scene
    scene->addItem(ship);

    //making the ship focusable
    ship->setFlag(QGraphicsItem::ItemIsFocusable);
    //Focusing the ship
    ship->setFocus();



    //creating enemy
    QTimer * spawnTimer = new QTimer();
    QObject::connect(spawnTimer,SIGNAL(timeout()),ship,SLOT(spawn()));
    spawnTimer->start(2000);

    //Linking to the scene
    setScene(scene);

    //creating the score
    score = new Score();
    //adding it to the scene
    scene->addItem(score);

    //Health

    //     =>Creating health
    health = new Health();

    int j = 0;
    int initialPos = 745;
    qDebug() << health->lifePoints.length();
    foreach(Life * life , health->lifePoints){
        //adding the heart rect to the scene
        scene->addItem(life);
        //positioning
        life->setPixmap(QPixmap(":/images/heart.png"));
        life->setScale(0.07);
        life->setX(initialPos-j*40);
        life->setY(15);
        //life->setRect(initialPos-j*35,20,20,20);
        //life->setPos(initialPos-j*35,30);
        j++;
        qDebug() << "life pos w and h" << life->x() << life->y();
    }

    //----------------------------------------------------------------------------------



    //locking draggers
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //setting view's size
    this->setFixedSize(800,600);

    //dimensioning the scene
    scene->setSceneRect(0,0,800,600);

    //painting the scene
    QPixmap backGround(":/images/desert-background.png");
    setBackgroundBrush(QBrush(backGround.scaled(800,600)));

    //play background music
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/bg_music.mp3"));
    music->setVolume(30);
    music->play();

    //initially positioning ship
    ship->setOffset(/*this->width()/2*/ 0,this->height() -100/*- ship->rect().height()*/);


}
