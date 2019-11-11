#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem
{
    int score;
public:
    Score();
    void increase(int rate);
    int getScore();
};

#endif // SCORE_H
