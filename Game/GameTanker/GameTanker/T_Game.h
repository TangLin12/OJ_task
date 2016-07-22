
#ifndef _T_GAME_H_INCLUDE_
#define _T_GAME_H_INCLUDE_


#include"T_Tool.h"
#include"T_Keyboard.h"
#include"T_Spirit.h"
#include"T_Map.h"
#include"T_Time.h"
#include"T_Iterm.h"
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
class T_Resource;
#define MAXROW 15
#define MAXCOL 20



enum STATE {
	STATE_MENU,
	STATE_RUN,
	STATE_END,
	STATE_RESTATE,
	STATE_PAUSE
};

class T_Game {
private:


	
	T_Game();
	static T_Game* _game;
	int _score;
public:
	int _enemyLimit;
	int _enemyOnceSize;
	T_Resource* _totalImg;
	vector<T_Spirit*> _myTank;
	vector<T_Spirit*> _enemyTank;
	T_Map _map;
	STATE _state;
	T_Iterm* _iterm;
	bool _win;

	~T_Game();

	static T_Game* GetInstance();

	void Init();

	bool EdgeTest(IplImage* background, IplImage* img, CvPoint pos);

	void Edge();
	void TestIntersect();//

	void WinJudge();
	void AllMove();
	void AllAttack();
	void AllSense();
	void AllClear();
	void EnemyUpdate();
	void ItermUpdate();
	void End();
	
	void Run();

	void Set();
	void Reset();
	
};


class T_Frame {
public:
	static void InitFrame(T_Game* game);
	static void RunFrame(T_Game* game);
};




#endif
