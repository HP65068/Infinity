#pragma once
#include "Bullet.h"
#include "define.h"
#include <easy2d/easy2d.h>

using namespace easy2d;

class EnemyBullet :
    public Bullet
{
public:
    EnemyBullet(int rotation, float speed);

    ~EnemyBullet();

    void onUpdate() override;
private:
    
};

