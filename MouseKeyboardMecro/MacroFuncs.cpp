#include "stdafx.h"
#include "MacroFuncs.h"
#include <string>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;
using namespace MacroFuncs;

POINT pt; // ���콺 ������

// ���콺 �Լ�
// ���콺 �̵� ( x��ǥ, y��ǥ )
static void MouseMove(int x, int y) {
	SetCursorPos(x, y); // ������ ���� ��ǥ�� ���콺 �̵�
	Sleep(10);
}

// ���콺 ��ư ���� ( ��ư )
static void MouseDown(int button) {
	GetCursorPos(&pt); // ���콺 ��ǥ���� �޾ƿ�
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
	mouse_event(button_hex, pt.x, pt.y, 0, 0); // ��ǥ�� �°� ���ʹ�ư ������
	Sleep(1);
}

// ���콺 ��ư �� ( ��ư )
static void MouseUp(int button) {
	GetCursorPos(&pt); // ���콺 ��ǥ���� �޾ƿ�
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
	mouse_event(button_hex, pt.x, pt.y, 0, 0); // ��ǥ�� �°� ���ʹ�ư ������
	Sleep(1);
}

// ���콺 ������ �� ( ��ư )
static void MouseClick(int button) {
	GetCursorPos(&pt); // ���콺 ��ǥ���� �޾ƿ�
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

// ���콺 �̵� �� Ŭ�� ( x��ǥ, y��ǥ , ��ư )
static void MouseMoveClick(int x, int y, int button) {
	MouseMove(x, y);
	MouseClick(button);
}

// ���콺 �巡�� ( x��ǥ, y��ǥ ) 
static void MouseDrag(int x, int y ) {
	MouseDown(1);
	MouseMove(x, y);
	MouseUp(1);
}

// �ƹ��� ����Ŭ�� ( ��ư )
static void MouseDoubleClick(int button) {
	MouseClick(button);
	MouseClick(button);
}

// Ű���� �Լ�
// Ű���� ���� ( ���� )
static void KeyDown(char c) {
	int vk = VkKeyScan(c);
	UINT sc_vk = MapVirtualKey((BYTE)vk, MAPVK_VK_TO_VSC);
	keybd_event(vk, sc_vk, 0, 0);
}

// Ű���� �� ( ���� )
static void KeyUp(char c) {
	int vk = VkKeyScan(c);
	UINT sc_vk = MapVirtualKey((BYTE)vk, MAPVK_VK_TO_VSC);
	keybd_event(vk, sc_vk, KEYEVENTF_KEYUP, 0);
}

// Ű���� ������ �� ( ���� )
static void KeyUpDown(char c, int delay) {
	int vk = VkKeyScan(c);
	UINT sc_vk = MapVirtualKey((BYTE)vk, MAPVK_VK_TO_VSC);
	keybd_event(vk, sc_vk, 0, 0);
	Sleep(delay);
	keybd_event(vk, sc_vk, KEYEVENTF_KEYUP, 0);
}

// Ÿ������ �� ( ���ڿ� )
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

// ��Ʈ�� + Ű���� �����ً� ( ���� )
static void CtrlKey(char c) {
	int vk = VkKeyScan(c);
	UINT sc_vk = MapVirtualKey((BYTE)vk, MAPVK_VK_TO_VSC);
	UINT sc_vk1 = MapVirtualKey((BYTE)vk, MAPVK_VK_TO_VSC);
	keybd_event(vk, sc_vk, 0, 0);
	Sleep(1);
	keybd_event(vk, sc_vk, KEYEVENTF_KEYUP, 0);
}

// ����Ʈ + Ű���� �����ً� ( ���� )
static void ShiftKey(char c) {

}

// ��Ʈ + Ű���� �����ً� ( ���� )
static void AltKey(char c) {

}