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
};//ö��ש������

<<<<<<< HEAD
class T_Memento {//��Ϣ�洢�ĵ���Ԫ��
public:
	vector<vector<int>> _map;

	T_Memento(vector<vector<int>> map) :_map(map) {

	}

	T_Memento& operator=(const T_Memento &memento) {
		_map = memento._map;
		return *this;
	}
};

class T_Map {//������Ϣ�ı���
=======
class T_Map {
>>>>>>> parent of e0d9470... add feature
public:
	vector<vector<int>> _map;
	vector<vector<int>> _mapSpare;
	int _wallTime;

	T_Map();
<<<<<<< HEAD

	void Load(int kind);//��ȡ
	void Load(T_Memento memento);
	T_Memento Save();//����
=======
>>>>>>> parent of e0d9470... add feature

	bool CantMove(int col, int row);//��ǰ���Ƿ�ɴ���

	void Intersect(T_Bullet* bullet);//�����ж�
	void Intersect(T_Spirit* spirit);

	static void Draw(IplImage * background, CvPoint pos, KIND kind);//�滭
};

<<<<<<< HEAD
class T_Archive {//�洢״̬
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