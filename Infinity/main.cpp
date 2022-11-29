#include <easy2d/easy2d.h>
#include "resource.h"
#include "CourseScene.h"
#include "HallScene.h"
#include "define.h"
#include "Init.h"

using namespace easy2d;

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow
)
{
	if (Game::init(L"Infinity", WIDTH, HEIGHT))
	{
		//显示控制台
		//Logger::showConsole();

		//显示图标
		Window::setIcon(IDI_ICON1);

		//创建初始场景
		Init* initscene = gcnew Init;

		//创建淡入淡出动画
		auto transition = gcnew FadeTransition(1);

		SceneManager::enter(initscene,transition);

		//auto scene = gcnew CourseScene;
		//SceneManager::enter(scene);

		//while(!scene->getFlag1())
		//{
			//continue; //按下F键跳出循环
		//}

		//auto callback = [=](Event *e)
		//{
		//	if (scene->getFlag1())
		//	{
		//		SceneManager::clear();
		//		auto hallscene = gcnew HallScene;
		//		SceneManager::enter(hallscene);
		//	}
		//};
		//auto lis = gcnew Listener;
		//lis->setCallback(callback);
		//scene->addListener(lis);

		Game::start();
	}

	Game::destroy();

	return 0;
}