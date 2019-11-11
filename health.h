#ifndef HEALTH_H
#define HEALTH_H

#include <QList>
#include "life.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QBrush>
#include <QGraphicsTextItem>

class Health
{
    const int initialPoints = 3;

public:
    Health();
    ~Health();
    QList<Life *> lifePoints;
    void decrease();
};

#endif // HEALTH_H
