#include "PlTank.h"
#include <cmath>

PlTank::PlTank()
{
	this->rotation = 0;
	this->hp = 10;
	this->atk = 1;
	this->speed = 1.5f;
}

PlTank::~PlTank()
{
}

void PlTank::onUpdate()
{
	if (Input::isDown(KeyCode::A))
	{
		//if (this->getPosX() <= 0)
		//{
		//	this->setPosX(0);
		//}
		//else
		//{
		//	this->movePosX(-2);
		//}

		this->rotation -= 5;
		if (this->rotation < 0)
			this->rotation += 360;
		if (this->rotation >= 360)
			this->rotation -= 360;
		this->setRotation(this->rotation);
	}
	else if (Input::isDown(KeyCode::D))
	{
		//if (this->getPosX() >= WIDTH)
		//{
		//	this->setPosX(WIDTH);
		//}
		//else
		//{
		//	this->movePosX(2);
		//}

		this->rotation += 5;
		if (this->rotation >= 360)
			this->rotation -= 360;
		if (this->rotation < 0)
			this->rotation += 360;
		this->setRotation(this->rotation);
	}
	if (Input::isDown(KeyCode::W))
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
		else if (this->rotation >= 180 && this->rotation <270)
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
	else if (Input::isDown(KeyCode::S))
	{
		if (this->rotation < 90)
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
				double rotation = (this->rotation) * 3.14 / 180;
				this->movePosX(-speed * abs(sin(rotation)));
				this->movePosY(speed * abs(cos(rotation)));
			}
		}
		else if (this->rotation >= 90 && this->rotation < 180)
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
				double rotation = (this->rotation - 90) * 3.14 / 180;
				this->movePosX(-speed * abs(cos(rotation)));
				this->movePosY(-speed * abs(sin(rotation)));
			}
		}
		else if (this->rotation >= 180 && this->rotation < 270)
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
				double rotation = (this->rotation - 180) * 3.14 / 180;
				this->movePosX(speed * abs(sin(rotation)));
				this->movePosY(-speed * abs(cos(rotation)));
			}
		}
		else if (this->rotation >= 270 && this->rotation < 360)
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
				double rotation = (this->rotation - 270) * 3.14 / 180;
				this->movePosX(speed * abs(cos(rotation)));
				this->movePosY(speed * abs(sin(rotation)));
			}
		}
	}
	if (Input::isDown(KeyCode::J))
	{
		this->speed = 5;
	}
	else
	{
		this->speed=1.5;
	}
}
