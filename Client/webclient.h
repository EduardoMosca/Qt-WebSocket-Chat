#ifndef WEBCLIENT_H
#define WEBCLIENT_H

#include <QObject>
#include <QWebSocket>
#include <QDebug>
#include <QUrl>

class WebClient : public QObject
{
    Q_OBJECT
public:
    explicit WebClient(const QUrl&url ,QObject *parent = nullptr);

public slots:
    void quandoConectado();
    void quandoDesconectado();
    void commando(QString valor);
    void quandoEnviarMensagem(const QString &mensagem);
    void quandoReceberMensagem(const QString &mensagem);

private:
    QUrl m_url;
    QString nome;
    QWebSocket m_webSocket;

};

#endif // WEBCLIENT_H
