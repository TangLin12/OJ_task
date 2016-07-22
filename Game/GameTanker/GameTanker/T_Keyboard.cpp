
#include "T_Keyboard.h"

DIR T_KeyBoard::SenseMove()
{
	if (GetAsyncKeyState('W') & 0x8000) {
		return DIR(DIR_UP);
	}
	if (GetAsyncKeyState('S') & 0x8000) {
		return DIR(DIR_DOWN);
	}
	if (GetAsyncKeyState('A') & 0x8000) {
		return DIR(DIR_LEFT);
	}
	if (GetAsyncKeyState('D') & 0x8000) {
		return DIR(DIR_RIGHT);
	}
	return DIR(DIR_NULL);
}

bool T_KeyBoard::IsHit()
{
	if (GetAsyncKeyState('J') & 0x8000) {
		return true;
	}
	return false;
}

bool T_KeyBoard::IsSpace()
{
	if (GetAsyncKeyState(' ') & 0x8000) {
		return true;
	}
	return false;
}

bool T_KeyBoard::IsPause()
{
	if (GetAsyncKeyState('P') & 0x8000) {
		return true;
	}
	return false;
}
