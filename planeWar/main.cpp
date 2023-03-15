#include "mainscene.h"
#include <QApplication>
#include <QResource>
#include <config.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //注册图片文件资源信息（也可用二进制，文件更小）
    QResource::registerResource(GAME_RES_PATH);

    MainScene w;
    w.show();

    return a.exec();
}
