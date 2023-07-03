#pragma once
#include "CommonIncude.h"
#include "yaTime.h"

namespace ya
{
	class Circle
	{
	public:

		static void Initialize();
		static void Update();
		static void Render(HDC hdc);

	private:
		struct State
		{
			float posX;
			float posY;
			float dirX;
			float dirY;
			float velX;
			float velY;
		};

		static std::vector<State> circles;
		int timePassed;
		};
}


