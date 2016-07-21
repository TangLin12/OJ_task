#include "T_Game.h"
#include"T_Resource.h"
T_Game* T_Game::_game = NULL;
T_Game::T_Game()
{
	_totalImg = T_Resource::GetInstance();
	_state = STATE_MENU;
}

T_Game * T_Game::GetInstance()
{
	if (_game == NULL) {
		_game = new T_Game();
	}
	return _game;
}

void T_Game::Init()
{

	while (true) {
		switch (_state) {
		case STATE_MENU:
			T_Frame::InitFrame(T_Game::GetInstance());
			if (T_KeyBoard::IsSpace()) {
				_state = STATE_RUN;
				if (!T_Timer::CheckTimer("Game")) {
					T_Timer::Register("Game", 100);
				}
				T_Timer::Reset("Game");
			}
			break;
		case STATE_RUN: 
			Set();
			while (true) {
				T_Timer::UpdateOnce();
				if (T_Timer::CheckTimer("Game")) {
					Run();
					T_Frame::InitFrame(T_Game::GetInstance());
					T_Timer::Reset("Game");
				}
				if (_state != STATE_RUN) {
					break;
				}
				cvWaitKey(20);
			}
			break;
		case STATE_END:
			T_Frame::InitFrame(T_Game::GetInstance());
			if (T_KeyBoard::IsSpace()) {
				_state = STATE_RUN;
			}
			break;
		case STATE_RESTATE:
			break;
		case STATE_PAUSE:
			break;
		}
		cvWaitKey(20);
	}
}

bool T_Game::EdgeTest(IplImage * background, IplImage * img, CvPoint pos)
{
	if (pos.x < 0) {
		return true;
	}
	if (pos.y < 0) {
		return true;
	}
	if (pos.x + img->width>background->width) {
		return true;
	}
	if (pos.y + img->height>background->height) {
		return true;
	}
	return false;
}

void T_Game::Edge()
{
	for (unsigned int i = 0;i < _myTank.size();i++) {
		if (EdgeTest(_totalImg->_levelImage, _myTank[i]->_img[0], _myTank[i]->_pos)) {
			_myTank[i]->_pos = _myTank[i]->_prePos;
		}
		for (unsigned int j = 0;j < _myTank[i]->_bullet.size();j++) {
			if (EdgeTest(_totalImg->_levelImage, _myTank[i]->_bullet[j]->_img, _myTank[i]->_bullet[j]->_pos)) {
				_myTank[i]->_bullet[j]->_isNeedClear = true;
			}
		}
	}

	for (unsigned int i = 0;i < _enemyTank.size();i++) {
		if (EdgeTest(_totalImg->_levelImage, _enemyTank[i]->_img[0], _enemyTank[i]->_pos)) {
			_enemyTank[i]->_pos = _enemyTank[i]->_prePos;
			_enemyTank[i]->_dir = T_Tool::GameAI();
		}
		for (unsigned int j = 0;j < _enemyTank[i]->_bullet.size();j++) {
			if (EdgeTest(_totalImg->_levelImage, _enemyTank[i]->_bullet[j]->_img, _enemyTank[i]->_bullet[j]->_pos)) {
				_enemyTank[i]->_bullet[j]->_isNeedClear = true;
			}
		}
	}
}

void T_Game::TestIntersect()
{
	for (unsigned int i = 0;i < _myTank.size();i++) {
		_map.Intersect(_myTank[i]);
		for (unsigned int k = 0;k < _myTank[i]->_bullet.size();k++) {
			_map.Intersect(_myTank[i]->_bullet[k]);

		}
		for (unsigned int j = 0;j < _enemyTank.size();j++) {
			for (unsigned int k = 0;k < _myTank[i]->_bullet.size();k++) {
				_myTank[i]->_bullet[k]->Intersenct(_enemyTank[j]);

			}
			_map.Intersect(_enemyTank[j]);
			for (unsigned int k = 0;k < _enemyTank[j]->_bullet.size();k++) {
				_map.Intersect(_enemyTank[j]->_bullet[k]);
				_enemyTank[j]->_bullet[k]->Intersenct(_myTank[i]);
			}
			_myTank[i]->Intersect(_enemyTank[j]);
		}
	}

}

void T_Game::AllMove()
{
	for (unsigned int i = 0;i < _myTank.size();i++) {
		DIR dir = T_KeyBoard::SenseMove();
		if (dir != DIR_NULL) {
			_myTank[i]->Move(dir);
		}
		for (unsigned int j = 0;j < _myTank[i]->_bullet.size();j++) {
			_myTank[i]->_bullet[j]->Move();
		}
	}

	for (unsigned int i = 0;i < _enemyTank.size();i++) {
		_enemyTank[i]->Move(_enemyTank[i]->_dir);
		for (unsigned int j = 0;j < _enemyTank[i]->_bullet.size();j++) {
			_enemyTank[i]->_bullet[j]->Move();
		}
	}

}

