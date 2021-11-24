#ifndef COMANDOS_H
#define COMANDOS_H

#include <QObject>
#include <QDebug>
#include <QTextStream>

class Comandos : public QObject
{
    Q_OBJECT
public:
    explicit Comandos(QObject *parent = nullptr, FILE *fileHandler = nullptr);

    [[noreturn]] void monitor();

signals:
    void comando(QString valor);

private:
    QTextStream cin;
};

#endif // COMANDOS_H
