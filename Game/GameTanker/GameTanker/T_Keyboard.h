#ifndef _T_KEYBOARD_H_INCLUDED_
#define _T_KEYBOARD_H_INCLUDED_

#include<Windows.h>
#include"T_Tool.h"


class T_KeyBoard {
public:
	static DIR SenseMove();//�����ƶ�
	static bool IsHit();//���ܹ���	
	static bool IsSpace();//�����Ƿ�
	static bool IsPause();//�����Ƿ���ͣ
};

#endif