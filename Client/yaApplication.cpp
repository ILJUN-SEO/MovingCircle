#include "yaApplication.h"
#include "yaInput.h"
#include "yaTime.h"
#include "yaCircle.h"


namespace ya
{
	Application::Application()
	{
		mHwnd = NULL;
		mHdc = NULL;
	}
	Application::~Application()
	{
	}
	void Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(mHwnd);

		Time::Initialize();
		Input::Initialize();
		Circle::Initialize();
	}
	void Application::Run()
	{
		Update();
		Render();
	}
	void Application::Update()
	{
		Time::Update();
		Input::Update();
		Circle::Update();

		////////// 직접 만든 이동 구현
		//if (Input::GetKey(eKeyCode::W))
		//{
		//	mPlayerPos.y -= 100.0f * Time::DeltaTime();
		//}
		//if (Input::GetKey(eKeyCode::A))
		//{
		//	mPlayerPos.x -= 100.0f * Time::DeltaTime();
		//}
		//if (Input::GetKey(eKeyCode::S))
		//{
		//	mPlayerPos.y += 100.0f * Time::DeltaTime();
		//}
		//if (Input::GetKey(eKeyCode::D))
		//{
		//	mPlayerPos.x += 100.0f * Time::DeltaTime();
		//}

		////////// WinAPI 기본 기능을 이용해 이동 구현
		//if (GetKeyState(VK_LEFT) & 0x8000)
		//{
		//	mPlayerPos.x -= 0.05f;
		//}
		//if (GetKeyState(VK_RIGHT) & 0x8000)
		//{
		//	mPlayerPos.x += 0.05f;
		//}
		//if (GetKeyState(VK_UP) & 0x8000)
		//{
		//	mPlayerPos.y -= 0.05f;
		//}
		//if (GetKeyState(VK_DOWN) & 0x8000)
		//{
		//	mPlayerPos.y += 0.05f;
		//}
		//if (GetAsyncKeyState(VK_RETURN) & 0x8000)
		//{
		//	mPlayerPos.x = 0.0f;
		//	mPlayerPos.y = 0.0f;
		//}
	}
	void Application::Render()
	{
		Time::Render(mHdc);
		Circle::Render(mHdc);
	}
}