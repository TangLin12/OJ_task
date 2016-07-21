#ifndef _T_RESOURCE_H_INCLUDE_
#define _T_RESOURCE_H_INCLUDE_

#include<cv.h>
#include<highgui.h>

#define MAPNODE 8



class T_Resource {
private:
	T_Resource();
	static T_Resource* _resource;

public:


	IplImage* _backgroud;
	IplImage* _mapNode[MAPNODE];
	IplImage* _bullet;
	IplImage* _myTank[4];
	IplImage* _enemyTank[4];
	IplImage* _levelImage;
	IplImage* _meun;

	static T_Resource* GetInstance() {
		if (_resource == NULL) {
			_resource = new T_Resource();
		}
		return _resource;
	}
	void DestoryInstance();
	void ShowFrame();
};

#endif