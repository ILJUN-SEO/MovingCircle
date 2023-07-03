#pragma once
#include "CommonIncude.h"

namespace ya
{
	// ��� ���Ͽ� �̷� �Լ��� ������ ������ �ִٴ� ���� �صд�
	// �Լ��� ���� ���������� cpp ���Ͽ��� �����Ѵ�
	//using namespace math;

	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd);
		void Run();
		void Update();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;

		math::Vector2 mPlayerPos;
		math::Vector2 square2;
		math::Vector2 square3;
	};
}

