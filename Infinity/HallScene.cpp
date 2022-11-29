#include "HallScene.h"
#include "resource.h"
#include "CourseScene.h"
#include "PlTank.h"
#include "Enemy.h"
#include "PlBullet.h"

HallScene::HallScene()
{
	this->score = 0;

	//������Ϸ����
	//auto music = MusicPlayer::preload(IDR_WAVE1, L"WAVE");
	//music->setVolume(0.3f);
	//music->play();
	MusicPlayer::play(IDR_WAVE1, L"WAVE");

	//��ʾ��Ϸ֡��
	//Renderer::showFps();

	//��䱳��
	for (int i = 0; i < WIDTH / 40; i++)
	{
		for (int j = 0; j < HEIGHT/40; j++)
		{
			auto board = gcnew Sprite;
			board->open(IDB_PNG12, L"PNG");
			board->setPos(Point(i * board->getWidth(), j * board->getHeight()));
			this->addChild(board);
		}
	}

	player = gcnew PlTank;
	player->open(IDB_PNG10, L"PNG");
	player->setAnchor(0.5f, 0.5f);
	player->setPos(Point(WIDTH / 2, HEIGHT / 2));
	this->addChild(player);

	//��ӵ���
	auto addEnemy = [=]()
	{
		float x, y;
		x = Random::range(0, 800);
		y = Random::range(0, 800);
		//do
		//{
		//	x = Random::range(0, 800);
		//	y = Random::range(0, 800);
		//} while (x >= 300 || x <= 700 || y >= 200 || y <= 600);

		auto enemy = gcnew Enemy;
		enemy->open(IDB_PNG14,L"PNG");
		enemy->setPos(Point(x, y));

		this->addChild(enemy);
	};

	Timer::add(addEnemy,3,15);

	//���Ѫ��
	auto hpText = gcnew Text;
	hpText->setText(L"HP");
	hpText->setColor(Color::Red);
	hpText->setPos(10, 5);
	hpText->setFontSize(20);
	this->addChild(hpText);

	hpStrip = gcnew Sprite;
	hpStrip->open(IDR_JPG2, L"JPG");
	hpStrip->setPos(40, 10);
	this->addChild(hpStrip);

	ro = new Text;
	ro->setText(FormatString(L"%d", Time::getTotalTime()));
	ro->setPos(900, 700);
	this->addChild(ro);
}

HallScene::~HallScene()
{
}

void HallScene::onUpdate()
{
	//����Ѫ��
	//this->hpStrip->crop(Rect(10, 10, int(this->player->hp / 10.0 * 50), 15));

	ro->setText(FormatString(L"%f", Time::getTotalTime()));

	if (this->player->hp <= 0)
	{
		if (this->score > Data::getInt(L"score", 0))
			Data::saveInt(L"score", this->score);
		this->setAutoUpdate(false);
		Timer::removeAll();
		Game::pause();

		auto text2 = new Text(FormatString(L"���γɼ���%d", this->score));
		text2->setFontSize(35);
		text2->setAnchor(0.5f, 0.5f);
		// ����������ʽ
		auto style = Text::Style();
		style.color = Color::Purple;          // ��ɫΪ��ɫ
		style.hasOutline = true;            // �����������
		style.outlineColor = Color::GreenYellow;    // ���������ɫ
		style.outlineWidth = 1.0;           // ������߿��Ϊ 2.0
		//style.wrapping = true;              // �����Զ�����
		//style.wrappingWidth = 70;           // �����Զ����еĿ��Ϊ 70�����أ�
		// ����������ʽ
		text2->setStyle(style);
		text2->setPos(WIDTH / 2, HEIGHT / 2 - 200);
		this->addChild(text2);

		auto text3 = new Text(FormatString(L"��ѳɼ���%d", Data::getInt(L"score",0)));
		text3->setFontSize(35);
		text3->setAnchor(0.5f, 0.5f);
		text3->setStyle(style);
		text3->setPos(WIDTH / 2, HEIGHT / 2 - 100);
		this->addChild(text3);
		//Data::saveInt(Time::getTotalTime());

		auto text = new Text(L"���¿�ʼ");
		text->setFontSize(33);
		text->setAnchor(0.5f, 0.5f);
		text->setPos(WIDTH / 2, HEIGHT / 2 +30);

		auto callback = [=]()
		{
			//Game::start();
			MusicPlayer::play(IDR_WAVE4, L"WAVE");
			this->removeAllChildren();
			//SceneManager::clear();
			//SceneManager::back();
			SceneManager::enter(gcnew HallScene, gcnew FadeTransition(1));
			//Game::reset();
			Game::resume();
			//delete this;
		};
		
		auto restart = new Sprite;
		restart->open(IDB_PNG1, L"PNG");
		restart->setAnchor(0.5f, 0.5f);
		//restart->setPos(WIDTH / 2-80, HEIGHT / 2 );

		auto button = new Button;
		button->setClickFunc(callback);
		button->setNormal(restart);
		button->setPos(WIDTH / 2-80 , HEIGHT / 2+110);

		this->addChild(text);
		this->addChild(button);
	}
	//�жϷ����ӵ�
	//if (Input::isPress(KeyCode::J))
	//{
	//	//Game::pause();
	//	auto plb = gcnew PlBullet(this->player->rotation, 3);
	//	plb->setPos(this->player->getPos());
	//	plb->setName(L"plb");
	//	this->addChild(plb);
	//	MusicPlayer::play(IDR_WAVE2, L"WAVE");
	//	//Game::start();
	//}
}

void HallScene::reduceHp(int i)
{
	if (this->player->hp - i >= 0)
		this->player->hp -= i;
	else
		this->player->hp = 0;

	this->hpStrip->crop(Rect(0, 0, int((this->player->hp / 10.0)*100), 15));
	//this->hpStrip->crop(Rect(0, 0, 10, 15));

	MusicPlayer::play(IDR_WAVE3, L"WAVE");
	//this->removeAllChildren();
}
