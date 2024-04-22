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

    QString file_name="config.ini";
    QString app_path=QCoreApplication::applicationDirPath();
    QString config_path=QDir::toNativeSeparators(app_path+QDir::separator()+file_name);
    QSettings settings(config_path,QSettings::IniFormat);
    QString gate_host = settings.value("GateServer/host").toString();
    QString gate_port = settings.value("GateServer/port").toString();

    GateUrlPrefix="http://"+gate_host+":"+gate_port;


    MainWindow w;
    w.show();
    return a.exec();
}
