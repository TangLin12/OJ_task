#ifndef _IMAGE_H_INCLUDED_
#define _IMAGE_H_INCLUDED_

#include<cv.h>
#include<highgui.h>

class MY_BitMap {
protected:
	IplImage* _img;
	int _width;
	int _height;
public:
	MY_BitMap() { ; }
	~MY_BitMap() { ; }

	int GetWidth() { return _width; }
	int GetHeight() { return _height; }
	IplImage* GetNowImage() { return _img; }
};

class MY_BackGround :public MY_BitMap {
public:
	MY_BackGround(const char* filename);

	void Show(const char* window_name);
};

class MY_Obj :public MY_BitMap {
protected:
	CvPoint _pos;
public:
	CvPoint _pos;
	MY_Obj(const char* filename, CvPoint pos = { 0,0 });
	void Draw(IplImage* bg_img,CvPoint pos);
};

class MY_Charactor :public MY_Obj {
public:
	void MY_Charactor::Move(int dir_x, int dir_y);
};

#endif