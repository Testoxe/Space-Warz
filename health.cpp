#include "health.h"
#include <QDebug>

Health::Health()
{
    qDebug() << lifePoints.length();
    for(int i=0;i<initialPoints;i++){
        Life * life = new Life();
        lifePoints.append(life);
        qDebug() << lifePoints.length();
    }
    qDebug() << "Final lp length: "<< lifePoints.length();


}

Health::~Health()
{
    for(int i=0;i<initialPoints;i++){
        delete lifePoints[i];
        qDebug() << "deletion :" << lifePoints.length();
    }
    delete this;
}

void Health::decrease()
{
    if (!lifePoints.isEmpty()) {
        Life * lastLife = lifePoints.takeLast();
        if (lifePoints.isEmpty()){
            // Game Over
            QGraphicsRectItem* panel = new QGraphicsRectItem(0,0,800,600);
            QBrush brush;
            brush.setStyle(Qt::SolidPattern);
            brush.setColor(Qt::white);
            panel->setBrush(brush);
            panel->setZValue(100);
            QGraphicsTextItem* gameOverText = new QGraphicsTextItem("GAME OVER");
            gameOverText->setPos(300,280);
            gameOverText->setDefaultTextColor(Qt::red);
            gameOverText->setFont(QFont("times",32));
            gameOverText->setZValue(101);
            lastLife->scene()->addItem(panel);
            lastLife->scene()->addItem(gameOverText);

        }
        delete lastLife;
    };
}

