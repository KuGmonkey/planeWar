#ifndef HEROPLANE_H
#define HEROPLANE_H
#include<QPixmap>
#include<QRect>
#include "bullet.h"


class HeroPlane
{
public:
    HeroPlane();

    //发射子弹
    void shoot();

    //设置飞机位置
    void setPosition(int x,int y);

    //飞机资源 对象
    QPixmap m_Plane;

    //飞机坐标
    int m_x;
    int m_y;

    //飞机的矩形边框
    QRect m_Rect;

    //弹匣
    Bullet m_bullets[BULLET_NUM];

    //发射时间间隔
    int m_recorder=0;
};

#endif // HEROPLANE_H
