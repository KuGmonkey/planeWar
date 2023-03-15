#ifndef CONFIG_H
#define CONFIG_H

/*******  游戏配置信息  *******/
#define GAME_WIDTH 480  //宽度
#define GAME_HEIGHT 700 //高度  依据背景图设置宽和高
#define GAME_TITLE "飞机大战 v1.0" //标题
#define GAME_RES_PATH "res.qrc" //图片资源（也可用二进制）
#define GAME_ICON ":/res/me1"//程序图标加载路径
#define GAME_RATE 10   //定时器刷新的时间间隔  单位毫秒

/*******  地图配置信息  *******/
#define MAP_PATH ":/res/background" //地图路径
#define MAP_SCOLL_SPEED 2  //地图滚动速度（2像素）

/*******  飞机的配置   *******/
#define HERO_PATH ":/res/me2"   //飞机图片的路径

/*******  子弹配置数据 *******/
#define BULLET_PATH ":/res/bullet2"  //子弹图片路径
#define BULLET_PATH2 ":/res/bullet1"
#define BULLET_SPEED 10        //子弹移动速度
#define BULLET_NUM 30   //弹匣中子弹个数
#define BULLET_INTERVAL 10  //发射子弹的时间间隔

/******* 敌机配置数据  *******/
#define ENEMY_PATH ":/res/enemy2"   //敌机资源路径
#define ENEMY_PATH2 ":/res/enemy1"
#define ENEMY_SPEED 5  //敌机移动速度
#define ENEMY_NUM 20   //敌机总数量
#define ENEMY_INTERVAL 50  //敌机出场时间间隔

/*******  爆炸配置数据  *******/
#define BOMB_PATH ":/res/enemy1_down%1.png"  //爆炸资源图片
#define BOMB_NUM 20     //爆炸数量
#define BOMB_MAX 4      //爆炸图片最大索引
#define BOMB_INTERVAL 20  //爆炸切图时间间隔

/*******  音效配置数据  *******/
#define SOUND_BACKGROUND ":/res/DYnamedion - 全民飞机大战背景音乐.wav"
#define SOUND_BOMB ":/res/down.wav"

/*******  游戏停止设置      *******/
#define STOP_PATH ":/res/resume_nor"
#define STOP_PATH1 ":/res/pause_nor"



#endif // CONFIG_H
