
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
};//游戏状态

class T_Game {
private:
	int _level;//地图关卡

	T_Game();//单例构造
	static T_Game* _game;
	
	bool EdgeTest(IplImage* background, IplImage* img, CvPoint pos);//边界测试

	void Edge();//所有物体的边界测试
	void TestIntersect();//所有物体的碰撞测试

	void WinJudge();//判断胜利
	void AllMove();//所有物体的移动
	void AllAttack();//坦克攻击更新
	void AllSense();//综合边界测试和碰撞测试
	void AllClear();//清理
	void EnemyUpdate();//继续产生敌人
	void ItermUpdate();//产生道具

	void Run();//运行函数

	void Set();//当前局设定
	void Reset();//重设变量

	class T_Garbo
	{
	public:
		~T_Garbo()
		{
			if (T_Game::_game) {
				T_Game::GetInstance()->DestoryInstance();
				delete T_Game::_game;
			}
		}//垃圾回收类
	};//单例释放
public:
	int _score;//得分
	int _enemyLimit;//敌人数量
	int _enemyOnceSize;//敌人一次出现数量
	T_Resource* _totalImg;//加载图片资源
	vector<T_Spirit*> _myTank;//实例化自己坦克
	vector<T_Spirit*> _enemyTank;//实例化敌人坦克
	T_Map _map;//实例化地图
	STATE _state;//状态控制
	T_Iterm* _iterm;//道具实例化
	bool _win;//胜利判断

	static T_Game* GetInstance();

	void Init();//开始游戏

	void DestoryInstance();
};


class T_Frame {
public:
	static void InitFrame(T_Game* game);
	static void RunFrame(T_Game* game);
	static void EndFrame(T_Game* game);
};




#endif
