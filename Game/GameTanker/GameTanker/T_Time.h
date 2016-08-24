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
}TIMEINFO;//ʱ��ڵ�


class T_Timer {
public:
	T_Timer();
	virtual ~T_Timer();

	static void Start();//��ʼ��ʱ
	static void UpdateOnce();//����
	static void Register(string name, int limit_time);//ע��һ����ʱ��
	static void UnRegister(string name);//���һ����ʱ��
	static bool CheckTimer(string name);//����ʱ��
	static void Reset(string name);//���ü�ʱ��
	static void Set(string name, int limit_time);//�����ʱ��

private:
	static vector<TIMEINFO*> _timers;
	static int _preTime;
};
#endif
