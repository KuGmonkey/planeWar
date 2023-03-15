#include "enemyplane.h"
#include "config.h"
#include <ctime>

EnemyPlane::EnemyPlane()
{
    //敌机资源加载
    int x=rand()%(10);
    if(x%2==0)
        m_enemy.load(ENEMY_PATH);
    if(x%2!=0)
        m_enemy.load(ENEMY_PATH2);

    //敌机位置
    m_x=0;
    m_y=0;

    //敌机状态
    m_Free=true;

    //敌机速度
    m_Speed=ENEMY_SPEED;

    //敌机矩形边框（碰撞检测）
    m_Rect.setWidth(m_enemy.width());
    m_Rect.setHeight(m_enemy.height());
    m_Rect.moveTo(m_x,m_y);
}

void EnemyPlane::updatePosition()
{
    //空闲状态敌机 不计算坐标
    if(m_Free)
    {
        return;
    }

    //非空闲敌机
    m_y+=m_Speed;
    m_Rect.moveTo(m_x,m_y);

    //如果超出屏幕 重置状态
    if(m_y>=GAME_HEIGHT+m_Rect.height())
    {
        m_Free=true;
    }

}
