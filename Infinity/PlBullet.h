#pragma once
#include "Bullet.h"

class PlBullet :
    public Bullet
{
public:
    PlBullet(int rotation,float speed);

    ~PlBullet();

    void onUpdate() override;

private:
};

