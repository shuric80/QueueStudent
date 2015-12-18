#include "clientprofile.h"
#include <QJsonDocument>
#include <QJsonObject>

ClientProfile::ClientProfile(QObject *parent):QObject(parent)
{
    manager = new QNetworkAccessManager(this);
    img_manager = new QNetworkAccessManager(this);

    connect(manager,SIGNAL(finished(QNetworkReply*)),this, SLOT(slotFinished(QNetworkReply*)));
    connect(img_manager,SIGNAL(finished(QNetworkReply*)), this,SLOT(loadImage(QNetworkReply*)));

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateProfile()));

    _login = "";
    _password = "";

    _url = URL;

   // setImage("http://mirgif.com/humor/prikol104.jpg");
}

void ClientProfile::slotFinished(QNetworkReply *ret){
    if (ret->error() ==QNetworkReply::NoError)
    {
        QByteArray content =ret->readAll();
        QTextCodec *codec = QTextCodec::codecForName("cp1251");
        if(DEBUG){
            //qDebug() << codec->toUnicode(content.data());
                    }
        if (content.data() =="ERROR"){
            emit errorNetwork("login");
            timer->stop();
        }
        else{
          emit readServer(content.data());
          emit errorNetwork("OK");

    }}

    else
    {
        emit errorNetwork("network");
        timer->stop();
        qDebug()<<ret->errorString();
       }

    delete ret;
}

void ClientProfile::loadImage(QNetworkReply* reply){
    qDebug()<<"load";
    if(reply->error() == QNetworkReply::NoError){
        QFile file("image/image.jpg");
        file.open(QIODevice::WriteOnly);
        file.write(reply->readAll());
        file.close();
        delete reply;
       }
    else
    {   }
}

void ClientProfile::setImage(const QString& url){
    qDebug()<<url;
    urlImage.setUrl(url);
    img_manager->get(QNetworkRequest(url));
}

void ClientProfile::updateProfile(){
   send();
}

void ClientProfile::authenticated(const QStringList auth){
_login = auth.at(0);
_password = auth.at(1);

timer->start(TIMEOUT_UPDATE);
}

void ClientProfile::send(){
    QString request = QString("%1/login/?username=%2&password=%3").arg(_url).arg(_login).arg(_password);
    manager->get(QNetworkRequest(QUrl(request)));
}
