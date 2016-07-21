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
};

class T_Map {
public:
	vector<vector<int>> _map;

	T_Map();

	bool CanDestory(int col, int row);
	bool CantMove(int col, int row);

	void Intersect(T_Bullet* bullet);
	void Intersect(T_Spirit* spirit);

	static void Draw(IplImage * background, CvPoint pos, KIND kind);
};

#endif