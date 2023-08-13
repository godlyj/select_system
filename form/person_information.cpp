#include "person_information.h"
#include "ui_person_information.h"

person_information::person_information(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::person_information)
{
    ui->setupUi(this);
}

person_information::~person_information()
{
    delete ui;
}
