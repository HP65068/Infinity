#pragma once
#include <easy2d/easy2d.h>
//#include "D:\VS\IDE\VC\Tools\MSVC\14.34.31933\include\easy2d\e2dnode.h"
#include "define.h"

using namespace easy2d;

class CourseScene :
    public Scene
{
public:
    CourseScene();

    ~CourseScene();

    bool getFlag1();

private:
    bool flag1; //检查操作说明是否阅读
};

