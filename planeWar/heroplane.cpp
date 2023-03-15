#include "heroplane.h"
#include "config.h"

HeroPlane::HeroPlane()
{
    //初始化加载飞机的资源
    m_Plane.load(HERO_PATH);

    //初始化飞机坐标
    m_x=(GAME_WIDTH-m_Plane.width())*0.5;
    m_y=GAME_HEIGHT-m_Plane.height();

    //初始化矩形边框
    m_Rect.setWidth(m_Plane.width());
    m_Rect.setHeight(m_Plane.height());
    m_Rect.moveTo(m_x,m_y);
}

void HeroPlane::shoot()
{
    //累加时间间隔记录变量
    m_recorder++;

    //如果记录的数字，未达到发射子弹时间间隔，则不发射return
    if(m_recorder<BULLET_INTERVAL)
    {
        return;
    }

    //达到发射时间 发射子弹
    m_recorder=0;
    for(int i=0;i<BULLET_NUM;i++)
    {
        //如果是空闲的子弹就发射
        if(m_bullets[i].m_Free)
        {
            //将空闲子弹状态改为非空闲
            m_bullets[i].m_Free=false;
            //设置子弹坐标
            m_bullets[i].m_x=m_x+m_Rect.width()*0.5;
            m_bullets[i].m_y=m_y;
            break;
        }
    }

}

void HeroPlane::setPosition(int x, int y)
{
    m_x=x;m_y=y;
    m_Rect.moveTo(m_x,m_y);
}
