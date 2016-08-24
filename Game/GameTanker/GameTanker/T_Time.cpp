#include "T_Time.h"

#include<iostream>

vector<TIMEINFO*> T_Timer::_timers;
int T_Timer::_preTime = 0;

T_Timer::T_Timer()
{
	_preTime = 0;
}

T_Timer::~T_Timer()
{
	for (int i = 0;i < _timers.size();i++) {
		delete _timers[i];
	}
	_timers.clear();
}
//开始计时///////////////////////////////////
void T_Timer::Start()
{
	_preTime = clock();
}
//计时器更新一次/////////////////////////////
void T_Timer::UpdateOnce()
{
	int now_time = clock();
	int time_lag = now_time - _preTime;
	for (int i = 0;i < _timers.size();i++) {
		_timers[i]->_timer += time_lag;
	}
	_preTime = now_time;
}
//注册计时器//////////////////////////////////
void T_Timer::Register(string name, int limit_time) {
	for (int i = 0;i < _timers.size();i++) {
		if (_timers[i]->_name == name) {
			//cout << "Object " << name << " is eixt";
			return;
		}
	}
	_timers.push_back(new TIMEINFO(name, 0, limit_time));
}
//取消注册///////////////////////////////////////
void T_Timer::UnRegister(string name)
{
	for (int i = 0;i < _timers.size();i++) {
		if (_timers[i]->_name == name) {
			delete _timers[i];
			_timers.erase(_timers.begin() + i);
			break;
		}
	}
}
//检查时间//////////////////////////////
bool T_Timer::CheckTimer(string name)
{
	for (int i = 0;i < _timers.size();i++) {
		if (_timers[i]->_name == name) {
			return _timers[i]->_timer >= _timers[i]->_limitTime;
		}
	}
	return false;
}
//重置时间////////////////////////////////
void T_Timer::Reset(string name)
{
	for (int i = 0;i < _timers.size();i++) {
		if (_timers[i]->_name == name) {
			_timers[i]->_timer = 0;
		}
	}
}
//重设时间///////////////////////////////////
void T_Timer::Set(string name, int limit_time)
{
	for (int i = 0;i < _timers.size();i++) {
		if (_timers[i]->_name == name) {
			_timers[i]->_limitTime = limit_time;
			return;
		}		
	}
}
