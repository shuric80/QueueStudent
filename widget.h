#ifndef WIDGET_H
#define WIDGET_H
#include <QPainter>
#include <QWidget>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QDebug>
#include <QTimer>
#include <QPushButton>
#include <QFile>
#include <QTimer>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QDir>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
signals:
      void queued(int);
public slots:
    void update(const QByteArray &);
    void setAvator();//const QVariantMap*);
    void setQueued();
    void loadAvator(QNetworkReply *);
private:
    QNetworkAccessManager *manager;
    QUrl url;
    Ui::Widget *ui;
    QTimer *timer;
};

#endif // WIDGET_H
