#include "dialog.h"
#include "ui_dialog.h"
#include "QTimer"
#include "QTime"
#include "QList"
#include "qmath.h"
#include "QPointF"
#include "QDebug"
#include "frmdevice.h"
#include <ctime>
//QChartView *chartView;
int id;
//QChart* m_chart;
//QValueAxis *m_axisX;
//QValueAxis* m_axisY;
//QLineSeries *m_series;
Dialog::Dialog(QWidget *parent) :
    QDialog(parent,Qt::WindowTitleHint | Qt::CustomizeWindowHint),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
//setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint);
    id=startTimer(1000);
    srand((unsigned)time(NULL));
    m_series1=new QLineSeries();
        splineSeries = new QSplineSeries();
        splineSeries->setUseOpenGL(true);
        scatterSeries = new QScatterSeries();
        scatterSeries->setMarkerSize(8);
        QPen pen(QColor(120,152,2));
        splineSeries->setPen(pen);
        splineSeries->setName(tr("变化量"));

        m_chart=new QChart();
        m_chart->addSeries(splineSeries);
        m_chart->addSeries(scatterSeries);
        m_chart->createDefaultAxes();
        m_chart->setTitle(tr("动态折线图"));

        //设置坐标
        m_axisX=new QValueAxis();
        m_axisX->setTitleText(tr("时间/秒"));

        m_axisY=new QValueAxis();
        m_axisY->setTitleText(tr("次数/个"));

        m_chart->setAxisX(m_axisX,splineSeries);
        m_chart->setAxisY(m_axisY,splineSeries);
        QChartView *view = new QChartView(m_chart);
        view->setRenderHint(QPainter::Antialiasing);
        ui->verticalLayout->addWidget(view);
        m_timerId=startTimer(1000);
        m_x=0;m_lowPos=20;
        int j;
        for(j=0;j<20;j++){
            int num=abs(rand()%30+1);

            //qDebug()<<"m_x:"<<m_x<<"  "<<"m_lowPos:"<<m_lowPos;
            splineSeries->append(m_x,num);
            scatterSeries->append(m_x,num);
            m_axisX->setRange(0,m_x);
            m_axisY->setRange(0,35);m_x++;
        }


}
void Dialog::timerEvent(QTimerEvent *event){ // event 表示当前运行的定时器
//    if(event->timerId() == id){
//        ui->label->setText(QString("这是 学生%1 的具体情况  %2").arg(num).arg(aa));
//        qsrand(time(NULL));
//        series->append(aa,qrand() % 10);
//        chart->addSeries(series);
//        QChartView *view = new QChartView(chart);
//        // 开启抗锯齿，让显示效果更好
//        view->setRenderHint(QPainter::Antialiasing);
//        ui->verticalLayout->addWidget(view);
//        // 显示图表
//        view->show();
//    }
//在可视的情况下刷新数据
    if(event->timerId()==m_timerId){
            int num=abs(rand()%30+1);
            m_x++;
            //qDebug()<<"m_x:"<<m_x<<"  "<<"m_lowPos:"<<m_lowPos;
            splineSeries->append(m_x,num);
            scatterSeries->append(m_x,num);
            m_axisX->setRange(0,m_x);
            m_axisY->setRange(0,35);

            if(m_x-30>m_lowPos){
                m_axisX->setRange(m_lowPos++,m_x);

            }

        }


}
Dialog::~Dialog()
{
    delete ui;
}
void Dialog::setnum(int a, int aa){
    num=a;
    ui->label->setText(QString("这是 学生%1 的具体情况  %2").arg(num).arg(aa));
//    series->append(QPointF(2,6));
//    series->append(3,8);
//    series->append(7,9);
//    series->append(11,3);
//    *series << QPointF(11,2) << QPointF(15,5) << QPointF(18,4) << QPointF(19,2);

}

void Dialog::dataReceived(int value) {
//    data << value;
//    // 数据个数超过了最大数量，则删除最先接收到的数据，实现曲线向前移动
//    while (data.size() > maxSize) {
//        data.removeFirst();
//    }
//    // 界面被隐藏后就没有必要绘制数据的曲线了
//    if (isVisible()) {
//        splineSeries->clear();
//        scatterSeries->clear();
//        int dx = maxX / (maxSize-1);
//        int less = maxSize - data.size();
//        for (int i = 0; i < data.size(); ++i) {
//            splineSeries->append(less*dx+i*dx, data.at(i));
//            scatterSeries->append(less*dx+i*dx, data.at(i));
//        }
//    }
}

void Dialog::on_pushButton_clicked()
{
    frmDevice *ptr = (frmDevice*)parentWidget();
    ptr->back();
    this->close();
}
