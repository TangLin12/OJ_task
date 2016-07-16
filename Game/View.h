#ifndef _VIEW_H_INCLUDED_
#define _VIEW_H_INCLUDED_

#include<Windows.h>
#include<cv.h>
#include<highgui.h>
#include<vector>

using namespace std;

#define NODENUM 8
#define PIXEL 32

enum DIR {
	DIR_UP = 0,
	DIR_DOWN = 1,
	DIR_LEFT = 2,
	DIR_RIGHT = 3,
	DIR_NULL = 4
};

enum KIND {
	OBJ_NULL = 0,
	OBJ_BLOCK = 1,
	OBJ_IRON = 2,
	OBJ_GRASS = 3,
	OBJ_STAR = 7
};

class T_BackGround {
private:
	IplImage * _img;
public:
	T_BackGround();
	~T_BackGround();
	void SetBgImage(IplImage* img);
	IplImage* GetImage() { return _img; }
};

class T_MapNode {
public:
	IplImage* _img[NODENUM];

	T_MapNode();
	~T_MapNode();
	void Draw(IplImage* background, CvPoint pos, KIND kind);
};

class T_Bullet {
public:
	IplImage* _img;
	CvPoint _pos;
	DIR _dir;
	int _speed;
	bool _isNeedClear;

	T_Bullet(CvPoint tank_shut_pos, DIR dir);


	void Draw(IplImage* background);
	void Move(int canvas_width, int canvas_height);
};

class T_Tank {
public:
	IplImage* _img[4];
	CvPoint _pos;
	CvPoint _prePos;
	DIR _dir;
	int _width, _height;
	int _speed;
	bool _isNeedClear;
	vector<T_Bullet*> _bullet;

	T_Tank();

	void Draw(IplImage * background);
	void Move(int canvas_width, int canvas_height, DIR dir);
};

class T_MyTank :public T_Tank {
public:
	int hp;

	T_MyTank();
	~T_MyTank();

	void Attack();
};

class T_EnemyTank :public T_Tank {
public:
	T_EnemyTank();
	~T_EnemyTank();

	DIR EnemyAi();
};
#endif