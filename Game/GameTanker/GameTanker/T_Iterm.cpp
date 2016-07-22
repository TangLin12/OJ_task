#include "T_Iterm.h"
#include"T_Resource.h"

T_Iterm::T_Iterm(int now_time)
{
	_nowTime = now_time;
	_showTime = 300;
	_pos.x = rand() % 600;
	_pos.y = rand() % 400;
	_kind = (rand() % 6) + 1;
	_img = T_Resource::GetInstance()->_iterm[_kind];
	_preTime = _nowTime;
}

void T_Iterm::Draw(IplImage * background)
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

bool T_Iterm::GetIterm(T_Spirit * spirit)
{
	if (T_Tool::Intersect(this->GetRecet(), spirit->GetRecet())) {
		_showTime = 0;
		if (_kind <= 3) {
			spirit->_bulletKind = _kind;
			spirit->itermTime = 500;
			return false;
		}
		else if(_kind==5){
			spirit->_hp += 1;
			return false;
		}
		else {
			return true;
		}
	}
	return false;
}

CvRect T_Iterm::GetRecet()
{
	CvRect rect = { _pos.x,_pos.y,_img->width,_img->height };
	return rect;
}
