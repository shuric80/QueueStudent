#ifndef WIDGET_H
#define WIDGET_H
#include <QPainter>
#include <QWidget>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QDebug>
#include <QTimer>

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
    void sendUrlAvator(const QString &);
public slots:
    void update(const QByteArray &);
    void setAvator();//const QVariantMap*);
private:
    Ui::Widget *ui;
    QString url_avator;
};

#endif // WIDGET_H
