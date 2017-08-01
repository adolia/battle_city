#ifndef STAGEOBJECT_H
#define STAGEOBJECT_H

#include <QObject>

class StageObject : public QObject
{
    Q_OBJECT
public:
    explicit StageObject(QObject *parent = nullptr);

signals:

public slots:
};

#endif // STAGEOBJECT_H