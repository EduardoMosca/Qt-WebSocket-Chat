#include "webclient.h"

WebClient::WebClient(const QUrl &url, QObject *parent)
    : QObject{parent}, m_url{url}
{
    connect(&m_webSocket, &QWebSocket::connected, this, &WebClient::quandoConectado);
    connect(&m_webSocket, &QWebSocket::disconnected, this, &WebClient::quandoDesconectado);
    m_webSocket.open(QUrl(url));
}

void WebClient::quandoConectado()
{
    qInfo() << "WebSocket connected";
    connect(&m_webSocket, &QWebSocket::textMessageReceived, this, &WebClient::quandoReceberMensagem);
}

void WebClient::quandoDesconectado()
{
    qInfo() << "Desconectado";
}

void WebClient::commando(QString valor)
{
    QString mensagem = nome + ": ";
    if(nome.isEmpty())
    {
        nome = valor;
        mensagem = nome + ": entrou";
        quandoEnviarMensagem(mensagem);
        return;
    }
    mensagem.append(valor);
    quandoEnviarMensagem(mensagem);
}

void WebClient::quandoEnviarMensagem(const QString &mensagem)
{
    m_webSocket.sendTextMessage(mensagem);
}

void WebClient::quandoReceberMensagem(const QString &mensagem)
{
    qInfo() << mensagem;
}
