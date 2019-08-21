// MouseKeyboardDll.cpp: DLL 응용 프로그램을 위해 내보낸 함수를 정의합니다.
//
#include "stdafx.h"
#include "MouseKeyboardDll.h"
#include <string>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;



POINT pt; // 마우스 포인터

		  // 마우스 함수
		  // 마우스 이동 ( x좌표, y좌표 )
 void MouseMove(int x, int y) {
	SetCursorPos(x, y); // 지정한 곳의 좌표로 마우스 이동
	Sleep(10);
}

// 마우스 버튼 누름 ( 버튼 )
 void MouseDown(int button) {
	GetCursorPos(&pt); // 마우스 좌표값들 받아옴
	int button_hex;

	switch (button)
	{
	case 0:
		button_hex = MOUSEEVENTF_LEFTDOWN;
		break;
	case 1:
		button_hex = MOUSEEVENTF_RIGHTDOWN;
		break;
	case 2:
		button_hex = MOUSEEVENTF_MIDDLEDOWN;
		break;
	default:
		button_hex = MOUSEEVENTF_LEFTDOWN;
		break;
	}
	mouse_event(button_hex, pt.x, pt.y, 0, 0); // 좌표에 맞게 왼쪽버튼 누르기
	Sleep(1);
}

// 마우스 버튼 뗌 ( 버튼 )
 void MouseUp(int button) {
	GetCursorPos(&pt); // 마우스 좌표값들 받아옴
	int button_hex;

	switch (button)
	{
	case 0:
		button_hex = MOUSEEVENTF_LEFTUP;
		break;
	case 1:
		button_hex = MOUSEEVENTF_RIGHTUP;
		break;
	case 2:
		button_hex = MOUSEEVENTF_MIDDLEUP;
		break;
	default:
		button_hex = MOUSEEVENTF_LEFTUP;
		break;
	}
	mouse_event(button_hex, pt.x, pt.y, 0, 0); // 좌표에 맞게 왼쪽버튼 누르기
	Sleep(1);
}

// 마우스 눌렀다 떔 ( 버튼 )
 void MouseClick(int button) {
	 MouseDown(button);
	 Sleep(1);
	 MouseUp(button);
}

// 마우스 이동 후 클릭 ( x좌표, y좌표 , 버튼 )
 void MouseMoveClick(int x, int y, int button) {
	MouseMove(x, y);
	MouseClick(button);
}

// 마우스 드래그 ( x좌표, y좌표 ) 
 void MouseDrag(int x, int y) {
	MouseDown(1);
	MouseMove(x, y);
	MouseUp(1);
}

// 무우스 더블클릭 ( 버튼 )
 void MouseDoubleClick(int button) {
	MouseClick(button);
	MouseClick(button);
}

// 키보드 함수
// 키보드 누름 ( 문자 )
 void KeyDown(char c) {
	int vk = VkKeyScan(c);
	UINT sc_vk = MapVirtualKey((BYTE)vk, MAPVK_VK_TO_VSC);
	keybd_event(vk, sc_vk, 0, 0);
}

// 키보드 땜 ( 문자 )
 void KeyUp(char c) {
	int vk = VkKeyScan(c);
	UINT sc_vk = MapVirtualKey((BYTE)vk, MAPVK_VK_TO_VSC);
	keybd_event(vk, sc_vk, KEYEVENTF_KEYUP, 0);
}

// 키보드 눌렀다 떔 ( 문자 )
 void KeyUpDown(char c, int delay) {
	 KeyDown(c);
	 Sleep(delay);
	 KeyUp(c);
	 Sleep(1);
}

// 타이핑을 함 ( 문자열 )
 void TypeString(char *baseStr) {
	for (int i = 0; i < sizeof(baseStr); i++) {
		char str = baseStr[i];
		KeyUpDown(str, 1);
		Sleep(1);
	}
}

 void cmdKeyDown(int key) {
	 int vk = specialKey(key);
	 UINT sc_vk = MapVirtualKey((BYTE)vk, MAPVK_VK_TO_VSC);
	 keybd_event(vk, sc_vk, 0, 0);
 }

 void cmdKeyUp(int key) {
	 int vk = specialKey(key);
	 UINT sc_vk = MapVirtualKey((BYTE)vk, MAPVK_VK_TO_VSC);
	 keybd_event(vk, sc_vk, KEYEVENTF_KEYUP, 0);
 }

 void cmdKeyUpDown(int key) {
	 cmdKeyDown(key);
	 Sleep(1);
	 cmdKeyUp(key);
 }

// 컨트롤 + 키보드 눌렀다떔 ( 문자 )
 void CtrlKey(char c) {
	int vk = VkKeyScan(c);
	UINT sc_vk = MapVirtualKey((BYTE)vk, MAPVK_VK_TO_VSC);
	UINT sc_vk1 = MapVirtualKey((BYTE)vk, MAPVK_VK_TO_VSC);
	keybd_event(vk, sc_vk, 0, 0);
	Sleep(1);
	keybd_event(vk, sc_vk, KEYEVENTF_KEYUP, 0);
}

