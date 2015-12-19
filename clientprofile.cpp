#include "clientprofile.h"
#include <QJsonDocument>
#include <QJsonObject>

ClientProfile::ClientProfile(QObject *parent):QObject(parent)
{
    manager = new QNetworkAccessManager(this);
   connect(manager,SIGNAL(finished(QNetworkReply*)),this, SLOT(slotFinished(QNetworkReply*)));

    timer = new QTimer(this);
     connect(timer,SIGNAL(timeout()),this,SLOT(updateProfile()));

    _login = "";
    _password = "";
    _task ="";
    _url = URL;

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

void ClientProfile::setQueued(int id_task){
     _task = QString("&queued=%1").arg(id_task);

}


void ClientProfile::updateProfile(){
   send();
}

void ClientProfile::authenticated(const QStringList auth){
_login = auth.at(0);
_password = auth.at(1);

 timer->start(TIMEOUT_UPDATE);
// timer->start(0);
}

void ClientProfile::send(){
    QString request = QString("%1/login/?username=%2&password=%3%4")
            .arg(_url)
            .arg(_login)
            .arg(_password)
            .arg(_task);
    manager->get(QNetworkRequest(QUrl(request)));
    _task="";
}
