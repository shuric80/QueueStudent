#ifndef TOPCLASS_H
#define TOPCLASS_H

#include <QObject>
#include "guiauthenticated.h"
#include "widget.h"
#include "clientprofile.h"
#include <QDebug>

class TopClass : public QObject
{
    Q_OBJECT
public:
    explicit TopClass(QObject *parent = 0);
public slots:
    void succesAuth(const QString&);
private:
    void initialize();
    Widget *profile;
    GuiAuthenticated *auth;
    ClientProfile *client;


};

#endif // TOPCLASS_H
