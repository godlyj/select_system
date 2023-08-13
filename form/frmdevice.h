#ifndef FRMDEVICE_H
#define FRMDEVICE_H

#include <QWidget>
#include "dialog.h"
extern int aa;
namespace Ui {
class frmDevice;
}

class frmDevice : public QWidget
{
    Q_OBJECT

public:
    explicit frmDevice(QWidget *parent = 0);
    ~frmDevice();

    void setDeviceName(const QString &deviceName);
    void setDeviceTemp(double tempValue);
    void setDeviceDamp(double dampValue);
    void setCountAll(int countAll);
    void setCountNoRead(int countNoRead);
    void setNumber(int num);
    void update();
    void back();


private slots:
    void on_pushButton_clicked();

private:
    Ui::frmDevice *ui;
    int number;
    int t;

};

#endif // FRMDEVICE_H
