#ifndef _T_RESOURCE_H_INCLUDE_
#define _T_RESOURCE_H_INCLUDE_

#include<cv.h>
#include<highgui.h>

#define MAPNODE 8



class T_Resource {
private:
	T_Resource();//单例模式
	static T_Resource* _resource;
	class T_Garbo   //垃圾回收
	{
	public:
		~T_Garbo()
		{
			if (T_Resource::_resource) {
				T_Resource::GetInstance()->DestoryInstance();
				delete T_Resource::_resource;
			}
		}
	};
public:
	//图片信息
	IplImage* _iterm[6];
	IplImage* _backgroud;
	IplImage* _mapNode[MAPNODE];
	IplImage* _bullet;
	IplImage* _myTank[4];
	IplImage* _enemyTank[2][4];
	IplImage* _levelImage;
	IplImage* _meun;
	IplImage* _nums[10];
	IplImage* _blood;
	IplImage* _end;
	IplImage* _endUI;
	IplImage* _num;

	static T_Resource* GetInstance() {//对外接口
		if (_resource == NULL) {
			_resource = new T_Resource();
		}
		return _resource;
	}
	void DestoryInstance();
	void ShowFrame();
};

#endif