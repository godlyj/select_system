#ifndef PERSON_INFORMATION_H
#define PERSON_INFORMATION_H

#include <QWidget>

namespace Ui {
class person_information;
}

class person_information : public QWidget
{
    Q_OBJECT

public:
    explicit person_information(QWidget *parent = nullptr);
    ~person_information();

private:
    Ui::person_information *ui;
};

#endif // PERSON_INFORMATION_H
