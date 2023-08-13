#ifndef UIDEMO1_H
#define UIDEMO1_H

#include <QDialog>

namespace Ui {
class UIDemo1;
}

class UIDemo1 : public QDialog
{
    Q_OBJECT

public:
    explicit UIDemo1(QWidget *parent = 0);
    ~UIDemo1();

private:
    Ui::UIDemo1 *ui;
private slots:
    void showCustomDlg(int a);

};

#endif // UIDEMO1_H
