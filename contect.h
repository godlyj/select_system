#ifndef CONTECT_H
#define CONTECT_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDriver>
#include <QSqlRecord>

class contect
{
public:
    contect();
private:
    QSqlDatabase db;
};

#endif // CONTECT_H
