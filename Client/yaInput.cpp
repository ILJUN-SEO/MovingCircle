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
			// �ش� Ű�� ���ȴ�
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				// ���� �����ӿ��� �����־��ٸ�
				if (mKeys[i].PressedBefore == true)
				{
					mKeys[i].state = eKeyState::Pressed;
				}
				// ���� ���� ���� ���̶��
				else
				{
					mKeys[i].state = eKeyState::Down;
				}

				mKeys[i].PressedBefore = true;
			}
			else // �ش� Ű�� �Է��� ����
			{
				// ���� �����ӿ� ������ �־��ٸ�
				if (mKeys[i].PressedBefore == true)
				{
					mKeys[i].state = eKeyState::Up;
				}
				else // ���� �����ӿ��� ������ �ʾҴٸ�
				{
					mKeys[i].state = eKeyState::None;
				}

				mKeys[i].PressedBefore = false;
			}
		}
	}
}
