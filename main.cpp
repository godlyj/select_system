#include "form/quiwidget.h"
#include "form/quicreator.h"
#include "demo/appinit.h"
#include <QApplication>
#include "uidemo3.h"
#include "quiwidget.h"
#include <QPixmap>
#include <QSplashScreen>
//#include <unistd.h>
#include <QWidget>
int main(int argc, char *argv[])
{
#if (QT_VERSION >= QT_VERSION_CHECK(5,6,0))
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QApplication a(argc, argv);

    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/1.png"));
//    QFont font;
//    font.setFamily("宋体");
//    font.setPixelSize(50);
//    splash->setFont(font);
    splash->show();
    splash->showMessage("Wait...");
    Qt::Alignment topRight = Qt::AlignRight | Qt::AlignTop;

    splash->showMessage(QObject::tr("Setting up the main window..."),topRight, Qt::red);
    a.processEvents();

    a.setFont(QFont("Microsoft Yahei", 9));
    a.setWindowIcon(QIcon(":/main2.ico"));
    QUIWidget::setStyle(QUIWidget::Style_FlatWhite);
    QUIWidget::setCode();
    QUIWidget::setTranslator(":/image/qt_zh_CN.qm");
    QUIWidget::setTranslator(":/image/widgets.qm");
    AppInit::Instance()->start();

    //读取配置文件
    //QUIConfig::ConfigFile = QString("%1/%2").arg(QUIWidget::appPath()).arg("qui_config.ini");
    //QUIConfig::ReadConfig();

    QUIWidget qui;
    UIDemo3 *creator = new UIDemo3;

    //设置主窗体
    //qui.setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint);
    qui.setMainWidget(creator);
    QObject::connect(&qui, SIGNAL(changeStyle(QString)), creator, SLOT(changeStyle(QString)));


    //设置标题文本居中
    qui.setAlignment(Qt::AlignCenter);

    //设置窗体可拖动大小
    qui.setSizeGripEnabled(true);

    //设置换肤下拉菜单可见
    qui.setVisible(QUIWidget::BtnMenu, true);

    //设置标题栏高度
    //qui.setTitleHeight(50);

    //设置按钮宽度
    //qui.setBtnWidth(50);

    //设置左上角图标-图形字体
    //qui.setIconMain(QChar(0xf099), 11);

    //设置左上角图标-图片文件
    //qui.setPixmap(QUIWidget::Lab_Ico, ":/main.ico");

    qui.show();
    splash->finish(&qui);
    delete splash;
    return a.exec();
}
