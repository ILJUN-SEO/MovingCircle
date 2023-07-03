#include "yaTime.h"


namespace ya
{
	LARGE_INTEGER Time::mCpuFrequency = {};
	LARGE_INTEGER Time::mPrevFrequency = {};
	LARGE_INTEGER Time::mCurrentFrequency = {};
	float Time::mDeltaTime = 0.0f;

	void Time::Initialize()
	{
		// CPU의 고유 진동수를 가져온다
		QueryPerformanceFrequency(&mCpuFrequency);

		// 프로그램이 시작됐을 때 진동수를 가져온다
		QueryPerformanceCounter(&mPrevFrequency);
	}

	void Time::Update()
	{
		// 현재 진동수를 가져온다
		QueryPerformanceCounter(&mCurrentFrequency);

		// 이전과 현재의 진동수의 차가 크다는 건
		// 방금 실행한 그 명령이 오래 걸렸다는 뜻
		float differenceFrequency
			= static_cast<float>(mCurrentFrequency.QuadPart - mPrevFrequency.QuadPart);

		mDeltaTime = differenceFrequency / static_cast<float>(mCpuFrequency.QuadPart);
		mPrevFrequency.QuadPart = mCurrentFrequency.QuadPart;
	}

	void Time::Render(HDC hdc)
	{
		static float timeCheck = 0.0f;
		timeCheck += mDeltaTime;

		if (timeCheck >= 1.0f)
		{
			wchar_t szFloat[50] = {};
			float FramesPerSecond = 1.0f / mDeltaTime;

			swprintf_s(szFloat, 50, L"Frames per second : %f", FramesPerSecond);
			int strLen = wcsnlen_s(szFloat, 50);

			TextOut(hdc, 10, 10, szFloat, strLen);

			timeCheck = 0.0f;
		}
	}
}