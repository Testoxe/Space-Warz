#ifndef LIFE_H
#define LIFE_H

#include <QObject>
#include <QGraphicsPixmapItem>


class Life: public QObject, public QGraphicsPixmapItem{
        Q_OBJECT
public:
    Life();

};
#endif // LIFE_H
