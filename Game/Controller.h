#ifndef _CONTROLLER_H_INCLUDED_
#define _CONTROLLER_H_INCLUDED_

#include"View.h"
#include<vector>

using namespace std;

#define NODEKIND 1
#define NUM 10
#define MAXROW 15
#define MAXCOL 20
#define PLAYNUM 1

class T_BGControl {
private:
	T_BackGround _bg;
	T_MapNode _node;

public:
	IplImage* _levelImage;

	T_BGControl();
	~T_BGControl();
	
	void Init(vector<vector<int>> map);			//init basic map ,without tank , bullet,ect;
	void Show();								//diplay one frame
};

class T_KeyBoard {
public:
	DIR SenseMove();
	bool IsHit();
};

class T_GameManange {
public:
	T_BGControl _ui;
	T_MyTank _player[PLAYNUM];
	vector<T_EnemyTank*> _enemy;
	vector<vector<int>> _map;
	T_KeyBoard _keyboard;

	T_GameManange();
	~T_GameManange();

	//test tool
	bool Intersect(CvRect r1, CvRect r2);
	void TestIntersect();


	void Move();
	void Draw();
	void Clear();

	void Run();
};

#endif