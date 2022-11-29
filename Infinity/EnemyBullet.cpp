#include "EnemyBullet.h"
#include "resource.h"
#include "HallScene.h"

EnemyBullet::EnemyBullet(int rotation, float speed)
{
	this->speed = speed;
	this->rotation = rotation;
	this->open(IDB_PNG15, L"PNG");
	this->setRotation(this->rotation-90);
	this->truly = true;
}

EnemyBullet::~EnemyBullet()
{
}

void EnemyBullet::onUpdate()
{
	//越界时销毁
	HallScene* sce = (HallScene*)this->getParentScene();
	if (this->getPosX() < 0 || this->getPosY() < 0 || this->getPosX() > WIDTH || this->getPosY() > HEIGHT)
	{
		//sce->removeChild(this);
		//this->stopAllActions();
		//delete this;
		//this->truly = false;
	}

	//判断是否碰到玩家
	if (this->getBoundingBox().intersects(sce->player->getBoundingBox()))
	{
		if (this->truly)
		{
			this->truly = false;
			sce->reduceHp(1);
		}

		//Game::pause();
		//this->removeFromParent();
		//this->getParentScene()->addChild(this);
		//Game::resume();
		//if (this)
		//delete(this);
		//this->stopAllActions();
		//this->stopAllActions();
		//delete(this);
	}

	//子弹移动
	if (this->rotation < 90)
	{
		float rotation = this->rotation * 3.14 / 180;
		this->movePosX(speed * abs(sin(rotation)));
		this->movePosY(-speed * abs(cos(rotation)));
	}
	else if (this->rotation >= 90 && this->rotation < 180)
	{
		float rotation = (this->rotation - 90) * 3.14 / 180;
		this->movePosX(speed * abs(cos(rotation)));
		this->movePosY(speed * abs(sin(rotation)));
	}
	else if (this->rotation >= 180 && this->rotation < 270)
	{
		float rotation = (this->rotation - 180) * 3.14 / 180;
		this->movePosX(-speed * abs(sin(rotation)));
		this->movePosY(speed * abs(cos(rotation)));
	}
	else if (this->rotation >= 270 && this->rotation < 360)
	{
		float rotation = (this->rotation - 270) * 3.14 / 180;
		this->movePosX(-speed * abs(cos(rotation)));
		this->movePosY(-speed * abs(sin(rotation)));
	}
}
