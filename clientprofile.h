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
#include <QFile>

#define DEBUG true
#define TIMEOUT_UPDATE 2000
#define URL "http://127.0.0.1:8000"


class ClientProfile : public QObject
{
    Q_OBJECT
public:
    ClientProfile(QObject *parent=0);
public slots:
    void setImage(const QString&);
private:
    QTimer *timer;
    QNetworkAccessManager *manager;
    QNetworkAccessManager *img_manager;
signals:
    void readServer(const QByteArray&);
    void errorNetwork(const QString &);

public slots:
    void slotFinished(QNetworkReply*);
    void updateProfile();
    void authenticated(const QStringList);
    void send();
    void loadImage(QNetworkReply*);
  private:

    QString _url;
    QVariantMap _param;
    QString _login;
    QString _password;
    QUrl urlImage;

};

#endif // CLIENTPROFILE_H
