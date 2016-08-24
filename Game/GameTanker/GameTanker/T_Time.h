#ifndef _T_TIMER_H_INCLUDED_
#define _T_TIMER_H_INCLUDED_

#include<ctime>
#include<string>
#include<vector>

using namespace std;

typedef struct TIMEINFO {
	string _name;
	int _timer;
	int _limitTime;
	TIMEINFO(string name, int time, int limit_time) {
		_name = name;
		_timer = time;
		_limitTime = limit_time;
	}
}TIMEINFO;//时间节点


class T_Timer {
public:
	T_Timer();
	virtual ~T_Timer();

	static void Start();//开始计时
	static void UpdateOnce();//更新
	static void Register(string name, int limit_time);//注册一个计时器
	static void UnRegister(string name);//清除一个计时器
	static bool CheckTimer(string name);//检查计时器
	static void Reset(string name);//重置计时器
	static void Set(string name, int limit_time);//重设计时器

private:
	static vector<TIMEINFO*> _timers;
	static int _preTime;
};
#endif