// 쉬프트 + 키보드 눌렀다떔 ( 문자 )
 void ShiftKey(char c) {

}

// 알트 + 키보드 눌렀다떔 ( 문자 )
 void AltKey(char c) {

}

 void sleep_dt(int delay) {
	 Sleep(delay);
 }

 int specialKey(int vk) {
	 switch (vk) {
	 case 0:
		 vk = VK_LEFT;
		 break;
	 case 1:
		 vk = VK_RIGHT;
		 break;
	 case 2:
		 vk = VK_UP;
		 break;
	 case 3:
		 vk = VK_DOWN;
		 break;
	 case 4:
		 vk = VK_BACK;
		 break;
	 case 5:
		 vk = VK_TAB;
		 break;
	 case 6:
		 vk = VK_CLEAR;
		 break;
	 case 7:
		 vk = VK_RETURN;
		 break;
	 case 8:
		 vk = VK_SHIFT;
		 break;
	 case 9:
		 vk = VK_CONTROL;
		 break;
	 case 10:
		 vk = VK_MENU;
		 break;
	 case 11:
		 vk = VK_PAUSE;
		 break;
	 case 12:
		 vk = VK_CAPITAL;
		 break;
	 case 13:
		 vk = VK_HANGEUL;
		 break;
	 case 14:
		 vk = VK_HANJA;
		 break;
	 case 15:
		 vk = VK_ESCAPE;
		 break;
	 case 16:
		 vk = VK_SPACE;
		 break;
	 case 17:
		 vk = VK_PRIOR;
		 break;
	 case 18:
		 vk = VK_NEXT;
		 break;
	 case 19:
		 vk = VK_END;
		 break;
	 case 20:
		 vk = VK_HOME;
		 break;
	 case 21:
		 vk = VK_LEFT;
		 break;
	 case 22:
		 vk = VK_UP;
		 break;
	 case 23:
		 vk = VK_RIGHT;
		 break;
	 case 24:
		 vk = VK_DOWN;
		 break;
	 case 25:
		 vk = VK_SELECT;
		 break;
	 case 26:
		 vk = VK_PRINT;
		 break;
	 case 27:
		 vk = VK_EXECUTE;
		 break;
	 case 28:
		 vk = VK_SNAPSHOT;
		 break;
	 case 29:
		 vk = VK_INSERT;
		 break;
	 case 30:
		 vk = VK_DELETE;
		 break;
	 case 31:
		 vk = VK_HELP;
		 break;
	 case 32:
		 vk = VK_LWIN;
		 break;
	 case 33:
		 vk = VK_RWIN;
		 break;
	 case 34:
		 vk = VK_SLEEP;
		 break;
	 case 35:
		 vk = VK_MULTIPLY;
		 break;
	 case 36:
		 vk = VK_ADD;
		 break;
	 case 37:
		 vk = VK_SEPARATOR;
		 break;
	 case 38:
		 vk = VK_SUBTRACT;
		 break;
	 case 39:
		 vk = VK_DECIMAL;
		 break;
	 case 40:
		 vk = VK_DIVIDE;
		 break;
	 case 41:
		 vk = VK_F1;
		 break;
	 case 42:
		 vk = VK_F2;
		 break;
	 case 43:
		 vk = VK_F3;
		 break;
	 case 44:
		 vk = VK_F4;
		 break;
	 case 45:
		 vk = VK_F5;
		 break;
	 case 46:
		 vk = VK_F6;
		 break;
	 case 47:
		 vk = VK_F7;
		 break;
	 case 48:
		 vk = VK_F8;
		 break;
	 case 49:
		 vk = VK_F9;
		 break;
	 case 50:
		 vk = VK_F10;
		 break;
	 case 51:
		 vk = VK_F11;
		 break;
	 case 52:
		 vk = VK_F12;
		 break;
	 case 53:
		 vk = VK_F13;
		 break;
	 case 54:
		 vk = VK_F14;
		 break;
	 case 55:
		 vk = VK_F15;
		 break;
	 case 56:
		 vk = VK_F16;
		 break;
	 case 57:
		 vk = VK_F17;
		 break;
	 case 58:
		 vk = VK_F18;
		 break;
	 case 59:
		 vk = VK_F19;
		 break;
	 case 60:
		 vk = VK_F20;
		 break;
	 case 61:
		 vk = VK_F21;
		 break;
	 case 62:
		 vk = VK_F22;
		 break;
	 case 63:
		 vk = VK_F23;
		 break;
	 case 64:
		 vk = VK_F24;
		 break;
	 case 65:
		 vk = VK_NUMLOCK;
		 break;
	 case 66:
		 vk = VK_SCROLL;
		 break;
	 case 67:
		 vk = VK_LSHIFT;
		 break;
	 case 68:
		 vk = VK_RSHIFT;
		 break;
	 case 69:
		 vk = VK_LCONTROL;
		 break;
	 case 70:
		 vk = VK_RCONTROL;
		 break;
	 case 71:
		 vk = VK_LMENU;
		 break;
	 case 72:
		 vk = VK_RMENU;
		 break;
	 default:
		 vk = VK_SPACE;
		 break;
	 }
	 return vk;
 }