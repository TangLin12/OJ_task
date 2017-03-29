#include "Controller.h"

T_BGControl::T_BGControl()
{
	_levelImage = cvCreateImage(cvSize(640, 480), IPL_DEPTH_8U, 3);
}

T_BGControl::~T_BGControl()
{
	cvReleaseImage(&_levelImage);
}

void T_BGControl::Init(vector<vector<int>> map)
{
	cvCopy(_bg.GetImage(), _levelImage);
	for (int col = 0;col < MAXCOL;col++) {
		for (int row = 0;row < MAXROW;row++) {
			KIND now_kind;
			switch (map[row][col]) {
			case 0:
				now_kind = OBJ_NULL;;break;
			case 1:
				now_kind = OBJ_BLOCK;break;
			case 2:
				now_kind = OBJ_IRON;break;
			case 3:
				now_kind = OBJ_GRASS;break;
			case 7:
				now_kind = OBJ_STAR;break;
			default:
				cout << "Error Type" << endl;exit(1);
			}
			CvPoint pos = { PIXEL * col,PIXEL * row };
			_node.Draw(_levelImage, pos, now_kind);
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
		{ 1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,2,0 },
		{ 1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 1,1,0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0 },
		{ 1,1,0,0,1,0,2,0,0,0,2,0,0,0,0,0,0,0,2,0 },
		{ 1,1,0,1,1,0,2,0,0,0,2,0,1,0,0,0,0,0,0,0 },
		{ 1,1,0,1,1,1,0,0,0,0,0,0,1,0,0,3,0,0,0,0 },
		{ 1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0 },
		{ 1,1,0,1,1,1,0,0,1,0,0,0,1,0,0,0,0,2,0,0 },
		{ 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,1,7,1,0,0,0,0,0,0,0,0,0 },
	};
}

T_GameManange::~T_GameManange()
{
	cvDestroyWindow("Tank");
}

bool T_GameManange::Intersect(CvRect r1, CvRect r2)
{
	int c1_x = r1.x + r1.width / 2;
	int c1_y = r1.y + r1.height / 2;

	int c2_x = r2.x + r2.width / 2;
	int c2_y = r2.y + r2.height / 2;

	if ((abs(c1_x - c2_x) == r1.width / 2 + r2.width / 2) || (abs(c1_y - c2_y) > r1.height / 2 + r2.height / 2)) {
		return false;
	}

	if ((abs(c1_x - c2_x) > r1.width / 2 + r2.width / 2) && (abs(c1_y - c2_y) > r1.height / 2 + r2.height / 2)) {
		return false;
	}
	else {
		return true;
	}
}

void T_GameManange::TestIntersect()
{
	//test play1 and wall
	int col = _player[0]._pos.x / PIXEL;int row = _player[0]._pos.y / PIXEL;
	CvRect player = { _player[0]._pos.x,_player[0]._pos.y,_player[0]._width,_player[0]._height };
	CvRect relate_wall = { col*PIXEL,(row + 1)*PIXEL,PIXEL,PIXEL };
	CvRect relate_wall_1 = { (col + 1)*PIXEL,row*PIXEL,PIXEL,PIXEL };
	CvRect relate_wall_2 = { (col + 1)*PIXEL,(row + 1)*PIXEL,PIXEL,PIXEL };
	if (_map[row][col] != 0 ||
		(Intersect(player, relate_wall_1) && _map[row][col + 1] != 0) ||
		(Intersect(player, relate_wall) && _map[row + 1][col] != 0) ||
		(Intersect(player, relate_wall_2) && _map[row + 1][col + 1] != 0)) {
		cout << "x:" << _player[0]._pos.x << " y:" << _player[0]._pos.y << endl;
		cout << "col:" << col << " row:" << row << endl;
		cout << _map[row][col]<< " " << _map[row][col + 1] << " "<<endl<< _map[row + 1][col] << " " << _map[row + 1][col + 1]  <<endl;
		_player[0]._pos = _player[0]._prePos;
	}

	//Mybullet and wall
	for (int i = 0;i < PLAYNUM;i++) {
		for (int j = 0;j < _player[i]._bullet.size();j++) {
			int col = _player[i]._bullet[j]->_pos.x / PIXEL;int row = _player[i]._bullet[j]->_pos.y / PIXEL;
			CvRect bullet = { _player[i]._bullet[j]->_pos.x,_player[i]._bullet[j]->_pos.y,_player[i]._width,_player[0]._height };
			if (_map[row][col] != 0) {
				_player[i]._bullet[j]->_isNeedClear = true;
				_map[row][col] = 0;
			}
		}
	}

	
}

void T_GameManange::Move()
{
	DIR dir = _keyboard.SenseMove();
	if (dir != DIR_NULL) {
		_player[0].Move(_ui._levelImage->width, _ui._levelImage->height, dir);
	}
	if (_keyboard.IsHit()) {
		_player[0].Attack();
	}


	//
	for (int i = 0;i < PLAYNUM;i++) {
		for (int j = 0;j < _player[i]._bullet.size();j++) {
			_player[i]._bullet[j]->Move(_ui._levelImage->width, _ui._levelImage->height);
		}
	}

	//
	for (int i = 0;i < _enemy.size();i++) {
		_enemy[i]->Move(_ui._levelImage->width, _ui._levelImage->height, _enemy[i]->_dir);
	}
}

void T_GameManange::Draw()
{
	_player[0].Draw(_ui._levelImage);

	//
	for (int i = 0;i < PLAYNUM;i++) {
		for (int j = 0;j < _player[i]._bullet.size();j++) {
			_player[i]._bullet[j]->Draw(_ui._levelImage);
		}
	}

	//
	for (int i = 0;i < _enemy.size();i++) {
		_enemy[i]->Draw(_ui._levelImage);
	}
}

void T_GameManange::Clear()
{
	for (int i = 0;i < PLAYNUM;i++) {
		for (int j = 0;j < _player[i]._bullet.size();j++) {
			if (_player[i]._bullet[j]->_isNeedClear) {
				delete _player[i]._bullet[j];
				_player[i]._bullet.erase(_player[i]._bullet.begin() + i);
			}
		}
	}
}

void T_GameManange::Run()
{
	_enemy.push_back(new T_EnemyTank);
	while (true) {
		_ui.Init(_map);

		Move();
		TestIntersect();
		Clear();
		Draw();

		_ui.Show();
		cvWaitKey(20);
	}
}

DIR T_KeyBoard::SenseMove()
{
	if (GetAsyncKeyState('W') & 0x8000) {
		return DIR(DIR_UP);
	}
	if (GetAsyncKeyState('S') & 0x8000) {
		return DIR(DIR_DOWN);
	}
	if (GetAsyncKeyState('A') & 0x8000) {
		return DIR(DIR_LEFT);
	}
	if (GetAsyncKeyState('D') & 0x8000) {
		return DIR(DIR_RIGHT);
	}
	return DIR(DIR_NULL);
}

bool T_KeyBoard::IsHit()
{
	if (GetAsyncKeyState('J') & 0x8000) {
		return true;
	}
	return false;
}