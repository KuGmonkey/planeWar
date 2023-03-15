#ifndef MAP_H
#define MAP_H
#include <QPixmap>
#include <QRect>

class Map
{
public:
    //构造函数
    Map();

    //地图滚动坐标计算
    void mapPosition();

    //地图图片对象
    QPixmap m_map1;
    QPixmap m_map2; //需要地图滚动就设置俩，静态地图只需一个
    QPixmap m_STOP; //暂停图标的设置

    //地图Y轴坐标
    int m_map1_posy;
    int m_map2_posy;
   //暂停图标的位置
    int m_STOP_x=0;
    int m_STOP_y=0;

    //暂停的矩形边框
    QRect m_Rect;

    //地图滚动幅度
    int m_scroll_speed;

    //游戏暂停状态更新
    void m_Stop_Free();

};

#endif // MAP_H
