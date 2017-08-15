#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>
#include "wall.h"
#include "shell.h"
#include "tank.h"
#include "aitank.h"
#include "battlefield.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    int retCode = 0;

    try {
        // register type to use in QML
        qmlRegisterType<Shell> ("BattleObjects", 1, 0, "Shell");
        qmlRegisterType<Wall> ("BattleObjects", 1, 0, "Wall");
        qmlRegisterType<Tank> ("BattleObjects", 1, 0, "Tank");
        qmlRegisterType<AITank> ("BattleObjects", 1, 0, "AITank");

        //QQuickView view;
        //create custom view
        BattleField view(QUrl("qrc:/qml/main.qml"));
        view.setResizeMode(QQuickView::SizeRootObjectToView);
        view.show();
        retCode = app.exec();
    } catch(const std::bad_alloc&) {
        /* There is no references to external resources yet */
        qDebug("Not enough memory!");
    }

    return retCode;
}
