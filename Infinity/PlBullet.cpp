#include "PlBullet.h"
#include "HallScene.h"

PlBullet::PlBullet(int rotation,float speed)
{
	this->rotation = rotation;
	this->speed = speed;
	this->open(IDB_PNG13, L"PNG");
	//this->truly = true;
}

PlBullet::~PlBullet()
{
}

void PlBullet::onUpdate()
{
	//越界时销毁
	if (this->getPosX() < 0 || this->getPosY() < 0 || this->getPosX() > WIDTH || this->getPosY() > HEIGHT)
	{
		HallScene* sce = (HallScene*)this->getParentScene();
		//sce->removeChild(this);
		//this->autorelease();
		//delete this;

		//this->truly = false;

	}

	//子弹移动
	if (rotation < 90)
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
