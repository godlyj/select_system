#ifndef DUANKOU_H
#define DUANKOU_H

#include <QDialog>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <shujuku.h>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDriver>
#include <QSqlRecord>


extern int port_judge;

namespace Ui {
class duankou;
}

class duankou : public QDialog
{
    Q_OBJECT

public:
    explicit duankou(QWidget *parent = nullptr);
    ~duankou();

private slots:
    void initPort();
    void on_btnOpen_clicked();
    void readComDataSlot();
    //void on_btnSend_clicked();
    void update();
private:
    Ui::duankou *ui;
    int a;
    QSerialPort *my_serialport;

};

#endif // DUANKOU_H
