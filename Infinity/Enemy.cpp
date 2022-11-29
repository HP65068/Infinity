#include "Enemy.h"
#include "EnemyBullet.h"
#include "Init.h"
#include "HallScene.h"
#include <cmath>

Enemy::Enemy()
{
	this->setAnchor(0.5f, 0.5f);
	this->speed = 1.0f;
	this->rotation = Random::range(0, 359);
	this->setRotation(this->rotation);
	this->tempRot = this->rotation;

	auto fire = [=]()
	{
		auto ebl = gcnew EnemyBullet(this->rotation,3.0f);
		ebl->setPos(this->getPos());
		this->getParentScene()->addChild(ebl);
		//this->addChild(ebl);

		auto sce = (HallScene*)this->getParentScene();
		++sce->score;
	};

	auto setRotation = [=]()
	{
		auto sce = (HallScene*)this->getParentScene();
		Point player = sce->player->getPos();
		int rot = 0;
		if (this->getPosX() > player.x)
		{
			if (this->getPosY() > player.y)
			{
				rot = 360 - abs(atan((abs(this->getPosX()) - abs(player.x)) / (abs(this->getPosY()) - abs(player.y))) * 180 / 3.14);
			}
			else
			{
				rot = 180 + abs(atan((abs(this->getPosX()) - abs(player.x)) / (abs(this->getPosY()) - abs(player.y))) * 180 / 3.14);
			}
		}
		else
		{
			if (this->getPosY() > player.y)
			{
				rot = abs(atan((abs(this->getPosX()) - abs(player.x)) / (abs(this->getPosY()) - abs(player.y))) * 180 / 3.14);
			}
			else
			{
				rot = 180 - abs(atan((abs(this->getPosX()) - abs(player.x)) / (abs(this->getPosY()) - abs(player.y))) * 180 / 3.14);
			}
		}
		
		this->rotation = rot;
	};

	Timer::add(setRotation, 3.0f, false);

	Timer::add(fire, 1.0f, false);

}

Enemy::~Enemy()
{

}

void Enemy::onUpdate()
{
	//if (this->getBoundingBox().intersects(this->getParentScene()->getChild(L"plb")->getBoundingBox()))
	//{
	//	Timer::stop(L"fire");
	//}

	if (this->tempRot < this->rotation)
	{
		++this->tempRot;
		this->setRotation(this->tempRot);
	}
	else if (this->tempRot > this->rotation)
	{
		--this->tempRot;
		this->setRotation(this->tempRot);
	}

	if (!Random::range(0, 10))
	{
		this->move(1);
	}
}

void Enemy::move(int speed)
{
	if (this->rotation < 90)
	{
		if (this->getPosY() <= 0)
		{
			this->setPosY(0);
		}
		else if (this->getPosX() >= WIDTH)
		{
			this->setPosX(WIDTH);
		}
		else
		{
			double rotation = this->rotation * 3.14 / 180;
			this->movePosX(speed * abs(sin(rotation)));
			this->movePosY(-speed * abs(cos(rotation)));
		}
	}
	else if (this->rotation >= 90 && this->rotation < 180)
	{
		if (this->getPosY() >= HEIGHT)
		{
			this->setPosY(HEIGHT);
		}
		else if (this->getPosX() >= WIDTH)
		{
			this->setPosX(WIDTH);
		}
		else
		{
			double rotation = (this->rotation - 90) * 3.14 / 180;
			this->movePosX(speed * abs(cos(rotation)));
			this->movePosY(speed * abs(sin(rotation)));
		}
	}
	else if (this->rotation >= 180 && this->rotation < 270)
	{
		if (this->getPosY() >= HEIGHT)
		{
			this->setPosY(HEIGHT);
		}
		else if (this->getPosX() <= 0)
		{
			this->setPosX(0);
		}
		else
		{
			double rotation = (this->rotation - 180) * 3.14 / 180;
			this->movePosX(-speed * abs(sin(rotation)));
			this->movePosY(speed * abs(cos(rotation)));
		}
	}
	else if (this->rotation >= 270 && this->rotation < 360)
	{
		if (this->getPosY() <= 0)
		{
			this->setPosY(0);
		}
		else if (this->getPosX() <= 0)
		{
			this->setPosX(0);
		}
		else
		{
			double rotation = (this->rotation - 270) * 3.14 / 180;
			this->movePosX(-speed * abs(cos(rotation)));
			this->movePosY(-speed * abs(sin(rotation)));
		}
	}
}
