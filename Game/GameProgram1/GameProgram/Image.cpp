#include"Image.h"
#include<windows.h>
#include<WinUser.h>

MY_BackGround::MY_BackGround(const char* filename) {
	_img = cvLoadImage(filename);
	if (_img) {
		_width = _img->width;
		_height = _img->height;
	}
}

void MY_BackGround::Show(const char* window_name) {
	cvShowImage(window_name, _img);
}



MY_Obj::MY_Obj(const char* filename, CvPoint pos) :_pos(pos) {
	_img = cvLoadImage(filename);
	if (_img) {
		_width = _img->width;
		_height = _img->height;
	}
}

void MY_Obj::Draw(IplImage* bg_img, CvPoint pos) {
	if (bg_img != NULL&&_img != NULL) {
		for (int i = 0;i < _img->height;i++) {
			for (int j = 0;j < _img->width;j++) {
				int B = CV_IMAGE_ELEM(_img, uchar, i, j * 3 + 0);
				int G = CV_IMAGE_ELEM(_img, uchar, i, j * 3 + 1);
				int R = CV_IMAGE_ELEM(_img, uchar, i, j * 3 + 2);

				if (j + pos.x < 0 || j + pos.x >= bg_img->width || i + pos.y < 0 || i + pos.y >= bg_img->height) {
					continue;
				}

				CV_IMAGE_ELEM(bg_img, uchar, i + pos.y, (j + pos.x) * 3 + 0) = B;
				CV_IMAGE_ELEM(bg_img, uchar, i + pos.y, (j + pos.x) * 3 + 1) = G;
				CV_IMAGE_ELEM(bg_img, uchar, i + pos.y, (j + pos.x) * 3 + 2) = R;
			}
		}
	}
	else {
		return;
	}
}

void MY_Charactor::Move(int width,int height){
	int speed = 5;
	if (GetAsyncKeyState('W') & 0x8000)
	{
		_pos.x -= speed;
	}
	if (GetAsyncKeyState('S') & 0x8000)
	{
		_pos.y += speed;
	}
	if (GetAsyncKeyState('A') & 0x8000)
	{
		_pos.x -= speed;
	}
	if (GetAsyncKeyState('D') & 0x8000)
	{
		_pos.x += speed;
	}

	if (_pos.x < 0) _pos.x = 0;
	if (_pos.x > width - 1 - this->GetWidth())
		_pos.x = width - 1 - this->GetWidth();

	if (_pos.y < 0) _pos.y = 0;
	if (_pos.y > height - 1 - this->GetHeight())
		_pos.y = height - 1 - this->GetHeight();
}
