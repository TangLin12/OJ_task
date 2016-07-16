#include "View.h"
#include<iostream>
using namespace std;

T_BackGround::T_BackGround()
{
	_img = cvLoadImage(".\\res\\BackGround.bmp");
	if (!_img) {
		cout << "Background Loading worry" << endl;
		exit(1);
	}
}

T_BackGround::~T_BackGround()
{
	cvReleaseImage(&_img);
}

void T_BackGround::SetBgImage(IplImage * img)
{
	_img = img;
}

T_MapNode::T_MapNode()
{
	_img[1] = cvLoadImage(".\\res\\block1.bmp");
	_img[2] = cvLoadImage(".\\res\\block2.bmp");
	_img[3] = cvLoadImage(".\\res\\block3.png");
	_img[4] = cvLoadImage(".\\res\\block4.bmp");
	_img[5] = cvLoadImage(".\\res\\block5.bmp");
	_img[6] = cvLoadImage(".\\res\\block6.bmp");
	_img[7] = cvLoadImage(".\\res\\block7.bmp");
	for (int i = 0;i < NODENUM;i++) {
		if (!_img[i]) {
			cout << "MapNode "<<i<<" Loading worry" << endl;
			exit(1);
		}
	}
}

T_MapNode::~T_MapNode()
{
	for (int i = 0;i < NODENUM;i++) {
		cvReleaseImage(&_img[i]);
	}
}

void T_MapNode::Draw(IplImage * background, CvPoint pos, KIND kind)
{
	if (kind == OBJ_NULL) {
		return;
	}
	for (int i = 0;i < _img[kind]->height;i++) {
		for (int j = 0;j < _img[kind]->width;j++) {
			if (j + pos.x < 0 || j + pos.x >= background->width || i + pos.y < 0 || i + pos.y >= background->height) {			//go over the map
				continue;
			}

			int B = CV_IMAGE_ELEM(_img[kind], uchar, i, j * 3 + 0);
			int G = CV_IMAGE_ELEM(_img[kind], uchar, i, j * 3 + 1);
			int R = CV_IMAGE_ELEM(_img[kind], uchar, i, j * 3 + 2);

			CV_IMAGE_ELEM(background, uchar, i + pos.y, (j + pos.x) * 3 + 0) = B;
			CV_IMAGE_ELEM(background, uchar, i + pos.y, (j + pos.x) * 3 + 1) = G;
			CV_IMAGE_ELEM(background, uchar, i + pos.y, (j + pos.x) * 3 + 2) = R;
		}
	}
}

T_Tank::T_Tank()
{
	_pos = { 32 * 15,32 *  9};
	_width = PIXEL;_height = PIXEL;
	_dir = DIR_UP;
	_isNeedClear = false;
	_bullet = {};
}

void T_Tank::Draw(IplImage * background)
{
	for (int i = 0;i < _img[0]->height;i++) {
		for (int j = 0;j < _img[0]->width;j++) {
			if (j + _pos.x < 0 || j + _pos.x >= background->width || i + _pos.y < 0 || i + _pos.y >= background->height) {
				continue;
			}

			int B = CV_IMAGE_ELEM(_img[_dir], uchar, i, j * 3 + 0);
			int G = CV_IMAGE_ELEM(_img[_dir], uchar, i, j * 3 + 1);
			int R = CV_IMAGE_ELEM(_img[_dir], uchar, i, j * 3 + 2);

		

			CV_IMAGE_ELEM(background, uchar, i + _pos.y, (j + _pos.x) * 3 + 0) = B;
			CV_IMAGE_ELEM(background, uchar, i + _pos.y, (j + _pos.x) * 3 + 1) = G;
			CV_IMAGE_ELEM(background, uchar, i + _pos.y, (j + _pos.x) * 3 + 2) = R;
		}
	}
}

void T_Tank::Move(int canvas_width, int canvas_height, DIR dir)
{
	_prePos = _pos;
	if (dir != DIR_NULL) {
		_dir = dir;
	}
	//move
	switch (_dir) {
	case DIR_UP:
		_pos.y -= _speed;break;
	case DIR_DOWN:
		_pos.y += _speed;break;
	case DIR_LEFT:
		_pos.x -= _speed;break;
	case DIR_RIGHT:
		_pos.x += _speed;break;
	}


	//position test
	if (_pos.x < 0) {
		_pos.x = 0;
	}
	if (_pos.x > canvas_width - 1 - _img[0]->width) {
		_pos.x = canvas_width - 1 - _img[0]->width;
	}
	if (_pos.y < 0) {
		_pos.y = 0;
	}
	if (_pos.y > canvas_height - 1 - _img[0]->height) {
		_pos.y = canvas_height - 1 - _img[0]->height;
	}
}

