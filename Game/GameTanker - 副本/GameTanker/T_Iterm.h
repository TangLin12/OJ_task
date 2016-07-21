
#ifndef _T_Iterm_H_INCLUDE_
#define _T_Iterm_H_INCLUDE_

#include<cv.h>
#include<highgui.h>

class T_Iterm {
	int _showTime;
	int _preTime, _nowTime;
	int _kind;
	CvPoint _pos;
};

#endif
