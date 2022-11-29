#include "CourseScene.h"
#include <easy2d/easy2d.h>
#include "define.h"
#include "HallScene.h"

CourseScene::CourseScene()
{
	flag1 = false;

	auto text1 = gcnew Text(L"控制角色躲避子弹");
	text1->setFontSize(40);
	text1->setAnchor(0.5f, 0.5f);
	text1->setPos(Point(Window::getWidth() / 2, Window::getHeight() / 4));
	this->addChild(text1);

	auto text2 = gcnew Text(L"W A S D 移动  J 加速");
	text2->setFontSize(40);
	text2->setAnchor(0.5f, 0.5f);
	text2->setPos(Point(Window::getWidth() / 2, Window::getHeight() / 4 * 2));
	this->addChild(text2);

	auto text3 = gcnew Text(L"按F继续");
	text3->setFontSize(40);
	text3->setAnchor(0.5f, 0.5f);
	text3->setPos(Point(Window::getWidth() / 2, Window::getHeight() / 4 * 3));
	this->addChild(text3);

	//if (Input::isPress(KeyCode::F))
	//{
	//	flag1 = true;
	//	SceneManager::back();
	//}

	auto callback = [=](Event* e) //回调函数 判断是否按下F键
	{
		if (e->type == Event::KeyDown)
		{
			auto keyEvent = (KeyDownEvent*)e;
			if (keyEvent->key == KeyCode::F)
			{
				flag1 = true;

				//创建大厅
				auto scene = gcnew HallScene;

				//创建淡入淡出动画
				auto transition = gcnew FadeTransition(1);

				SceneManager::enter(scene, transition);
			}
		}
	};

	auto lis = gcnew Listener();
	lis->setCallback(callback);
	this->addListener(lis);
}

CourseScene::~CourseScene()
{
}

bool CourseScene::getFlag1()
{
	return flag1;
}
