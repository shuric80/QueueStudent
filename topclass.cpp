#include "topclass.h"

TopClass::TopClass(QObject *parent) :
    QObject(parent)
{
    client = new ClientProfile;
    profile = new Widget;
    initialize();
}

void TopClass::initialize()
{
    auth = new GuiAuthenticated;
    auth->show();
    connect(auth,SIGNAL(setAuth(const QStringList)),client,SLOT(authenticated(const QStringList&)));
    connect(client,SIGNAL(errorNetwork(const QString&)),auth,SLOT(error(const QString&)));
    connect(client,SIGNAL(readServer(const QByteArray&)), profile,SLOT(update(const QByteArray&)));
    connect(client,SIGNAL(errorNetwork(const QString&)),this,SLOT(succesAuth(const QString&)));
    connect(profile,SIGNAL(sendUrlAvator(const QString&)), client,SLOT(setImage(const QString&)));
}

void TopClass::succesAuth(const QString &cod){
    qDebug()<<cod;
    if (cod=="OK"){
        disconnect(auth,SIGNAL(setAuth(const QStringList)),client,SLOT(authenticated(const QStringList&)));
        disconnect(client,SIGNAL(errorNetwork(const QString&)),auth,SLOT(error(const QString&)));
        disconnect(client,SIGNAL(errorNetwork(const QString&)),this,SLOT(succesAuth(const QString&)));

        auth->deleteLater();
        profile->show();
    }
}
