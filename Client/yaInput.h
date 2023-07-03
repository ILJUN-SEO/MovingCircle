#pragma once
#include "CommonIncude.h"

namespace ya
{
	// 키의 종류
	enum class eKeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,
		END,
	};
	// 키의 상태
	enum class eKeyState
	{
		None,
		Down,
		Pressed,
		Up,
	};

	class Input
	{
	public:
		struct Key
		{
			eKeyCode code;
			eKeyState state;
			bool PressedBefore;
		};

		static void Initialize();
		static void Update();

		__forceinline static bool GetKeyDown(eKeyCode code) { return mKeys[(int)code].state == eKeyState::Down; }
		__forceinline static bool GetKey(eKeyCode code) { return mKeys[(int)code].state == eKeyState::Pressed; }
		__forceinline static bool GetKeyUp(eKeyCode code) { return mKeys[(int)code].state == eKeyState::Up; }

	private:
		static std::vector<Key> mKeys;
	};
}


