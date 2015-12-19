#ifndef CLIENTPROFILE_H
#define CLIENTPROFILE_H

#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QTimer>
#include <QUrl>
#include <QTextCodec>
#include <QDebug>
#include <QPixmap>

#define DEBUG true
#define TIMEOUT_UPDATE 2000
#define URL "http://127.0.0.1:8000"


class ClientProfile : public QObject
{
    Q_OBJECT
public:
    ClientProfile(QObject *parent=0);

private:
    QTimer *timer;
    QNetworkAccessManager *manager;
signals:
    void readServer(const QByteArray&);
    void errorNetwork(const QString &);

public slots:
    void slotFinished(QNetworkReply*);
    void updateProfile();
    void authenticated(const QStringList);
    void send();

    void setQueued(int);

private:
    QString _url;
    QVariantMap _param;
    QString _login;
    QString _password;
    QString _task;
};

#endif // CLIENTPROFILE_H
