#include "frmdevice.h"
#include "ui_frmdevice.h"
#include "qfontdatabase.h"
#include "quiwidget.h"
#include "dialog.h"
#include <QDebug>
const QString m_red_SheetStyle = "min-width: 16px; min-height: 16px;max-width:16px; max-height: 16px;border-radius: 8px;  border:1px solid black;background:red";
const QString m_green_SheetStyle = "min-width: 16px; min-height: 16px;max-width:16px; max-height: 16px;border-radius: 8px;  border:1px solid black;background:green";
const QString m_grey_SheetStyle = "min-width: 16px; min-height: 16px;max-width:16px; max-height: 16px;border-radius: 8px;  border:1px solid black;background:grey";
const QString m_yellow_SheetStyle = "min-width: 16px; min-height: 16px;max-width:16px; max-height: 16px;border-radius: 8px;  border:1px solid black;background:yellow";
frmDevice::frmDevice(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmDevice)
{
    ui->setupUi(this);

    //引入图形字体
    int fontId = QFontDatabase::addApplicationFont(":/image/fontawesome-webfont.ttf");
    QString fontName = QFontDatabase::applicationFontFamilies(fontId).at(0);
    QFont iconFont = QFont(fontName);
    iconFont.setPixelSize(15);
//    ui->label->clear();
//    QPalette palette;
//    palette.setColor(QPalette::Background, QColor(0, 0, 0));
//    ui->label->setAutoFillBackground(true);  //一定要这句，否则不行
//    ui->label->setPalette(palette);
    ui->label->setStyleSheet(m_grey_SheetStyle);
    ui->labDevice->setFont(iconFont);
    ui->labDevice->setText(QChar(0xf06c));

    ui->labTemp->setFont(iconFont);
    ui->labTemp->setText(QChar(0xf0eb));

    ui->labDamp->setFont(iconFont);
    ui->labDamp->setText(QChar(0xf043));

    QTimer *timer1 = new QTimer(this);
    connect(timer1, SIGNAL(timeout()), this, SLOT(update()));//系统调用update函数重绘界面，也可以写自定义的槽函数
    timer1->start(1000);
}
void frmDevice::update()

{
          //判断是哪个定时器
      ui->labCurrentTemp->setText(QString(" : %1 ").arg(aa));
      qDebug()<<aa;

}

frmDevice::~frmDevice()
{
    delete ui;
}

void frmDevice::setDeviceName(const QString &deviceName)
{
    ui->labDeviceName->setText(deviceName);
}

void frmDevice::setDeviceTemp(double tempValue)
{
    if(tempValue<=0.5)
        ui->label->setStyleSheet(m_grey_SheetStyle);
    else if(tempValue>0.5&&tempValue<=0.7)
        ui->label->setStyleSheet(m_yellow_SheetStyle);
    else
        ui->label->setStyleSheet(m_red_SheetStyle);
    ui->labCurrentTemp->setText(QString("当前变动: %1 ").arg(tempValue));

}

void frmDevice::setDeviceDamp(double dampValue)
{
    ui->labCurrentDamp->setText(QString("平均变动: %1 ").arg(dampValue));
}

void frmDevice::setCountAll(int countAll)
{
    ui->labCountAll->setText(QString("总条数 : %1").arg(countAll));
}

void frmDevice::setCountNoRead(int countNoRead)
{
    ui->labCountNoRead->setText(QString("未读数 : %1").arg(countNoRead));
}
void frmDevice::setNumber(int num)
{
    number=num;
}

void frmDevice::on_pushButton_clicked()
{
    ui->pushButton->setEnabled(false);
    Dialog* temp = new Dialog(this);
    temp->setnum(number,aa);
    temp->show();
}
void frmDevice::back()
{
    ui->pushButton->setEnabled(true);
}
