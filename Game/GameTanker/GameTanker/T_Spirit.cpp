#include "T_Spirit.h"
#include"T_Tool.h"
#include"T_Resource.h"
//出现位置生成////////////////////////////////////
T_Bullet::T_Bullet(CvPoint tank_center_pos, DIR dir)
{
	_dir = dir;
	switch (dir)
	{
	case DIR_UP:
		_pos = { tank_center_pos.x,tank_center_pos.y - 16 };
		break;
	case DIR_DOWN:
		_pos= { tank_center_pos.x,tank_center_pos.y + 16 };
		break;
	case DIR_LEFT:
		_pos = { tank_center_pos.x - 16,tank_center_pos.y };
		break;
	case DIR_RIGHT:
		_pos = { tank_center_pos.x + 16,tank_center_pos.y };
		break;
	case DIR_NULL:
		break;
	default:
		break;
	}
	_isNeedClear = false;
	this->SetImage(T_Resource::GetInstance()->_bullet);
	_speed = 18;
}
//设定图片////////////////////////////////////
void T_Bullet::SetImage(IplImage * img)
{
	_img = img;
	_width = img->width;
	_height = img->height;
}
//绘图方法实现////////////////////////////////////
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
//移动方法--根据原有方向移动////////////////////////////////////
void T_Bullet::Move()
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
}
//子弹与spirit交错判定////////////////////////////////////
void T_Bullet::Intersenct(T_Spirit * pSpirit)
{
	CvRect bullet = { this->_pos.x,this->_pos.y,this->_img ->width,this->_img->height };
	CvRect spirit = { pSpirit->_pos.x,pSpirit->_pos.y,pSpirit->_img[0]->width,pSpirit->_img[0]->height };
	if (T_Tool::Intersect(bullet, spirit)) {
		this->_isNeedClear = true;
		pSpirit->_hp--;
		if (pSpirit->_hp == 0) {
			pSpirit->_isNeedClear = true;
		}

	}
}
//下一版本实现////////////////////////////////////
void T_Bullet::DrawFire()
{

}
//我方坦克初始化////////////////////////////////////
T_MyTank::T_MyTank()
{
	_pos = { PIXEL * 7,PIXEL * 12 };
	_dir = DIR_UP;
	_isNeedClear = false;
	_speed = 16;
	_hp = 3;
	_prePos = _pos;
	_bullet.clear();
}
//设置图片////////////////////////////////////
void T_MyTank::SetImage(IplImage * img[])
{
	for (int i = 0;i < 4;i++) {
		_img[i] = img[i];
	}
	_width = _img[0]->width;
	_height = _img[0]->height;
}
//绘图实现/////////////////////////////////////
void T_MyTank::Draw(IplImage * background)
{
	for (int i = 0;i < _img[_dir]->height;i++) {
		for (int j = 0;j < _img[_dir]->width;j++) {
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
//移动实现///////////////////////////////////////
void T_MyTank::Move(DIR dir)
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
}
//交错判定//////////////////////////////////////
void T_MyTank::Intersect(T_Spirit * pSpirit)
{
	CvRect player = { this->_pos.x,this->_pos.y,this->_img[0]->width,this->_img[0]->height };
	CvRect enemy = { pSpirit->_pos.x,pSpirit->_pos.y,pSpirit->_img[0]->width,pSpirit->_img[0]->height };
	if (T_Tool::Intersect(player, enemy)) {
		this->_isNeedClear = true;
	}
}
//敌人初始化，留出位置接口/////////////////
T_EnemyTank::T_EnemyTank(CvPoint pos)
{
	_pos = pos;
	_dir = DIR_DOWN;
	_isNeedClear = false;
	_speed = 16;
	_hp = 1;
	_prePos = _pos;
	_bullet.clear();
}
//设置图片//////////////////////////
void T_EnemyTank::SetImage(IplImage * img[])
{
	for (int i = 0;i < 4;i++) {
		_img[i] = img[i];
	}
	_width = _img[0]->width;
	_height = _img[0]->height;
}
//绘图方法实现////////////////////////////////////
void T_EnemyTank::Draw(IplImage * background)
{
	for (int i = 0;i < _img[_dir]->height;i++) {
		for (int j = 0;j < _img[_dir]->width;j++) {
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
//移动实现-留出AI接口//////////////////////////////
void T_EnemyTank::Move(DIR dir)
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
}
//攻击实现///////////////////////////////////////
void T_Spirit::Attack()
{
	if (_bullet.size() < 1) {
		CvPoint pos = { _pos.x + _width / 2 - 4, _pos.y + _height / 2 - 4 };//
		_bullet.push_back(new T_Bullet(pos, _dir));
	}
}
//得到图片CvRect//////////////////////////////////
CvRect T_Spirit::GetRecet()
{
	CvRect rect = { _pos.x,_pos.y,_width,_height };
	return rect;
}


