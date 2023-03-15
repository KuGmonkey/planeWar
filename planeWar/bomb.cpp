#include "bomb.h"

Bomb::Bomb()
{
    //将所有爆炸的图片存放在数组中
    for(int i=1;i<=BOMB_MAX;i++)
    {
        //str 类似于 ":/res/bomb-%1.png"
        QString str=QString(BOMB_PATH).arg(i);
        m_pixArr.push_back(QPixmap(str));
    }
    //坐标
    m_x=0;m_y=0;

    //空闲状态
    m_Free=true;

    //当前播放的图片下标
    m_index=0;

    //播放爆炸的间隔的记录
    m_Recorder=0;
}

void Bomb::updateInfo()
{
    //空闲状态则不需要爆炸 直接return
    if(m_Free)
    {
        return;
    }

    //非空闲状态
    m_Recorder++;
    //若爆炸时间未到达爆炸间隔 则不需要爆炸
    if(m_Recorder<BOMB_INTERVAL)
    {
        return;
    }

    //若达到爆炸间隔 重置记录
    m_Recorder=0;
    //切换爆炸播放的图片的下标
    m_index++;

    if(m_index>BOMB_MAX - 1)   //数组中下标从0开始
    {
        m_index=0;
        m_Free=true;
    }
}
