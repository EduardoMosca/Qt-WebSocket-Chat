#include <QCoreApplication>
#include <QFuture>
#include <QtConcurrent>
#include <QUrl>
#include "webclient.h"
#include "comandos.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Comandos cli(&a, stdin);

    QFuture<void> future = QtConcurrent::run(&Comandos::monitor, &cli);

    WebClient chat(QUrl("ws://localhost:1234"));

    QObject::connect(&cli, &Comandos::comando, &chat, &WebClient::commando, Qt::QueuedConnection);

    return a.exec();
}
