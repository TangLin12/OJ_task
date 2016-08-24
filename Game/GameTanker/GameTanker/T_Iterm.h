
#ifndef _T_Iterm_H_INCLUDE_
#define _T_Iterm_H_INCLUDE_

#include<cv.h>
#include<highgui.h>
#include"T_Tool.h"
#include"T_Spirit.h"

class T_Iterm {
public:
	IplImage* _img;//ͼƬ��Ϣ
	int _showTime;//��ʾʱ��	
	int _preTime, _nowTime;//�Լ�ʱ���ʱ
	int _kind; //����
	CvPoint _pos;//������
	
	T_Iterm(int now_time);

	void Draw(IplImage* background);
	bool GetIterm(T_Spirit* spirit);//spirit���佻���ж�
	CvRect GetRecet();//����ͼƬ��CvRect
};

#endif
