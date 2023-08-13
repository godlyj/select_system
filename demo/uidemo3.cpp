#include "uidemo3.h"
#include "ui_uidemo3.h"
#include "quiwidget.h"
#include "qtimer.h"
#include "duankou.h"
#include <help.h>
#include "shujuku.h"
#include <uidemo3.h>
int aa;
int Start=0;
//x轴&y轴

UIDemo3::UIDemo3(QWidget *parent) :
    QDialog(parent,Qt::WindowTitleHint | Qt::CustomizeWindowHint),
    ui(new Ui::UIDemo3)
{
    Sleep(1500);
    Start=0;
    ui->setupUi(this);
    this->initForm();
    //this->initTableWidget();
    //this->initMenu();
    QUIWidget::setFormInCenter(this);
    QTimer::singleShot(100, this, SLOT(initPanelWidget()));
    QGridLayout* layout = new QGridLayout();
    layout->addWidget(ui->widgetPanel,0, 0);
    ui->tab->setLayout(layout);
    duan_kou = new class duankou;
    shu_juku = new class shujuku;
    setting = new class setting;
    shujuku::select_from(QString("123"),QString("123"));
    startTimer(1000);


}

UIDemo3::~UIDemo3()
{
    delete ui;
}
/*
void UIDemo3::timerEvent(QTimerEvent *event){ // event 表示当前运行的定时器
    int j;


    if(all==1)
    for(j=0;j<50;j++){
        QTime time;
        time= QTime::currentTime();
        qsrand(time.msec()+time.second()*1000);
        int n = qrand() % 10;
        Sleep(1);
        frm[j]->setDeviceDamp(n);
        frm[j]->setDeviceTemp(double(n/10.0));
    }
    if(event->timerId()==m_timerId){
            int num=abs(rand()%30+1);
            m_x++;
            qDebug()<<"m_x:"<<m_x<<"  "<<"m_lowPos:"<<m_lowPos;
            splineSeries->append(m_x,num);
            scatterSeries->append(m_x,num);
            m_axisX->setRange(0,m_x);
            m_axisY->setRange(0,35);

            if(m_x-30>m_lowPos){
                m_axisX->setRange(m_lowPos++,m_x);

            }

        }

}*/
void UIDemo3::initForm()
{
    this->max = false;
    this->location = this->geometry();
    this->setProperty("form", true);
    //this->setProperty("canMove", true);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);
    //设置主题图标
    QImage *img=new QImage; //新建一个image对象
    img->load(":/3.png"); //将图像资源载入对象img，注意路径，可点进图片右键复制路径
    QPixmap pixmap =QPixmap::fromImage(*img);
    pixmap=pixmap.scaled(QSize(64,64),Qt::KeepAspectRatio,Qt::SmoothTransformation);

    ui->labIco->setPixmap(pixmap);
    ui->labIco->setScaledContents(true);


    //IconHelper::Instance()->setIcon(QChar(0xF099), 30);
//    IconHelper::Instance()->setIcon(ui->btnMenu_Min, QChar(0xF068));
//    IconHelper::Instance()->setIcon(ui->btnMenu_Max, QChar(0xF067));
//    IconHelper::Instance()->setIcon(ui->btnMenu_Close, QChar(0xF00d));

    ui->widgetTitle->setProperty("form", "title");
    ui->widgetTop->setProperty("nav", "top");
    ui->labTitle->setText("课堂质量评估系统");
    ui->labTitle->setFont(QFont("Microsoft Yahei", 20));
    this->setWindowTitle(ui->labTitle->text());

    QSize icoSize(32, 32);
    int icoWidth = 85;

    //设置顶部导航按钮
    QList<QToolButton *> tbtns = ui->widgetTop->findChildren<QToolButton *>();
    foreach (QToolButton *btn, tbtns) {
        btn->setIconSize(icoSize);
        btn->setMinimumWidth(icoWidth);
    }


   //包裹控件的布局

    ui->splitterH->setStretchFactor(0,1);
    QList<int> widths;
    widths << 170 << 650;
    ui->splitterH->setSizes(widths);
    QList<int> heights;
    heights << 400 << 200;
    ui->splitterV->setSizes(heights);
}


