#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <QWebSocketServer>
#include <QWebSocket>
#include <QDebug>
#include <QObject>

class WebServer : public QWebSocketServer
{
    Q_OBJECT
public:
    WebServer(QObject *parent = nullptr);

signals:
    void mensagemRecebida(QString);

public slots:
    void novaConexao();
    void aoDisconectar();
    void onMensagemRecebida(const QString &mensagem);

private:
    QList<QWebSocket *> mSockets;
    QList<QString> mensagensRecebidas;
};

#endif // WEBSERVER_H
