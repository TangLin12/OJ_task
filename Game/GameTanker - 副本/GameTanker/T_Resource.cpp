#include "T_Resource.h"

T_Resource::T_Resource()
{
	_backgroud = cvLoadImage("./res/BackGround.bmp");
	_bullet = cvLoadImage("./res/bullet.bmp");
	_levelImage = cvCreateImage(cvSize(640, 480), IPL_DEPTH_8U, 3);
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
	for (int i = 0;i < 4;i++) {
		sprintf_s(filename, "./res/enemy_%d.png", i);
		_enemyTank[i] = cvLoadImage(filename, 1);
	}
	_meun = cvLoadImage("./res/menu.png");


	cvNamedWindow("TankGame");
	

}
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
	for (int i = 0;i < 4;i++) {
		cvReleaseImage(&_enemyTank[i]);
	}
	cvDestroyWindow("TankGame");
}

void T_Resource::ShowFrame()
{
	cvShowImage("TankGame", _levelImage);
	cvCopy(_backgroud, _levelImage);
}
