#include "Init.h"
#include "define.h"
#include "HallScene.h"
#include "resource.h"
#include "CourseScene.h"

void Start();

Init::Init()
{
	// 显示游戏刚开始时的 LOGO
	auto splash = gcnew Sprite(IDR_JPG1,L"JPG");
	this->addChild(splash);

	// 1.5 秒后执行 Start 函数
	Timer::start(1.5, Start);
}

void Start()
{
	//创建大厅
	auto scene = gcnew CourseScene;

	//创建淡入淡出动画
	auto transition = gcnew FadeTransition(1);

	SceneManager::enter(scene, transition);
}

Init::~Init()
{
}