T_MyTank::T_MyTank()
{
	_img[0] = cvLoadImage(".\\res\\player1_w.png");
	_img[1] = cvLoadImage(".\\res\\player1_s.png");
	_img[2] = cvLoadImage(".\\res\\player1_a.png");
	_img[3] = cvLoadImage(".\\res\\player1_d.png");
	_pos = { 32 * 13,32 * 9 };
	_speed = 4;
	_width = _img[0]->width;_height = _img[0]->height;
	_dir = DIR_UP;
}

T_MyTank::~T_MyTank()
{
	for (int i = 0;i < 4;i++) {
		cvReleaseImage(&_img[i]);
	}
}

void T_MyTank::Attack()
{
	if (_bullet.size() < 1) {
		CvPoint pos;
		switch (_dir) {
		case DIR_UP:
			pos = { _pos.x + _width / 2,_pos.y };break;
		case DIR_DOWN:
			pos = { _pos.x + _width,_pos.y + _height };break;
		case DIR_LEFT:
			pos = { _pos.x,_pos.y + _height / 2 };break;
		case DIR_RIGHT:
			pos = { _pos.x + _width,_pos.y + _height };break;
		default:
			cout << "Attack error" << endl;
			exit(1);
		}
		_bullet.push_back(new T_Bullet(pos, _dir));
	}
}

T_Bullet::T_Bullet(CvPoint tank_shut_pos, DIR dir)
{
	_img = cvLoadImage(".\\res\\bullet.bmp");
	if (!_img) {
		cout << "Bullet Loading worry" << endl;
		exit(1);
	}
	_pos = tank_shut_pos;
	_dir = dir;
	_isNeedClear = false;
	_speed = 8;
}

void T_Bullet::Draw(IplImage * background)
{
	for (int i = 0;i < _img->height;i++) {
		for (int j = 0;j < _img->width;j++) {
			if (j + _pos.x < 0 || j + _pos.x >= background->width || i + _pos.y < 0 || i + _pos.y >= background->height) {
				continue;
			}

			int B = CV_IMAGE_ELEM(_img, uchar, i, j * 3 + 0);
			int G = CV_IMAGE_ELEM(_img, uchar, i, j * 3 + 1);
			int R = CV_IMAGE_ELEM(_img, uchar, i, j * 3 + 2);

			CV_IMAGE_ELEM(background, uchar, i + _pos.y, (j + _pos.x) * 3 + 0) = B;
			CV_IMAGE_ELEM(background, uchar, i + _pos.y, (j + _pos.x) * 3 + 1) = G;
			CV_IMAGE_ELEM(background, uchar, i + _pos.y, (j + _pos.x) * 3 + 2) = R;
		}
	}
}

void T_Bullet::Move(int canvas_width, int canvas_height)
{
	//move
	switch (_dir) {
	case DIR_UP:
		_pos.y -= _speed;break;
	case DIR_DOWN:
		_pos.y += _speed;break;
	case DIR_LEFT:
		_pos.x -= _speed;break;
	case DIR_RIGHT:
		_pos.x += _speed;break;
	}

	//edge test
	if (_pos.x < 0) {
		_isNeedClear = true;return;
	}
	if (_pos.x > canvas_width - 1 - _img->width) {
		_isNeedClear = true;return;
	}
	if (_pos.y < 0) {
		_isNeedClear = true;return;
	}
	if (_pos.y > canvas_height - 1 - _img->height) {
		_isNeedClear = true;return;
	}
}

T_EnemyTank::T_EnemyTank()
{
	_img[0] = cvLoadImage(".\\res\\enemy_w.png");
	_img[1] = cvLoadImage(".\\res\\enemy_s.png");
	_img[2] = cvLoadImage(".\\res\\enemy_a.png");
	_img[3] = cvLoadImage(".\\res\\enemy_d.png");
	_pos = { 32 * 13,32 * 10 };
	_speed = 4;
	_width = _img[0]->width;_height = _img[0]->height;
	_dir = EnemyAi();
}

T_EnemyTank::~T_EnemyTank()
{
	for (int i = 0;i < 4;i++) {
		cvReleaseImage(&_img[i]);
	}
}

DIR T_EnemyTank::EnemyAi()
{
	switch (rand() % 4) {
	case 0:
		return DIR(DIR_UP);
	case 1:
		return DIR(DIR_DOWN);
	case 2:
		return DIR(DIR_LEFT);
	case 3:
		return DIR(DIR_RIGHT);
	default:
		exit(3);
	}
}
