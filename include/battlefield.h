#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include <QtQuick/QQuickView>

class BattleField : public QQuickView
{
    Q_OBJECT
public:
    BattleField(QWindow *parent = Q_NULLPTR);

    ~BattleField() {};
};

#endif // BATTLEFIELD_H
