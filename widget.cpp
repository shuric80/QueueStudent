#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //setInfoPage();
    url_avator="";
}

void Widget::update(const QByteArray &data){

    QJsonDocument doc = QJsonDocument::fromJson(data);

    {
       QJsonObject obj = doc.object();

        ui->name->setText(obj["first_name"].toString());
        ui->group->setText(obj["group"].toString());
        ui->attendance->setText(obj["attendance"].toString());
        ui->rating->setText(obj["rating"].toString());
       if (url_avator==""){
         url_avator = obj["url"].toString();
         emit sendUrlAvator(url_avator);
         QTimer::singleShot(3000,this,SLOT(setAvator()));
       }
        int len=obj["len"].toInt();
        QJsonObject table = obj["table"].toObject();

for(int i=0;i<len ;++i){
    QJsonObject row = table[QString("row%1").arg(i)].toObject();

 ui->tableWidget->setItem(i,0,new QTableWidgetItem(row["date"].toString()));
 ui->tableWidget->setItem(i,1,new QTableWidgetItem(row["time"].toString()));
 ui->tableWidget->setItem(i,2,new QTableWidgetItem(row["txt"].toString()));

}
    }
}

void Widget::setAvator(){//const QVariantMap *data){
    QPixmap pixmap;
    pixmap.load("image/image.jpg");
    QPixmap resize =pixmap.scaled(QSize(200,150),Qt::KeepAspectRatio);
    ui->avatorka->setPixmap(resize);
}

Widget::~Widget()
{
    delete ui;
}
