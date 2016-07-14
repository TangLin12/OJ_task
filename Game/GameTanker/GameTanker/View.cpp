#include "View.h"

T_MapNode::T_MapNode()
{
	_img[1] = cvLoadImage(".\\res\\block1.bmp");
	_img[2] = cvLoadImage(".\\res\\block2.bmp");
	_img[3] = cvLoadImage(".\\res\\block3.bmp");
	_img[4] = cvLoadImage(".\\res\\block4.bmp");
	_img[5] = cvLoadImage(".\\res\\block5.bmp");
	_img[6] = cvLoadImage(".\\res\\block6.bmp");
	_img[7] = cvLoadImage(".\\res\\block7.bmp");
}

void T_MapNode::Draw(IplImage* background, CvPoint pos,int kind)
{
	if (kind == 0) {
		return;
	}
	for (int i = 0;i < _img[kind]->height;i++) {
		for (int j = 0;j < _img[kind]->width;j++) {
			int B = CV_IMAGE_ELEM(_img[kind], uchar, i, j * 3 + 0);
			int G = CV_IMAGE_ELEM(_img[kind], uchar, i, j * 3 + 1);
			int R = CV_IMAGE_ELEM(_img[kind], uchar, i, j * 3 + 2);

			if (j + pos.x < 0 || j + pos.x >= background->width || i + pos.y < 0 || i + pos.y >= background->height) {
				continue;
			}
			
			CV_IMAGE_ELEM(background, uchar, i + pos.y, (j +pos.x) * 3 + 0) = B;
			CV_IMAGE_ELEM(background, uchar, i + pos.y, (j +pos.x) * 3 + 1) = G;
			CV_IMAGE_ELEM(background, uchar, i + pos.y, (j +pos.x) * 3 + 2) = R;
		}
	}
}

void T_BackGround::SetBgImage(IplImage * img)
{
	_img = img;
}

T_Tank::T_Tank():_speed(5)
{
	_img = cvLoadImage(".\\res\\player1w.bmp");
	_pos = { 32 * 14,32 * 10 };
	_width = _img->width;_height = _img->height;
}

void T_Tank::Draw(IplImage * background)
{
	for (int i = 0;i < _img->height;i++) {
		for (int j = 0;j < _img->width;j++) {
			int B = CV_IMAGE_ELEM(_img, uchar, i, j * 3 + 0);
			int G = CV_IMAGE_ELEM(_img, uchar, i, j * 3 + 1);
			int R = CV_IMAGE_ELEM(_img, uchar, i, j * 3 + 2);

			if (j + _pos.x < 0 || j + _pos.x >= background->width || i + _pos.y < 0 || i + _pos.y >= background->height) {
				continue;
			}

			CV_IMAGE_ELEM(background, uchar, i + _pos.y, (j + _pos.x) * 3 + 0) = B;
			CV_IMAGE_ELEM(background, uchar, i + _pos.y, (j + _pos.x) * 3 + 1) = G;
			CV_IMAGE_ELEM(background, uchar, i + _pos.y, (j + _pos.x) * 3 + 2) = R;
		}
	}
}

void T_Tank::Move(int canvas_width, int canvas_height)
{
	if (GetAsyncKeyState('W') & 0x8000) {
		_pos.y -= _speed;
	}
	if (GetAsyncKeyState('S') & 0x8000) {
		_pos.y += _speed;
	}
	if (GetAsyncKeyState('A') & 0x8000) {
		_pos.x -= _speed;
	}
	if (GetAsyncKeyState('D') & 0x8000) {
		_pos.x += _speed;
	}

	if (_pos.x < 0) {
		_pos.x = 0;
	}
	if (_pos.x > canvas_width - 1 - _img->width) {
		_pos.x = canvas_width - 1 - _img->width;
	}
	if (_pos.y < 0) {
		_pos.y = 0;
	}
	if (_pos.y > canvas_height - 1 - _img->height) {
		_pos.y = canvas_height - 1 - _img->height;
	}
}
