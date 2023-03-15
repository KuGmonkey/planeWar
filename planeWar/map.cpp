#include "map.h"
#include "config.h"
extern int op;
extern int temp;


Map::Map()
{
    //初始化地图加载地图对象
    m_map1.load(MAP_PATH);
    m_map2.load(MAP_PATH);
    //初始化暂停图标
    m_STOP.load(STOP_PATH1);

    //初始化暂停矩形边框
    m_Rect.setWidth(m_STOP.width());
    m_Rect.setHeight(m_STOP.height());

    //初始化Y轴坐标
    m_map1_posy=-GAME_HEIGHT;
    m_map2_posy=0;

    //地图滚动速度
    m_scroll_speed=MAP_SCOLL_SPEED;

}

void Map::mapPosition()
{
    //处理第一张图片滚动位置
    m_map1_posy+=m_scroll_speed;
    if(m_map1_posy>=0)
    {
        m_map1_posy=-GAME_HEIGHT;
    }
    //处理第二张图片滚动位置
    m_map2_posy+=m_scroll_speed;
    if(m_map2_posy>=GAME_HEIGHT)
    {
        m_map2_posy=0;
    }
}

//游戏暂停状态
void Map::m_Stop_Free()
{
    //鼠标左键事件发生时，temp改变，进而改变op值，即暂停状态
    op=temp;
}



