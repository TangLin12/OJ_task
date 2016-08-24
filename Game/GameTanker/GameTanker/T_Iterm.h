
#ifndef _T_Iterm_H_INCLUDE_
#define _T_Iterm_H_INCLUDE_

#include<cv.h>
#include<highgui.h>
#include"T_Tool.h"
#include"T_Spirit.h"

class T_Iterm {
public:
	IplImage* _img;//图片信息
	int _showTime;//显示时间	
	int _preTime, _nowTime;//自己时间计时
	int _kind; //种类
	CvPoint _pos;//产生点
	
	T_Iterm(int now_time);

	void Draw(IplImage* background);
	bool GetIterm(T_Spirit* spirit);//spirit与其交错判定
	CvRect GetRecet();//返回图片的CvRect
};

#endif