void T_Game::AllAttack()
{
	if (T_KeyBoard::IsHit()) {
		_myTank[0]->Attack();
	}
	for (int i = 0;i < _enemyTank.size();i++) {
		_enemyTank[i]->Attack();
	}

}

void T_Game::AllSense()
{
 	Edge();
	TestIntersect();
}

void T_Game::AllClear()//
{
	for (int i = 0;i < _myTank.size();i++) {
		if (_myTank[i]->_isNeedClear) {
			_state = STATE_END;
			return;
		}
		for (int j = 0;j < _myTank[i]->_bullet.size();j++) {
			if (_myTank[i]->_bullet[j]->_isNeedClear) {
				delete _myTank[i]->_bullet[j];
				_myTank[i]->_bullet.erase(_myTank[i]->_bullet.begin() + j);
				--_enemyLimit;
			}
		}
	}

	for (int i = 0;i < _enemyTank.size();i++) {
		for (int j = 0;j < _enemyTank[i]->_bullet.size();j++) {
			if (_enemyTank[i]->_bullet[j]->_isNeedClear) {
				delete _enemyTank[i]->_bullet[j];
				_enemyTank[i]->_bullet.erase(_enemyTank[i]->_bullet.begin() + j);
			}
		}
		if (_enemyTank[i]->_isNeedClear) {
			delete _enemyTank[i];
			_enemyTank.erase(_enemyTank.begin() + i);
		}
		
	}
}

void T_Game::EnemyUpdate()
{
	for (int i = 0;i < _enemyTank.size();i++) {
		string name = "enemy";
		name.append(sizeof(char), static_cast<char>(i));
		if (T_Timer::CheckTimer(name)) {
			_enemyTank[i]->_dir = T_Tool::GameAI();
			T_Timer::Reset(name);
		}
	}
	for (int i = _enemyTank.size();i < _enemyOnceSize;i++) {
		_enemyTank.push_back(new T_EnemyTank(T_Tool::RandPos()));
		_enemyTank[i]->SetImage(_totalImg->_enemyTank);
		string name = "enemy";
		name.append(sizeof(char), static_cast<char>(i));
		T_Timer::Register(name, 400);
	}
}



void T_Game::End()
{
	if (_myTank[0]->_isNeedClear||_enemyLimit==0) {
		_state = STATE_END;
		return;
	}
	
}

void T_Game::Run()
{
	AllMove();
	AllAttack();
	AllSense();
	AllClear();
	EnemyUpdate();
}

void T_Game::Set()
{
	_enemyLimit = 10;
	_enemyOnceSize = 3;
	for (int i = 0;i < 1;i++) {
		_myTank.push_back(new T_MyTank());
		_myTank[i]->SetImage(_totalImg->_myTank);
	}
	for (int i = 0;i < _enemyOnceSize;i++) {
		_enemyTank.push_back(new T_EnemyTank(T_Tool::RandPos()));
		_enemyTank[i]->SetImage(_totalImg->_enemyTank);
		string name = "enemy";
		name.append(sizeof(char), static_cast<char>(i));
		T_Timer::Register(name, 400);
	}
}

void T_Frame::InitFrame(T_Game * game)
{
	switch (game->_state) {
	case STATE_MENU:
		cvShowImage("TankGame", game->_totalImg->_meun);
		break;
	case STATE_RUN:
		RunFrame(game);
		break;
	case STATE_END:
		cvShowImage("TankGame", game->_totalImg->_meun);
		break;
	case STATE_RESTATE:
		break;
	case STATE_PAUSE:
		break;
	}
}

void T_Frame::RunFrame(T_Game * game)
{
	for (int col = 0;col < MAXCOL;col++) {
		for (int row = 0;row < MAXROW;row++) {
			KIND now_kind;
			switch (game->_map._map[row][col]) {
			case 0:
				now_kind = OBJ_NULL;break;
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
			T_Map::Draw(game->_totalImg->_levelImage, pos, now_kind);
		}
	}

	for (int i = 0;i < game->_myTank.size();i++) {
		game->_myTank[i]->Draw(game->_totalImg->_levelImage);
		for (int j = 0;j < game->_myTank[i]->_bullet.size();j++) {
			game->_myTank[i]->_bullet[j]->Draw(game->_totalImg->_levelImage);
		}
	}

	for (int i = 0;i < game->_enemyTank.size();i++) {
		game->_enemyTank[i]->Draw(game->_totalImg->_levelImage);
		for (int j = 0;j < game->_enemyTank[i]->_bullet.size();j++) {
			game->_enemyTank[i]->_bullet[j]->Draw(game->_totalImg->_levelImage);
		}
	}

	game->_totalImg->ShowFrame();
}
