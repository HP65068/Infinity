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

    //void start(); //��ʼ��Ϸ

    ~HallScene();

    void onUpdate() override;

    void reduceHp(int i); //��Ѫ

    Sprite* hpStrip; //Ѫ��

    PlTank* player; //���

    Text* ro;

    int score; //����
};

