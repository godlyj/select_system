#include "shujuku.h"
#include "ui_shujuku.h"
#include <QLineEdit>
#include <QTextCodec>
#include <QMessageBox>
#include<QDebug>
extern int judge=0;
QSqlDatabase shujuku::db= QSqlDatabase::addDatabase("QMYSQL");
//shujuku::db = QSqlDatabase::addDatabase("QMYSQL");
shujuku::shujuku(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::shujuku)
{
    ui->setupUi(this);
    ui->lineEdit_4->setEchoMode(QLineEdit::Password);
    ui->pushButton_2->setEnabled(false);
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
    db.setHostName("localhost");
    db.setDatabaseName("data");       //这里输入你的数据库名
    db.setUserName("root");
    db.setPassword("lyj102899");   //这里输入你的密码
    if (!db.open()) {
        qDebug() << db.lastError();
    }
    else{
        judge=1;
        qDebug() << "success";
        QSqlQuery query(db);
        // 使数据库支持中文
        query.exec("SET NAMES 'Latin1'");
        query.exec("insert into course2 values(10, '数学', '刘老师')");
    }

}

shujuku::~shujuku()
{
    delete ui;
}


void shujuku::select_from(QString table,QString from)
{
    qDebug()<<table<<from;

    QStringList namelist;//储存所有名字
    if(db.isOpen())
    {

        QSqlQuery query(db);//查找表MANAGER_INFO中的ManagerName这一列   SELECT ManagerName FROM MANAGER_INFO
        query.exec("select number from test");
        while(query.next())//query指向下一条记录，每执行一次该函数，便指向相邻的下一条记录。
        {//QStringList    QList<QString>
            //1. 过度下在追加到namelist中
            //name = query.value(0).toString();//查询表MANAGER_INFO字段
            // namelist<<name;//把获取的名字追加到字符串链表中
            //2. 直接追加到namelist中
            namelist<<query.value(0).toString();//查询表MANAGER_INFO字段
            qDebug()<<"namelist="<<namelist[0];
        }

    }



}
