#include "Controller.h"

T_BGControl::T_BGControl()
{
	IplImage* img = cvLoadImage(".\\res\\BackGround.bmp");
	_bg.SetBgImage(img);
}

void T_BGControl::Init(vector<vector<int>> map)
{
	_levelImage = cvCloneImage(_bg.GetImage());
	for (int col = 0;col < MAXCOL;col++) {
		for (int row = 0;row < MAXROW;row++) {
			CvPoint pos = { 32 * col,32 * row };
			_node.Draw(_levelImage, pos, map[row][col]);
		}
	}
}

void T_BGControl::Show()
{
	cvShowImage("Tank", _levelImage);
}

T_GameManange::T_GameManange()
{
	cvNamedWindow("Tank");
	_map = {
		{ 1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0 },
		{ 1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,6,0 },
		{ 1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 1,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0 },
		{ 1,1,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,5,0 },
		{ 1,1,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0 },
		{ 1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0 },
		{ 1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 1,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,4,0,0 },
		{ 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,1,7,1,0,0,0,0,0,0,0,0,0 },

	};
}

void T_GameManange::TankUpdate()
{
	_player1.Move(_ui._levelImage->width, _ui._levelImage->height);
	_player1.Draw(_ui._levelImage);
}

void T_GameManange::Run()
{
	while (true) {
		_ui.Init(_map);

		TankUpdate();

		_ui.Show();
		cvWaitKey(20);
	}
}
