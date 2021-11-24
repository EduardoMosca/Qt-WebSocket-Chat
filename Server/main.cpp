#include <QCoreApplication>
#include "webserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    WebServer *mWebServer = new WebServer();
    mWebServer->listen(QHostAddress::Any, 1234);
    return a.exec();
}
