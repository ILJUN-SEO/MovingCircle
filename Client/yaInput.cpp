#include "yaInput.h"


namespace ya
{
	std::vector<Input::Key> Input::mKeys = {};

	int ASCII[(int)eKeyCode::END] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
	};

	void ya::Input::Initialize()
	{
		for (int i = 0; i < (int)eKeyCode::END; i++)
		{
			Key key = {};
			key.code = (eKeyCode)i;
			key.state = eKeyState::None;
			key.PressedBefore = false;

			mKeys.push_back(key);
		}
	}

	void ya::Input::Update()
	{
		for (int i = 0; i < (int)eKeyCode::END; i++)
		{
			// 해당 키가 눌렸다
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				// 이전 프레임에도 눌려있었다면
				if (mKeys[i].PressedBefore == true)
				{
					mKeys[i].state = eKeyState::Pressed;
				}
				// 지금 새로 누른 것이라면
				else
				{
					mKeys[i].state = eKeyState::Down;
				}

				mKeys[i].PressedBefore = true;
			}
			else // 해당 키의 입력이 없다
			{
				// 이전 프레임에 눌려져 있었다면
				if (mKeys[i].PressedBefore == true)
				{
					mKeys[i].state = eKeyState::Up;
				}
				else // 이전 프레임에도 누르지 않았다면
				{
					mKeys[i].state = eKeyState::None;
				}

				mKeys[i].PressedBefore = false;
			}
		}
	}
}
