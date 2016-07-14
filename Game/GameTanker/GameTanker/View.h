#ifndef _VIEW_H_INCLUDED_
#define _VIEW_H_INCLUDED_

#include<Windows.h>
#include<cv.h>
#include<highgui.h>


#define NODENUM 8

class T_BackGround {
public:
	IplImage * _img;

	void SetBgImage(IplImage* img);
	IplImage* GetImage() { return _img; }
};

class T_MapNode {
public:
	IplImage* _img[NODENUM];
	
	T_MapNode();
	void Draw(IplImage* background, CvPoint pos , int kind);
};

class T_Tank {
public:
	IplImage* _img;
	CvPoint _pos;
	int _width, _height;
	int _speed;

	T_Tank();

	void Draw(IplImage* background);
	void Move(int canvas_width, int canvas_height);
};
#endif