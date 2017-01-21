#include "T_Resource.h"
//载入资源
T_Resource::T_Resource()
{
	_backgroud = cvLoadImage("./res/BackGround.png");
	_bullet = cvLoadImage("./res/bullet.bmp");
	_levelImage = cvCreateImage(cvSize(960, 480), IPL_DEPTH_8U, 3);
	cvCopy(_backgroud, _levelImage);
	char filename[40];
	for (int i = 1;i < MAPNODE;i++) {
		sprintf_s(filename, "./res/block%d.bmp", i);
		_mapNode[i] = cvLoadImage(filename, 1);
	}
	for (int i = 0;i < 4;i++) {
		sprintf_s(filename, "./res/player1_%d.png", i);
		_myTank[i] = cvLoadImage(filename, 1);
	}
	for (int i = 0;i < 2;i++) {
		for (int j = 0;j < 4;j++) {
			sprintf_s(filename, "./res/enemy_%d%d.png", i,j);
			_enemyTank[i][j] = cvLoadImage(filename, 1);
		}
	}
	_meun = cvLoadImage("./res/menu.png");
	for (int i = 0;i < 6;i++) {
		sprintf_s(filename, "./res/prop_bmp%d.png", i);
		_iterm[i] = cvLoadImage(filename, 1);
	}
<<<<<<< HEAD
	for (int i = 0;i < 10;i++) {
		sprintf_s(filename, "./res/num%d.png", i);
		_nums[i] = cvLoadImage(filename, 1);
	}
	_num = cvLoadImage("./res/num.png");
	_blood = cvLoadImage("./res/blood.png");
	_end = cvLoadImage("./res/end.png");
	_endUI = cvCreateImage(cvSize(960, 480), IPL_DEPTH_8U, 3);
=======
>>>>>>> parent of e0d9470... add feature

	cvNamedWindow("TankGame");
	

}
//静态成员初始化
T_Resource* T_Resource::_resource = NULL;
void T_Resource::DestoryInstance()
{
	cvReleaseImage(&_backgroud);
	cvReleaseImage(&_bullet);
	for (int i = 1;i < MAPNODE;i++) {
		cvReleaseImage(&_mapNode[i]);
	}
	for (int i = 0;i < 4;i++) {
		cvReleaseImage(&_myTank[i]);
	}
	for (int i = 0;i < 2;i++) {
		for (int j = 0;j < 4;j++) {
			cvReleaseImage(&_enemyTank[i][j]);
		}
	}
	cvReleaseImage(&_meun);
	for (int i = 0;i < 6;i++) {
		cvReleaseImage(&_iterm[i]);
	}
	for (int i = 0;i < 10;i++) {
		cvReleaseImage(&_nums[i]);
	}
	cvReleaseImage(&_num);
	cvReleaseImage(&_blood);
	cvReleaseImage(&_end);
	cvReleaseImage(&_endUI);

	cvDestroyWindow("TankGame");
}
//展示窗口
void T_Resource::ShowFrame()
{
	cvShowImage("TankGame", _levelImage);
	cvCopy(_backgroud, _levelImage);
}
