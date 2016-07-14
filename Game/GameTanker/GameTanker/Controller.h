#ifndef _CONTROLLER_H_INCLUDED_
#define _CONTROLLER_H_INCLUDED_

#include"View.h"
#include<vector>

using namespace std;

#define NODEKIND 1
#define NUM 10
#define MAXROW 15
#define MAXCOL 20

class T_BGControl {
private:
	T_BackGround _bg;
	T_MapNode _node;

public:
	IplImage* _levelImage;
	T_BGControl();
	void Init(vector<vector<int>> map);
	void Show();
};

class T_GameManange {
public:
	T_BGControl _ui;
	T_Tank _player1;
	vector<vector<int>> _map;

	T_GameManange();

	void TankUpdate();
	void Run();
};

#endif.