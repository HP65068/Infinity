#pragma once
//#include "D:\VS\IDE\VC\Tools\MSVC\14.34.31933\include\easy2d\e2dnode.h"
// #include "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.30.30705\include\easy2d\e2dnode.h"
#include "define.h"
#include "resource.h"
#include "CourseScene.h"
#include "PlTank.h"
#include "Enemy.h"
#include <easy2d/easy2d.h>

using namespace easy2d;

class HallScene :
    public Scene
{
public:
    HallScene();

    //void start(); //开始游戏

    ~HallScene();

    void onUpdate() override;

    void reduceHp(int i); //减血

    Sprite* hpStrip; //血条

    PlTank* player; //玩家

    Text* ro;

    int score; //分数
};

