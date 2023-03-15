#include "mainscene.h"
#include"config.h"
#include"map.h"
#include <QIcon>
#include <QPainter>
#include <QMouseEvent>
#include <ctime>
#include <QSound>

//游戏是否暂停状态
int op=1;
//检测鼠标左键事件
int temp=1;

MainScene::MainScene(QWidget *parent)
    : QWidget(parent)
{
    //调用初始化场景
    initScene();

        //启动游戏
        playGame();
}

MainScene::~MainScene()
{

}

void MainScene::initScene() //初始化场景
{
    //设置窗口固定尺寸

    setFixedSize(GAME_WIDTH,GAME_HEIGHT);

    //设置标题
    setWindowTitle(GAME_TITLE);

    //加载图标(即程序图标)
    setWindowIcon(QIcon(GAME_ICON));

    //定时器的设置
    m_Timer.setInterval(GAME_RATE);

    //随机数种子
    srand((unsigned int)time(NULL));
}

void MainScene::playGame()
{

    //启动背景音乐
    QSound::play(SOUND_BACKGROUND);
    //启动定时器
    m_Timer.start();

    //监听定时器发送的信号
    connect(&m_Timer,&QTimer::timeout,[=](){
        if(op==1)
        {
            m_map.m_STOP.load(STOP_PATH1);
            //更新游戏中元素坐标
            updatePosition();
        }
        else
        {
            m_map.m_STOP.load(STOP_PATH);
        }
        //绘制到屏幕中
        update();
        //碰撞检测
        collisionDetection();
    });
}

void MainScene::updatePosition()
{

    //更新地图坐标
    m_map.mapPosition();

    //更新暂停状态
    m_map.m_Stop_Free();

    //发射子弹
    m_hero.shoot();

    //计算所有非空闲子弹当前的坐标
    for(int i=0;i<BULLET_NUM;i++)
    {
        //如果非空闲，计算发射的位置(即从飞机处发射)
        if(m_hero.m_bullets[i].m_Free==false)
        {
            m_hero.m_bullets[i].updatePosition();
        }
    }

    //敌机出场
    enemyToScene();

    //敌机位置坐标
    for(int i=0;i<ENEMY_NUM;i++)
    {
        if(m_enemys[i].m_Free==false)
        {
            m_enemys[i].updatePosition();
        }
    }

    //计算爆炸的播放图片
    for(int i=0;i<BOMB_NUM;i++)
    {
        if(m_bombs[i].m_Free==false)
        {
            m_bombs[i].updateInfo();
        }
    }

    //测试子弹
    //temp_bullet.m_Free=false;
    //temp_bullet.updatePosition();
}

void MainScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    //绘制地图
    painter.drawPixmap(0,m_map.m_map1_posy,m_map.m_map1);
    painter.drawPixmap(0,m_map.m_map2_posy,m_map.m_map2);

    //绘制英雄飞机
    painter.drawPixmap(m_hero.m_x,m_hero.m_y,m_hero.m_Plane);

    //绘制子弹
    for(int i=0;i<BULLET_NUM;i++)
    {
        //如果非空闲，绘制
        if(m_hero.m_bullets[i].m_Free==false)
        {
             painter.drawPixmap(m_hero.m_bullets[i].m_x,m_hero.m_bullets[i].m_y,m_hero.m_bullets[i].m_Bullet);
        }
    }

    //绘制敌机
    for(int i=0;i<ENEMY_NUM;i++)
    {
        if(m_enemys[i].m_Free==false)
        {
            painter.drawPixmap(m_enemys[i].m_x,m_enemys[i].m_y,m_enemys[i].m_enemy);
        }
    }

    //绘制爆炸过程
    for(int i=0;i<BOMB_NUM;i++)
    {
        if(m_bombs[i].m_Free==false)
        {
            painter.drawPixmap(m_bombs[i].m_x,m_bombs[i].m_y,m_bombs[i].m_pixArr[m_bombs[i].m_index]);
        }
    }

    //绘制暂停图标
    painter.drawPixmap(m_map.m_STOP_x,m_map.m_STOP_y,m_map.m_STOP);

    //测试子弹
    //painter.drawPixmap(temp_bullet.m_x,temp_bullet.m_y,temp_bullet.m_Bullet);
}

void MainScene::mouseMoveEvent(QMouseEvent *event)
{
    int x=event->x()-m_hero.m_Rect.width()*0.5;
    int y=event->y()-m_hero.m_Rect.height()*0.5;  //鼠标拖拽英雄飞机（拖拽点在飞机正中）

    //边界检测
    if(x<=0)
    {
        x=0;
    }
    if(x>=GAME_WIDTH-m_hero.m_Rect.width())
    {
        x=GAME_WIDTH-m_hero.m_Rect.width();
    }
    if(y<=0)
    {
        y=0;
    }
    if(y>=GAME_HEIGHT-m_hero.m_Rect.height())
    {
        y=GAME_HEIGHT-m_hero.m_Rect.height();
    }
    if(op==1)
    {
        m_hero.setPosition(x,y);
    }

}

void MainScene::mousePressEvent(QMouseEvent *event)
{
    int x=event->x();
    int y=event->y();
    if(x<=m_map.m_Rect.width()&&y<=m_map.m_Rect.height())
    {
        //鼠标左键事件发生，temp改变
        if(temp==1)
        {
            temp=0;
        }
        else if(temp==0)
        {
            temp=1;
        }
        //改变游戏暂停状态
        m_map.m_Stop_Free();
    }
}

void MainScene::enemyToScene()
{
    m_recorder++;
    //未达到出场间隔 直接return
    if(m_recorder<ENEMY_INTERVAL)
    {
        return;
    }

    //达到出场间隔
    m_recorder=0;
    for(int i=0;i<ENEMY_NUM;i++)
    {
        //若是空闲敌机
        if(m_enemys[i].m_Free)
        {
            m_enemys[i].m_Free=false;
            //坐标
            m_enemys[i].m_x=rand()%(GAME_WIDTH-m_enemys[i].m_Rect.width());
            m_enemys[i].m_y=-m_enemys[i].m_Rect.height();
            break;
        }
    }
}

void MainScene::collisionDetection()
{
    //遍历所有的非空闲敌机
    for(int i=0;i<ENEMY_NUM;i++)
    {
        //如果是空闲的飞机 继续找下一个飞机
        if(m_enemys[i].m_Free)
        {
            continue;
        }
        //遍历所有非空闲子弹
        for(int j=0;j<BULLET_NUM;j++)
        {
            //如果是空闲子弹 继续找下一个非空闲子弹
            if(m_hero.m_bullets[j].m_Free)
            {
                continue;
            }

            //如果子弹与敌机相交，发生碰撞，同时将敌机和子弹设置为空闲
            if(m_enemys[i].m_Rect.intersects(m_hero.m_bullets[j].m_Rect))
            {
                m_enemys[i].m_Free=true;
                m_hero.m_bullets[j].m_Free=true;

                //播放爆炸效果
                for(int k=0;k<BOMB_NUM;k++)
                {
                    if(m_bombs[k].m_Free)
                    {
                        //空闲 则可以播放

                        QSound::play(SOUND_BOMB);
                        m_bombs[k].m_Free=false;
                        //更新爆炸坐标
                        m_bombs[k].m_x=m_enemys[i].m_x;
                        m_bombs[k].m_y=m_enemys[i].m_y;
                        break;
                    }
                }
            }

        }
    }
}
