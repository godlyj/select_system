#ifndef DIALOG_H
#define DIALOG_H
#include "quiwidget.h"
#include <QDialog>
#include <QtCharts>
#include "QtCharts/QChart"
#include "frmdevice.h"
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void setnum(int a,int aa);
    void timerEvent(QTimerEvent *event);
    void dataReceived(int value);

protected:

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
    int num;
    int timerId;
    QLineSeries *m_series1;
    QChart *m_chart;
    QSplineSeries *splineSeries ;
    QScatterSeries *scatterSeries;
    //x轴&y轴
    QValueAxis *m_axisX;
    QValueAxis *m_axisY;

    int m_x;

    int m_timerId;
    int m_lowPos;


};

#endif // DIALOG_H
