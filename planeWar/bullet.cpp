#include "bullet.h"
#include <ctime>

Bullet::Bullet()
{
    //加载子弹资源
    int x=rand()%(10);
    if(x%2==0)
        m_Bullet.load(BULLET_PATH);
    if(x%2!=0)
        m_Bullet.load(BULLET_PATH2);

    //子弹坐标
    m_x=GAME_WIDTH*0.5-m_Bullet.width()*0.5;
    m_y=GAME_HEIGHT;

    //子弹的状态 默认空闲
    m_Free=true;

    //子弹速度
    m_Speed=BULLET_SPEED;

    //子弹边框
    m_Rect.setWidth(m_Bullet.width());
    m_Rect.setHeight(m_Bullet.height());
    m_Rect.moveTo(m_x,m_y);

}

void Bullet::updatePosition()
{
    //空闲状态下的子弹，无坐标
    if(m_Free)
    {
        return;
    }
    //子弹向上移动
    m_y-=m_Speed;
    m_Rect.moveTo(m_x,m_y);

    //子弹位置超出窗口，变为空闲
    if(m_y<=-m_Rect.height())
    {
        m_Free=true;
    }
}