void UIDemo3::initPanelWidget()
{
    //加载设备面板
    qDeleteAll(frms);
    frms.clear();

    for (int i = 0; i < 50; i++) {
        frm[i] = new frmDevice;
        frm[i]->setFixedHeight(100);
        frm[i]->setNumber(i+1);
        frm[i]->setDeviceName(QString("学生编号 %1").arg(i + 1));
        frm[i]->setDeviceTemp(0);
        frm[i]->setDeviceDamp(0);
        frm[i]->setCountAll(1024);
        frm[i]->setCountNoRead(1);
        frms.append(frm[i]);
    }

    ui->widgetPanel->setWidget(frms, 5);
    ui->widgetPanel->setMargin(3);
    ui->widgetPanel->setSpacing(3);
}
/*

void UIDemo3::initTableWidget()
{
    //设置列数和列宽
    int width = qApp->desktop()->availableGeometry().width() - 120;
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setColumnWidth(0, width * 0.06);
    ui->tableWidget->setColumnWidth(1, width * 0.10);
    ui->tableWidget->setColumnWidth(2, width * 0.06);
    ui->tableWidget->setColumnWidth(3, width * 0.10);
    ui->tableWidget->setColumnWidth(4, width * 0.15);
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(25);

    QStringList headText;
    headText << "学生编号" << "学生名称" << "设备编号" << "告警内容" << "告警时间";
    ui->tableWidget->setHorizontalHeaderLabels(headText);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setAlternatingRowColors(true);
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    //设置行高
    ui->tableWidget->setRowCount(300);

    for (int i = 0; i < 300; i++) {
        ui->tableWidget->setRowHeight(i, 24);

        QTableWidgetItem *itemDeviceID = new QTableWidgetItem(QString::number(i + 1));
        QTableWidgetItem *itemDeviceName = new QTableWidgetItem(QString("测试设备%1").arg(i + 1));
        QTableWidgetItem *itemDeviceAddr = new QTableWidgetItem(QString::number(i + 1));
        QTableWidgetItem *itemContent = new QTableWidgetItem("坐姿警告");
        QTableWidgetItem *itemTime = new QTableWidgetItem(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));

        itemDeviceID->setTextAlignment(Qt::AlignCenter);
        itemDeviceName->setTextAlignment(Qt::AlignCenter);
        itemDeviceAddr->setTextAlignment(Qt::AlignCenter);
        itemContent->setTextAlignment(Qt::AlignCenter);

        ui->tableWidget->setItem(i, 0, itemDeviceID);
        ui->tableWidget->setItem(i, 1, itemDeviceName);
        ui->tableWidget->setItem(i, 2, itemDeviceAddr);
        ui->tableWidget->setItem(i, 3, itemContent);
        ui->tableWidget->setItem(i, 4, itemTime);
    }
}

void UIDemo3::initMenu()
{
    QMenu *menu = new QMenu(this);
    menu->addAction("开始运行", this, SLOT(start()));
    menu->addAction("终止运行", this, SLOT(end()));
    menu->addSeparator();
    //menu->addAction("数据库管理", this, SLOT(shujuku()));
    menu->addAction("串口管理", this, SLOT(duankou()));
    ui->btnMain->setPopupMode(QToolButton::InstantPopup);
    ui->btnMain->setMenu(menu);
}
*/


void UIDemo3::duankou()
{
    duan_kou->exec();
}

void UIDemo3::start()
{

}
void UIDemo3::end()
{

}

void UIDemo3::doMenu_test()
{
    shujuku::select_from(QString("123"),QString("123"));
}


void UIDemo3::on_btnMenu_Min_clicked()
{
    showMinimized();
}

void UIDemo3::on_btnMenu_Max_clicked()
{
    if (max) {
        this->setGeometry(location);
        this->setProperty("canMove", true);
    } else {
        location = this->geometry();
        this->setGeometry(qApp->desktop()->availableGeometry());
        this->setProperty("canMove", false);
    }

    max = !max;
}

void UIDemo3::on_btnMenu_Close_clicked()
{
    close();
}

void UIDemo3::on_btnExit_clicked()
{
   qApp->exit(0);
}

void UIDemo3::on_btnHelp_clicked()
{
    duan_kou->exec();
}


void UIDemo3::on_btnMain_clicked()
{
    if(ui->btnMain->text() == "开始上课"){
        setting->exec();
        if(Start==1)
        ui->btnMain->setText(tr("结束上课"));
    }
    else
    {
        ui->btnMain->setText(tr("开始上课"));
        Start=0;
    }

}
