#pragma once
#include "Tank.h"
#include "define.h"
#include "resource.h"
#include <easy2d/easy2d.h>

using namespace easy2d;

class Enemy :
    public Tank
{
public:
    Enemy();

    ~Enemy();

    void onUpdate() override;

    void move(int dis); //ÒÆ¶¯

    int rotation;
    float speed;
    int tempRot;
};

