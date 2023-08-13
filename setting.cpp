#include "setting.h"
#include "ui_setting.h"
#include <QMessageBox>
#include <duankou.h>
#include <uidemo3.h>
QString school="";
QString teacher="";
QString class_number="";
QString unit="";
QString course="";
int student_number=0;
setting::setting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setting)
{
    ui->setupUi(this);
}

setting::~setting()
{
    delete ui;
}
void setting::on_pushButton_clicked()
{
       if(port_judge==1){
           school = ui->lineEdit->text();
           teacher = ui->lineEdit->text();
           course = ui->lineEdit->text();
           unit = ui->lineEdit->text();
           class_number = ui->lineEdit->text();
           student_number = ui->lineEdit->text().toInt();
           Start=1;
           this->close();
       }
       else{
           QMessageBox::warning(this,"warning","请先连接串口！！",QMessageBox::Ok | QMessageBox::Cancel,QMessageBox::Cancel);
       }
}
