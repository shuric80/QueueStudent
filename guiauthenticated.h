#ifndef GUIAUTHENTICATED_H
#define GUIAUTHENTICATED_H
#include <QDialog>
#include <QStringList>
#include <QAbstractButton>
#include <QDebug>

namespace Ui {
class GuiAuthenticated;
}

class GuiAuthenticated : public QDialog
{
    Q_OBJECT

public:
    explicit GuiAuthenticated(QWidget *parent = 0);
    ~GuiAuthenticated();
public slots:
    void error(const QString&);

private:
    Ui::GuiAuthenticated *ui;
private slots:
    void submit();
    void cancel();
signals:
    void setAuth(const QStringList&);

};

#endif // GUIAUTHENTICATED_H
