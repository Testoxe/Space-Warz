#include "score.h"
#include <QFont>

Score::Score()
{
    //initialize score to 0
    score = 0;

    //setting text
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Score::increase(int rate)
{
    score += rate;
    setPlainText(QString("Score: ") + QString::number(score));
}

int Score::getScore()
{
    return score;
}
