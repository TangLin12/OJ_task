
#include "T_Keyboard.h"
//·½Ïò¼ü¼ì²â////////////////////////////////////
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
//¹¥»÷¼ì²â////////////////////////////////////
bool T_KeyBoard::IsHit()
{
	if (GetAsyncKeyState('J') & 0x8000) {
		return true;
	}
	return false;
}
//¿ªÊ¼¼ì²â////////////////////////////////////
bool T_KeyBoard::IsSpace()
{
	if (GetAsyncKeyState(' ') & 0x8000) {
		return true;
	}
	return false;
}
<<<<<<< HEAD
//ÔÝÍ£¼ì²â////////////////////////////////////
bool T_KeyBoard::IsPause()
{
	if (GetAsyncKeyState('P') & 0x8000) {
		return true;
	}
	return false;
}
=======
>>>>>>> parent of e0d9470... add feature
