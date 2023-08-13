#include "uidemo1.h"
#include "ui_uidemo1.h"
#include "quiwidget.h"

UIDemo1::UIDemo1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UIDemo1)
{
    ui->setupUi(this);


}

UIDemo1::~UIDemo1()
{
    delete ui;
}
void UIDemo1::showCustomDlg(int a)
{

    return;
}
