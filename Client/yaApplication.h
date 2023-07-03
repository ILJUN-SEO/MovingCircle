#pragma once
#include "CommonIncude.h"

namespace ya
{
	// 헤더 파일엔 이런 함수와 변수를 가지고 있다는 선언만 해둔다
	// 함수가 무슨 내용인지는 cpp 파일에서 정의한다
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

