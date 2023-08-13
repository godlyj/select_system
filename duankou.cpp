#include "duankou.h"
#include "ui_duankou.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QTimer>
#include <QTime>
#include "frmdevice.h"
#include <QTextCodec>
int port_judge=1;
duankou::duankou(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::duankou)
{
    ui->setupUi(this);
    initPort();
    aa=0;
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));//系统调用update函数重绘界面，也可以写自定义的槽函数
    timer->start(1000);

}

duankou::~duankou()
{
    delete ui;
}

/****************************串口初始化*****************************/
void duankou::initPort()
{
    //读取串口信息

    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
       // qDebug()<<"Name:"<<info.portName();
        //qDebug()<<"Description:"<<info.description();
        //qDebug()<<"Manufacturer:"<<info.manufacturer();

        //这里相当于自动识别串口号之后添加到了cmb，如果要手动选择可以用下面列表的方式添加进去
        QSerialPort serial;
        serial.setPort(info);
        if(serial.open(QIODevice::ReadWrite))
        {
            //将串口号添加到cmb
            ui->cmbPortName->addItem(info.portName());
            //ui->cmbPortName->addItem(serial.portName());

            //关闭串口等待人为(打开串口按钮)打开
            serial.close();
        }
    }

    QStringList baudList;//波特率
    QStringList parityList;//校验位
    QStringList dataBitsList;//数据位
    QStringList stopBitsList;//停止位

    baudList<<"50"<<"75"<<"100"<<"134"<<"150"<<"200"<<"300"
           <<"600"<<"1200"<<"1800"<<"2400"<<"4800"<<"9600"
          <<"14400"<<"19200"<<"38400"<<"56000"<<"57600"
         <<"76800"<<"115200"<<"128000"<<"256000";

    ui->cmbBaudRate->addItems(baudList);
    ui->cmbBaudRate->setCurrentIndex(12);
    /*
    parityList<<"无"<<"奇"<<"偶";
    parityList<<"标志";
    parityList<<"空格";

    ui->cmbParity->addItems(parityList);
    ui->cmbParity->setCurrentIndex(0);

    dataBitsList<<"5"<<"6"<<"7"<<"8";
    ui->cmbDataBits->addItems(dataBitsList);
    ui->cmbDataBits->setCurrentIndex(3);

    stopBitsList<<"1";
    stopBitsList<<"1.5";
    stopBitsList<<"2";

    ui->cmbStopBits->addItems(stopBitsList);
    ui->cmbStopBits->setCurrentIndex(0);

    //设置按钮可以被按下
    */
    ui->btnOpen->setCheckable(true);
}

/****************************串口设置******************************/
void duankou::on_btnOpen_clicked()
{

    if(ui->btnOpen->text() == "打开串口")
    {

            if (judge==0) {
               QMessageBox::warning(this,"warning","未成功连接！",QMessageBox::Ok | QMessageBox::Cancel,QMessageBox::Cancel);
            }
            else{
                //设置串口号
                my_serialport-> setPortName(ui->cmbPortName->currentText());
                //以读写方式打开串口
                ui->cmbPortName->setEnabled(false);
                //设置波特率
                my_serialport->setBaudRate(ui->cmbBaudRate->currentText().toInt());
                ui->cmbBaudRate->setEnabled(false);
                /*
                //设置数据位
                my_serialport->setDataBits(QSerialPort::Data8);
                ui->cmbDataBits->setEnabled(false);
                //设置校验位
                my_serialport->setParity(QSerialPort::NoParity);
                ui->cmbParity->setEnabled(false);
                //设置流控制
                my_serialport->setFlowControl(QSerialPort::NoFlowControl);
                ui->comboBox_6->setEnabled(false);
                //设置停止位
                my_serialport->setStopBits(QSerialPort::OneStop);
                ui->cmbStopBits->setEnabled(false);
                */
                //每秒读一次
                port_judge=1;
                QObject::connect(my_serialport, &QSerialPort::readyRead, this, &duankou::readComDataSlot);
                ui->btnOpen->setText(tr("关闭串口"));
            }




    }
    else
    {
        port_judge=0;
        ui->btnOpen->setText(tr("打开串口"));
        ui->cmbBaudRate->setEnabled(true);
        ui->cmbPortName->setEnabled(true);
        /*ui->cmbDataBits->setEnabled(true);
        ui->cmbParity->setEnabled(true);
        ui->comboBox_6->setEnabled(true);
        ui->cmbStopBits->setEnabled(true);*/
        my_serialport->clear();
        my_serialport->close();
        my_serialport->deleteLater();

    }
}
/****************************数据传输******************************/
void duankou::readComDataSlot()
{
    //读取串口数据
    QByteArray readComData = my_serialport->readAll();

    //将读到的数据显示到数据接收区的te中
    //if(readComData != NULL)
    //{
    //     ui->teReceiveData->append(readComData);
    // }

    //清除缓冲区
    readComData.clear();
}
/*
void duankou::on_btnSend_clicked()
{
    //获取发送区的数据
    QString sendData = ui->teSendData->toPlainText();
    QByteArray sendData_2 = sendData.toLatin1();

    //写入缓冲区
    my_serialport->write(sendData_2.data());
}
*/
void duankou::update()

{
          //判断是哪个定时器
      aa++;

}
