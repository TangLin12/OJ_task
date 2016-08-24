#ifndef _T_KEYBOARD_H_INCLUDED_
#define _T_KEYBOARD_H_INCLUDED_

#include<Windows.h>
#include"T_Tool.h"


class T_KeyBoard {
public:
	static DIR SenseMove();//感受移动
	static bool IsHit();//感受攻击	
	static bool IsSpace();//感受是否
	static bool IsPause();//感受是否暂停
};

#endif