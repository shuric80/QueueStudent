#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QUrl>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QTimer>

class Client:public QObject
{
    Q_OBJECT
public:
    Client(QObject *parent);
   // void setParam(const QString&);
   // void setURL();
    //void login(const QString, const QString);
private:
    void send();
    void authenticate(const QVariantMap*);
    QUrl url;

    QNetworkAccessManager *manager;
    QTimer *timer;

    QString _login;
    QString _password;

private slots:
    void replyFinished(QNetworkReply*);
    void update();
    void requestError(QNetworkReply::NetworkError);

};

#endif // CLIENT_H
