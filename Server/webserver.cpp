#include "webserver.h"

WebServer::WebServer(QObject *parent)
    : QWebSocketServer("Servidor", QWebSocketServer::NonSecureMode, parent)
{
    connect(this, &QWebSocketServer::newConnection, this, &WebServer::novaConexao);
}

void WebServer::novaConexao()
{
    QWebSocket *mSocket = nextPendingConnection();
    connect(mSocket, &QWebSocket::textMessageReceived, this, &WebServer::onMensagemRecebida);
    connect(mSocket, &QWebSocket::disconnected, this, &WebServer::aoDisconectar);
    mSockets << mSocket;
    for(auto &&i : mensagensRecebidas)
    {
        mSocket->sendTextMessage(i);
    }
    qDebug() << "Valor ao conectar: " << mSockets.size();
}

void WebServer::aoDisconectar()
{
    QWebSocket *mSocket = qobject_cast<QWebSocket *>(sender());
    mSockets.removeAll(mSocket);
    mSocket->deleteLater();
    qDebug() << "Valor ao desconectar: " << mSockets.size();
}

void WebServer::onMensagemRecebida(const QString &mensagem)
{
    mensagensRecebidas.append(mensagem);
    for(auto &&i : mSockets)
        i->sendTextMessage(mensagem);
}
