#include "mainwindow.h"

#include <QApplication>

const QString key = "希両_V1.000";

int main(int argc, char *argv[])
{
    QSystemSemaphore semaphore(key, 1, QSystemSemaphore::Create);

    // 尝试获取信号量
    if (!semaphore.acquire()) {
        return -1;
    }

    QApplication a(argc, argv);
    QObject::connect(&a, &QCoreApplication::aboutToQuit, [&semaphore]() {
        semaphore.release();
    });
    MainWindow w;
    w.show();
    return a.exec();
}
