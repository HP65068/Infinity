#pragma once
//#include "D:\VS\IDE\VC\Tools\MSVC\14.34.31933\include\easy2d\e2dnode.h"
#include "define.h"
#include <easy2d/easy2d.h>

using namespace easy2d;

class Tank :
    public Sprite
{
public:
    Tank();

    ~Tank();

    void onUpdate() override;

    int hp; //Ѫ��

    float speed; //�ٶ�

    int atk; //������
};

