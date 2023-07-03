#include "yaCircle.h"
#include <random>


namespace ya
{
	std::vector<Circle::State> Circle::circles = {};

	void Circle::Initialize()
	{
		std::random_device randomSeed;
		std::mt19937 gen(randomSeed());

		Circle::State newcircle;
		std::uniform_int_distribution<int> startX(0, 1500);
		std::uniform_int_distribution<int> startY(0, 800);
		std::uniform_real<double> Velocity(100.0, 500.0);
		std::uniform_int_distribution<int> direction(0, 1);

		newcircle.posX = startX(gen);
		newcircle.posY = startY(gen);
		newcircle.velX = Velocity(gen);
		newcircle.velY = Velocity(gen);
		int tempdirX = direction(gen);
		if (tempdirX == 0)
		{
			newcircle.dirX = -1;
		}
		else
		{
			newcircle.dirX = 1;
		}
		int tempdirY = direction(gen);
		if (tempdirY == 0)
		{
			newcircle.dirY = -1;
		}
		else
		{
			newcircle.dirY = 1;
		}

		Circle::circles.push_back(newcircle);
	}

	void Circle::Update()
	{
		static float timecheck = 0.0f;
		timecheck += Time::DeltaTime();

		if (timecheck >= 5.0f)
		{
			std::random_device randomSeed;
			std::mt19937 gen(randomSeed());

			Circle::State newcircle;
			std::uniform_int_distribution<int> startX(0, 1500);
			std::uniform_int_distribution<int> startY(0, 800);
			std::uniform_real<double> Velocity(100.0, 500.0);
			std::uniform_int_distribution<int> direction(0, 1);

			newcircle.posX = startX(gen);
			newcircle.posY = startY(gen);
			newcircle.velX = Velocity(gen);
			newcircle.velY = Velocity(gen);
			int tempdirX = direction(gen);
			if (tempdirX == 0)
			{
				newcircle.dirX = -1;
			}
			else
			{
				newcircle.dirX = 1;
			}
			int tempdirY = direction(gen);
			if (tempdirY == 0)
			{
				newcircle.dirY = -1;
			}
			else
			{
				newcircle.dirY = 1;
			}

			Circle::circles.push_back(newcircle);

			timecheck = 0.0f;
		}

		for (int i = 0; i < circles.size(); i++)
		{
			Circle::circles[i].posX += circles[i].velX * circles[i].dirX * Time::DeltaTime();
			Circle::circles[i].posY += circles[i].velY * circles[i].dirY * Time::DeltaTime();

			if (circles[i].posX <= 0)
			{
				circles[i].dirX = 1;
			}
			else if (circles[i].posX >= 1500)
			{
				circles[i].dirX = -1;
			}
			if (circles[i].posY <= 0)
			{
				circles[i].dirY = 1;
			}
			else if (circles[i].posY >= 750)
			{
				circles[i].dirY = -1;
			}
		}
	}

	void Circle::Render(HDC hdc)
	{
		for (int i = 0; i < circles.size(); i++)
		{
			Ellipse(hdc, circles[i].posX, circles[i].posY, circles[i].posX + 100, circles[i].posY + 100);
		}
	}
}
