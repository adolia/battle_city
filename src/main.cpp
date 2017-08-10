#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>
#include "wall.h"
#include "battlefield.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    int retCode = 0;

    try {
        qmlRegisterType<Wall> ("BattleFieldObjects", 1, 0, "Wall");
        //QQuickView view;
        Wall wall;
        BattleField view(QUrl("qrc:/qml/main.qml"));
        view.setResizeMode(QQuickView::SizeRootObjectToView);
        view.show();
        /*
        engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));
        if (engine.rootObjects().isEmpty())
            return -1;
        */
        retCode = app.exec();
    } catch(const std::bad_alloc&) {
        /* There is no references to external resources yet */
        qDebug("Not enough memory!");
    }

    return retCode;
}
