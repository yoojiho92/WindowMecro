// enjoy3.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "MouseKeyboardDll.h"
#include <Windows.h>


int main()
{
	while (1) {
		if (GetKeyState(VK_F6) < 0) // 이어서 매크로 설정
		{
			for (int i = 0; i < 20; i++) {
				int x = i * 100;
				int y = x + 130;
				MouseMoveClick(x, y, 0);
			}
		}

		if (GetKeyState(VK_F7) < 0) // 이어서 매크로 설정
		{
			for (int i = 0; i < 20; i++) {
				KeyUpDown('h', 1000);
			}
		}

		if (GetKeyState(VK_F8) < 0) // 이어서 매크로 설정
		{
			KeyUpDown('c', 10);
		}

		if (GetKeyState(VK_F8) < 0) // 이어서 매크로 설정
		{
			KeyUpDown('c', 10);
		}
	}
	
	Sleep(3000);
	

    return 0;
}

ccccccccccccccccccccccccccccccccccccccccchhhhhhhhhh