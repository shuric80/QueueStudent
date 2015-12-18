#include "client.h"

Client::Client(QObject *parent):QObject(parent)
{
    manager = new QNetworkAccessManager(this);
    //connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(replyFinished(QNetworkReply*)));

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
}

void Client::replyFinished(QNetworkReply *ret){


 }

void Client::authenticate(const QVariantMap *list){



}

void Client::send(){



}
void Client::update(){



}

void Client::requestError(QNetworkReply::NetworkError){



}
