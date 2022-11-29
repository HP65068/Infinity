#pragma once
#include "Tank.h"
#include <easy2d/easy2d.h>

using namespace easy2d;

class PlTank :
    public Tank
{
public:
    PlTank();

    ~PlTank();

    void onUpdate() override;

    int rotation; //Ðý×ª½Ç¶È
};

