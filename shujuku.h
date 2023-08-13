#ifndef SHUJUKU_H
#define SHUJUKU_H
#include <QDialog>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDriver>
#include <QSqlRecord>

extern int judge;

namespace Ui {
class shujuku;
}

class shujuku : public QDialog
{
    Q_OBJECT

protected:

public:
    explicit shujuku(QWidget *parent = nullptr);
    static void select_from(QString table,QString from);
    static QSqlDatabase db;
    ~shujuku();
private slots:
    //void on_pushButton_clicked();
    //void on_pushButton_2_clicked();

private:
    Ui::shujuku *ui;

};

#endif // SHUJUKU_H
