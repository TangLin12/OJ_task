#ifndef _T_MAP_H_INCLUDED_
#define _T_MAP_H_INCLUDED_

#include<vector>
#include<cv.h>
#include<highgui.h>
#include"T_Resource.h"
#include"T_Spirit.h"
#include"T_Tool.h"
using namespace std;

enum KIND {
	OBJ_NULL = 0,
	OBJ_BLOCK = 1,
	OBJ_IRON = 2,
	OBJ_GRASS = 3,
	OBJ_STAR = 7
};//枚举砖块种类

<<<<<<< HEAD
class T_Memento {//信息存储的单个元素
public:
	vector<vector<int>> _map;

	T_Memento(vector<vector<int>> map) :_map(map) {

	}

	T_Memento& operator=(const T_Memento &memento) {
		_map = memento._map;
		return *this;
	}
};

class T_Map {//产生信息的本身
=======
class T_Map {
>>>>>>> parent of e0d9470... add feature
public:
	vector<vector<int>> _map;
	vector<vector<int>> _mapSpare;
	int _wallTime;

	T_Map();
<<<<<<< HEAD

	void Load(int kind);//读取
	void Load(T_Memento memento);
	T_Memento Save();//保存
=======
>>>>>>> parent of e0d9470... add feature

	bool CantMove(int col, int row);//当前点是否可穿过

	void Intersect(T_Bullet* bullet);//交错判定
	void Intersect(T_Spirit* spirit);

	static void Draw(IplImage * background, CvPoint pos, KIND kind);//绘画
};

<<<<<<< HEAD
class T_Archive {//存储状态
private:
	vector<T_Memento> _mementoArray;
public:
	T_Archive() {

	}

	void AddIterm(T_Memento memento);

	T_Memento Load(int state);
};

=======
>>>>>>> parent of e0d9470... add feature
#endif