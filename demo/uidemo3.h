#ifndef UIDEMO3_H
#define UIDEMO3_H

#include <QDialog>
#include<duankou.h>
#include <shujuku.h>
#include "frmdevice.h"
#include "dialog.h"
#include <setting.h>

extern int Start;

namespace Ui {
class UIDemo3;
}

class UIDemo3 : public QDialog
{
    Q_OBJECT

public:
    explicit UIDemo3(QWidget *parent = 0);
    ~UIDemo3();

private:
    Ui::UIDemo3 *ui;
    bool max;
    QRect location;
    QList<QWidget *> frms;
    duankou *duan_kou;
    shujuku *shu_juku;
    setting *setting;
    frmDevice * frm[100];
    QSqlDatabase DB;
    int y=0;
private slots:
    void initForm();
    void initPanelWidget();
    //void initTableWidget();
    //void initMenu();
    //void doMenu();
    void duankou();
    //void shujuku();
    void start();
    void end();
    void doMenu_test();
    //void timerEvent(QTimerEvent *event);
private slots:
    void on_btnMenu_Min_clicked();
    void on_btnMenu_Max_clicked();
    void on_btnMenu_Close_clicked();
    void on_btnExit_clicked();
    //void on_btnConfig_clicked();
    void on_btnHelp_clicked();
    void on_btnMain_clicked();
};

#endif // UIDEMO3_H
