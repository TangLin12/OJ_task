
#ifndef _T_GAME_H_INCLUDE_
#define _T_GAME_H_INCLUDE_


#include"T_Tool.h"
#include"T_Keyboard.h"
#include"T_Spirit.h"
#include"T_Map.h"
#include"T_Time.h"
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

	int _enemyLimit;
	
	T_Game();
	static T_Game* _game;
public:
	int _enemyOnceSize;
	T_Resource* _totalImg;
	vector<T_Spirit*> _myTank;
	vector<T_Spirit*> _enemyTank;
	T_Map _map;
	STATE _state;

	~T_Game();

	static T_Game* GetInstance();

	void Init();

	bool EdgeTest(IplImage* background, IplImage* img, CvPoint pos);

	void Edge();
	void TestIntersect();//

	void AllMove();
	void AllAttack();
	void AllSense();
	void AllClear();
	void EnemyUpdate();
	void End();
	
	void Run();

	void Set();
	
};


class T_Frame {
public:
	static void InitFrame(T_Game* game);
	static void RunFrame(T_Game* game);
};
#endif
