#include "Init.h"
#include "define.h"
#include "HallScene.h"
#include "resource.h"
#include "CourseScene.h"

void Start();

Init::Init()
{
	// ��ʾ��Ϸ�տ�ʼʱ�� LOGO
	auto splash = gcnew Sprite(IDR_JPG1,L"JPG");
	this->addChild(splash);

	// 1.5 ���ִ�� Start ����
	Timer::start(1.5, Start);
}

void Start()
{
	//��������
	auto scene = gcnew CourseScene;

	//�������뵭������
	auto transition = gcnew FadeTransition(1);

	SceneManager::enter(scene, transition);
}

Init::~Init()
{
}
