#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include <QTimer>
#include <map.h>
#include <heroplane.h>
#include "bullet.h"
#include "enemyplane.h"
#include "bomb.h"

class MainScene : public QWidget
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = 0);
    ~MainScene();

    //初始化场景
    void initScene();

    //启动游戏
    void playGame();

    //更新游戏中所有元素的坐标
    void updatePosition();

    //绘制到屏幕中  函数名称不能更改
    void paintEvent(QPaintEvent *);

    //地图对象
    Map m_map;

    //重新鼠标移动的事件  函数名不可更改
    void mouseMoveEvent(QMouseEvent *);

    //鼠标左键事件
    void mousePressEvent(QMouseEvent *);

    //敌机出场
    void enemyToScene();

    //敌机的数组
    EnemyPlane m_enemys[ENEMY_NUM];

    //敌机出场时间间隔记录
    int m_recorder=0;

    //英雄飞机对象
    HeroPlane m_hero;

    //碰撞检测
    void collisionDetection();

    //爆炸数组
    Bomb m_bombs[BOMB_NUM];

    //测试子弹对象
    //Bullet temp_bullet;

    //定时器
    QTimer m_Timer;

};

#endif // MAINSCENE_H
