#pragma once
//#include "D:\VS\IDE\VC\Tools\MSVC\14.34.31933\include\easy2d\e2dnode.h"
// #include "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.30.30705\include\easy2d\e2dnode.h"
#include <easy2d/easy2d.h>
#include "define.h"
#include "resource.h"

using namespace easy2d;

class Bullet :
    public Sprite
{
protected:
    float speed=0; //�ٶ�

    int rotation=0; //�Ƕ�

    bool truly; //�Ƿ����
};

