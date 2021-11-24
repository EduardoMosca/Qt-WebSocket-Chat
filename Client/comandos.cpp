#include "comandos.h"

Comandos::Comandos(QObject *parent, FILE *fileHandler)
    : QObject{parent}, cin(fileHandler)
{

}

void Comandos::monitor()
{
    while(true)
    {
        QString valor = cin.readLine();
        emit comando(valor);
    }
}
