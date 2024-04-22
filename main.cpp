/******************************************************************************
 *
 * @file       main.cpp
 * @brief      XXXX Function
 *
 * @author     outoflu
 * @date       2024/04/09
 * @history
 *****************************************************************************/
#include "mainwindow.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile qss(":/style/stylesheet.qss");
    if (qss.open(QFile::ReadOnly)){
        //logger.get()->debug("open qss file success");
        QString style=QLatin1String(qss.readAll());
        a.setStyleSheet(style);
        qss.close();
    }else {
        //logger.get()->error("open qss file faild\n");
    }
    MainWindow w;
    w.show();
    return a.exec();
}
