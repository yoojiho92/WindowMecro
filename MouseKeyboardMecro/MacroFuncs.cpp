#include "stdafx.h"
#include "MacroFuncs.h"
#include <string>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;
using namespace MacroFuncs;

POINT pt; // 마우스 포인터

// 마우스 함수
// 마우스 이동 ( x좌표, y좌표 )
static void MouseMove(int x, int y) {
	SetCursorPos(x, y); // 지정한 곳의 좌표로 마우스 이동
	Sleep(10);
}

// 마우스 버튼 누름 ( 버튼 )
static void MouseDown(int button) {
	GetCursorPos(&pt); // 마우스 좌표값들 받아옴
	int button_hex;

	switch (button)
	{
	case 0 : 
		button_hex = MOUSEEVENTF_LEFTDOWN;
		break;
	case 1 :
		button_hex = MOUSEEVENTF_RIGHTDOWN;
		break;
	case 2 : 
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
static void MouseUp(int button) {
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
static void MouseClick(int button) {
	GetCursorPos(&pt); // 마우스 좌표값들 받아옴
	int button_hex;
	int button_hex2;

	switch (button)
	{
	case 0:
		button_hex = MOUSEEVENTF_LEFTDOWN;
		button_hex2 = MOUSEEVENTF_LEFTUP;
		break;
	case 1:
		button_hex = MOUSEEVENTF_RIGHTDOWN;
		button_hex2 = MOUSEEVENTF_RIGHTUP;
		break;
	case 2:
		button_hex = MOUSEEVENTF_MIDDLEDOWN;
		button_hex2 = MOUSEEVENTF_MIDDLEUP;
		break;
	default:
		button_hex = MOUSEEVENTF_LEFTDOWN;
		button_hex2 = MOUSEEVENTF_LEFTUP;
		break;
	}

	mouse_event(button_hex, pt.x, pt.y, 0, 0); 
	Sleep(10);
	mouse_event(button_hex2, pt.x, pt.y, 0, 0);
	Sleep(10);
}

// 마우스 이동 후 클릭 ( x좌표, y좌표 , 버튼 )
static void MouseMoveClick(int x, int y, int button) {
	MouseMove(x, y);
	MouseClick(button);
}

// 마우스 드래그 ( x좌표, y좌표 ) 
static void MouseDrag(int x, int y ) {
	MouseDown(1);
	MouseMove(x, y);
	MouseUp(1);
}

// 아무스 더블클릭 ( 버튼 )
static void MouseDoubleClick(int button) {
	MouseClick(button);
	MouseClick(button);
}

// 키보드 함수
// 키보드 누름 ( 문자 )
static void KeyDown(char c) {
	int vk = VkKeyScan(c);
	UINT sc_vk = MapVirtualKey((BYTE)vk, MAPVK_VK_TO_VSC);
	keybd_event(vk, sc_vk, 0, 0);
}

// 키보드 땜 ( 문자 )
static void KeyUp(char c) {
	int vk = VkKeyScan(c);
	UINT sc_vk = MapVirtualKey((BYTE)vk, MAPVK_VK_TO_VSC);
	keybd_event(vk, sc_vk, KEYEVENTF_KEYUP, 0);
}

// 키보드 눌렀다 떔 ( 문자 )
static void KeyUpDown(char c, int delay) {
	int vk = VkKeyScan(c);
	UINT sc_vk = MapVirtualKey((BYTE)vk, MAPVK_VK_TO_VSC);
	keybd_event(vk, sc_vk, 0, 0);
	Sleep(delay);
	keybd_event(vk, sc_vk, KEYEVENTF_KEYUP, 0);
}

// 타이핑을 함 ( 문자열 )
static void TypeString(string baseStr) {
	for (int i = 0; i < baseStr.size(); i++) {
		char str = baseStr.at(i);
		int vk = VkKeyScan(str);
		UINT sc_vk = MapVirtualKey((BYTE)vk, MAPVK_VK_TO_VSC);
		keybd_event(vk, sc_vk, 0, 0);
		Sleep(10);
		keybd_event(vk, sc_vk, KEYEVENTF_KEYUP, 0);
		Sleep(10);
	}
}

// 컨트롤 + 키보드 눌렀다떔 ( 문자 )
static void CtrlKey(char c) {
	int vk = VkKeyScan(c);
	UINT sc_vk = MapVirtualKey((BYTE)vk, MAPVK_VK_TO_VSC);
	UINT sc_vk1 = MapVirtualKey((BYTE)vk, MAPVK_VK_TO_VSC);
	keybd_event(vk, sc_vk, 0, 0);
	Sleep(1);
	keybd_event(vk, sc_vk, KEYEVENTF_KEYUP, 0);
}

// 쉬프트 + 키보드 눌렀다떔 ( 문자 )
static void ShiftKey(char c) {

}

// 알트 + 키보드 눌렀다떔 ( 문자 )
static void AltKey(char c) {

}