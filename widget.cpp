#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this, SLOT(setAvator()));
    manager = new QNetworkAccessManager(this);
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(loadAvator(QNetworkReply*)));
   timer->start(1000);
  }

void Widget::update(const QByteArray &data){

    QJsonDocument doc = QJsonDocument::fromJson(data);
        QJsonObject obj = doc.object();
        url.setUrl(obj["url"].toString());
        ui->name->setText(obj["first_name"].toString());
        ui->group->setText(obj["group"].toString());
        ui->attendance->setText(obj["attendance"].toString());
        ui->rating->setText(obj["rating"].toString());
    {
        QJsonObject table = obj["table_busy"].toObject();

        for(int i=0;i<table.size() ;++i){
            QJsonObject row = table[QString("task_%1").arg(i)].toObject();
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(row["date"].toString()));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(row["time"].toString()));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(row["txt"].toString()));

        }
}

 {
            QJsonObject table = obj["table_queued"].toObject();
            for(int i=0;i<table.size() ;++i){

                QJsonObject row = table[QString("task_%1").arg(i)].toObject();
                QPushButton *btn = new QPushButton("Занять");
                btn->setMaximumWidth(150);
                btn->setProperty("row",i);

               ui->tableWidget_2->setItem(i,0,new QTableWidgetItem(row["date"].toString()));
                ui->tableWidget_2->setItem(i,1,new QTableWidgetItem(row["time"].toString()));
                ui->tableWidget_2->setItem(i,2,new QTableWidgetItem(row["txt"].toString()));
                ui->tableWidget_2->setCellWidget(i,3,btn);

               connect(btn,SIGNAL(clicked()),this,SLOT(setQueued()));

            }
}
}

void Widget::setQueued(){
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    if (btn){
        QVariant var = btn->property("row");
        if (var.isValid()){
            qDebug()<< var.toInt();
            emit queued(var.toInt());
        }
    }
}

void Widget::setAvator(){
    manager->get(QNetworkRequest(url));
    QPixmap pixmap;
    pixmap.load("image/image.jpg");
    QPixmap resize =pixmap.scaled(QSize(200,150),Qt::KeepAspectRatio);
    ui->avatorka->setPixmap(resize);
}
void  Widget::loadAvator(QNetworkReply*reply){

    if(reply->error() == QNetworkReply::NoError){
           if (!QDir("image").exists()){
              QDir().mkdir("image");
        };
            QFile file("image/image.jpg");
            file.open(QIODevice::WriteOnly);
            file.write(reply->readAll());
            file.close();
            delete reply;
           }
        else
        {   }
    }

Widget::~Widget()
{
    QFile file("image/image.jpg");
    file.remove();
    file.close();

    delete ui;
}
