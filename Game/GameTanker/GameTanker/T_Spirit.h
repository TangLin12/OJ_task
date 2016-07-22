
#ifndef _SPIRIT_H_INCLUDED_
#define _SPIRIT_H_INCLUDED_

#include<cv.h>
#include<highgui.h>
#include<vector>

using namespace std;

enum DIR ;

#define PIXEL 32

class T_BitMap {
public:
	CvPoint _pos;
	DIR _dir;
	int _speed;
	int _width, _height;
	bool _isNeedClear;

};

class T_Spirit;
class T_Bullet :public T_BitMap{
public:
	IplImage* _img;
	int _kind;
	int _fireNum;

	T_Bullet(CvPoint tank_center_pos, DIR dir);

	void SetImage(IplImage* img);
	void Draw(IplImage *background);
	void Move();
	void Intersenct(T_Spirit* spirit);
	void DrawFire();
};


class T_Spirit :public T_BitMap{
protected:

public:
	IplImage* _img[4];
	CvPoint _prePos;
	int _hp;
	vector<T_Bullet*> _bullet;
	int _preTime, _nowTime;
	int _tankKind;
	int _bulletKind;
	int itermTime;

	virtual void SetImage(IplImage* img[]) = 0;
	virtual void Draw(IplImage* background) = 0;
	virtual	void Move(DIR dir) = 0;
	virtual void Intersect(T_Spirit* pSpirit) {}
	void Attack();
	CvRect GetRecet();
};


class T_MyTank :public T_Spirit{
public:
	

	T_MyTank();

	void SetImage(IplImage* img[]);
	void Draw(IplImage *background);
	void Move(DIR dir);
	void Intersect(T_Spirit* pSpirit);

};

class T_EnemyTank :public T_Spirit {
public:
	T_EnemyTank(CvPoint pos);

	void SetImage(IplImage* img[]);
	void Draw(IplImage *background);
	void Move(DIR dir);
};
#endif
