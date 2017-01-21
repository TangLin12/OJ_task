#include "T_Game.h"
#include"T_Resource.h"
T_Game* T_Game::_game = NULL;
//��ʼ����������////////////////////////////////
T_Game::T_Game()
{
	_totalImg = T_Resource::GetInstance();
	_state = STATE_MENU;
<<<<<<< HEAD
	_level = 0;
	mciSendString(TEXT("open ./music/bgm.wav"), NULL, 0, 0);
	mciSendString(TEXT("open ./music/menuBgm.mp3"), NULL, 0, 0);
	mciSendString(TEXT("open ./music/bang.wav"), NULL, 0, 0);
	mciSendString(TEXT("open ./music/Gunfire.wav"), NULL, 0, 0);
	mciSendString(TEXT("open ./music/hit.wav"), NULL, 0, 0);

	mciSendString(TEXT("play ./music/menuBgm.mp3"), NULL, 0, 0);
=======
>>>>>>> parent of e0d9470... add feature
}
//�õ�ʵ��///////////////////////////////////////
T_Game * T_Game::GetInstance()
{
	if (_game == NULL) {
		_game = new T_Game();
	}
	return _game;
}
//��Ϸ״̬����ʼ����////////////////////////////
void T_Game::Init()
{

	while (true) {
		int preTime, nowTime;
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
			preTime = GetTickCount();
			while (true) {
				T_Timer::UpdateOnce();
				if (T_Timer::CheckTimer("Game")) {
					Run();
					nowTime = GetTickCount();
					_score = (1000 - (nowTime - preTime) / 1000) * _myTank[0]->_hp;
					T_Frame::InitFrame(T_Game::GetInstance());
					T_Timer::Reset("Game");
				}
				if (_state != STATE_RUN) {
					break;
				}
				cvWaitKey(20);
			}
			

			Reset();
			T_Timer::UnRegister("Game");
			break;
		case STATE_END:
			T_Frame::InitFrame(T_Game::GetInstance());
			if (T_KeyBoard::IsSpace()) {
				_state = STATE_MENU;
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
//����ʵ����������Դ///////////////////////////////
void T_Game::DestoryInstance()
{
	for (vector<T_Spirit*>::iterator it = _myTank.begin(); it != _myTank.end(); it++){
		if (NULL != *it)
		{
			delete *it;
			*it = NULL;
		}
	}
	_myTank.clear();

	for (vector<T_Spirit*>::iterator it = _enemyTank.begin(); it != _enemyTank.end(); it++) {
		if (NULL != *it)
		{
			delete *it;
			*it = NULL;
		}
	}
	_enemyTank.clear();
}
//��Ե����/////////////////////////////////////
bool T_Game::EdgeTest(IplImage * background, IplImage * img, CvPoint pos)
{
	if (pos.x < 0) {
		return true;
	}
	if (pos.y < 0) {
		return true;
	}
	if (pos.x + img->width>background->width-1) {
		return true;
	}
	if (pos.y + img->height>background->height-1) {
		return true;
	}
	return false;
}
//�������еı�Ե����//////////////////////////////
void T_Game::Edge()
{
	for (unsigned int i = 0;i < _myTank.size();i++) {
		//�ҷ�̹�˼��
		if (EdgeTest(_totalImg->_levelImage, _myTank[i]->_img[0], _myTank[i]->_pos)) {
			_myTank[i]->_pos = _myTank[i]->_prePos;
		}
		//�ҷ��ӵ����
		for (unsigned int j = 0;j < _myTank[i]->_bullet.size();j++) {
			if (EdgeTest(_totalImg->_levelImage, _myTank[i]->_bullet[j]->_img, _myTank[i]->_bullet[j]->_pos)) {
				_myTank[i]->_bullet[j]->_isNeedClear = true;
			}
		}
	}
	
	for (unsigned int i = 0;i < _enemyTank.size();i++) {
		//�з����
		if (EdgeTest(_totalImg->_levelImage, _enemyTank[i]->_img[0], _enemyTank[i]->_pos)) {
			_enemyTank[i]->_pos = _enemyTank[i]->_prePos;
			_enemyTank[i]->_dir = T_Tool::GameAI();
		}
		//�з��ӵ����
		for (unsigned int j = 0;j < _enemyTank[i]->_bullet.size();j++) {
			if (EdgeTest(_totalImg->_levelImage, _enemyTank[i]->_bullet[j]->_img, _enemyTank[i]->_bullet[j]->_pos)) {
				_enemyTank[i]->_bullet[j]->_isNeedClear = true;
			}
		}
	}
}
//�����ж�
void T_Game::TestIntersect()
{
	for (unsigned int i = 0;i < _myTank.size();i++) {
		//��ͼ���ҷ�̹��
		_map.Intersect(_myTank[i]);
		//��ͼ���ҷ��ӵ�
		for (unsigned int k = 0;k < _myTank[i]->_bullet.size();k++) {
			_map.Intersect(_myTank[i]->_bullet[k]);

		}
		for (unsigned int j = 0;j < _enemyTank.size();j++) {
			for (unsigned int k = 0;k < _myTank[i]->_bullet.size();k++) {
				//�ҷ��ӵ������
				_myTank[i]->_bullet[k]->Intersenct(_enemyTank[j]);

			}
			//���˺͵�ͼ
			_map.Intersect(_enemyTank[j]);
			for (unsigned int k = 0;k < _enemyTank[j]->_bullet.size();k++) {
				//��ͼ������ӵ�
				_map.Intersect(_enemyTank[j]->_bullet[k]);
				//�����ӵ����ҷ�̹��
				_enemyTank[j]->_bullet[k]->Intersenct(_myTank[i]);

			}
			//�ҷ�̹����з�̹��
			_myTank[i]->Intersect(_enemyTank[j]);
		}
	}

}
//ʤ���жϣ�״̬ת��//////////////////////////
void T_Game::WinJudge()
{
	
	if (_myTank[0]->_hp <= 0) {
		_win = false;
		_state = STATE_END;
	}
	if (_enemyLimit <= 0) {
		_win = true;
		_state = STATE_END;
	}
	if (_map._map[14][9] == 0) {
 		_win= false;
		_state = STATE_END;
	}
}
//�����ƶ�//////////////////////////////////
void T_Game::AllMove()
{
	for (unsigned int i = 0;i < _myTank.size();i++) {
		DIR dir = T_KeyBoard::SenseMove();
		if (dir != DIR_NULL) {
			//�ҷ�̹���ƶ�
			_myTank[i]->Move(dir);
		}
		for (unsigned int j = 0;j < _myTank[i]->_bullet.size();j++) {
			//�ҷ��ӵ��ƶ�
			_myTank[i]->_bullet[j]->Move();
		}
	}

	for (unsigned int i = 0;i < _enemyTank.size();i++) {
		//�з�̹���ƶ�
		_enemyTank[i]->Move(_enemyTank[i]->_dir);
		for (unsigned int j = 0;j < _enemyTank[i]->_bullet.size();j++) {
			//�з��ӵ��ƶ�
			_enemyTank[i]->_bullet[j]->Move();
		}
	}

}
//�����źż��/////////////////////////////
void T_Game::AllAttack()
{
	//�ҷ�����
	if (T_KeyBoard::IsHit()) {
		_myTank[0]->Attack();
<<<<<<< HEAD
		mciSendString(TEXT("play ./music/Gunfire.wav"), NULL, 0, 0);
		mciSendString(TEXT("open ./music/Gunfire.wav"), NULL, 0, 0);
=======
>>>>>>> parent of e0d9470... add feature
	}
	//�з�����
	for (int i = 0;i < _enemyTank.size();i++) {
		_enemyTank[i]->Attack();
	}

}
//��Ե���Ӽ����///////////////////////////
void T_Game::AllSense()
{
 	Edge();
	TestIntersect();
}
//���������flag��isNeedClear=true������
void T_Game::AllClear()//
{
	//���ҷ��ӵ�
	for (int i = 0;i < _myTank.size();i++) {
		for (int j = 0;j < _myTank[i]->_bullet.size();j++) {
			if (_myTank[i]->_bullet[j]->_isNeedClear) {
				delete _myTank[i]->_bullet[j];
				_myTank[i]->_bullet.erase(_myTank[i]->_bullet.begin() + j);
				
			}
		}
	}
	//��з��ӵ���̹��
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
			_enemyLimit--;
		}
		
	}
}
//�����ٵ��ĵ���/////////////////////////////
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
	for (int i = _enemyTank.size();i < _enemyOnceSize&&i<_enemyLimit;i++) {
		_enemyTank.push_back(new T_EnemyTank(T_Tool::RandPos()));
		_enemyTank[i]->SetImage(_totalImg->_enemyTank[0]);
		string name = "enemy";
		name.append(sizeof(char), static_cast<char>(i));
		T_Timer::Register(name, 400);
	}
}
//���µ���///////////////////////////
void T_Game::ItermUpdate()
{
	_iterm->_nowTime = GetTickCount();
	if (_iterm->_nowTime - _iterm->_preTime >= 20000) {
		_iterm = new T_Iterm(GetTickCount());
	}
	if (_iterm->GetIterm(_myTank[0])) {
		_map._map[14][8] = _map._map[13][8] = _map._map[13][9] = OBJ_IRON;
		_map._map[14][10] = _map._map[13][10] = OBJ_IRON;
		_map._wallTime = 300;
	}
	if (_myTank[0]->_bulletKind == 3) {
		_enemyTank.clear();
		_myTank[0]->_bulletKind = 1;
	}
}

//���µ�ǰ֡//////////////////////////////////
void T_Game::Run()
{
	AllMove();
	AllAttack();
	AllSense();
	WinJudge();
	AllClear();
	EnemyUpdate();
	ItermUpdate();
}
//�趨���ֲ���/////////////////////////////////
void T_Game::Set()
{
	_enemyLimit = 8;
	_enemyOnceSize = 3;
	for (int i = 0;i < 1;i++) {
		_myTank.push_back(new T_MyTank());
		_myTank[i]->SetImage(_totalImg->_myTank);
	}
	for (int i = 0;i < _enemyOnceSize;i++) {
		_enemyTank.push_back(new T_EnemyTank(T_Tool::RandPos()));
		_enemyTank[i]->_tankKind = rand() % 2;
		_enemyTank[i]->SetImage(_totalImg->_enemyTank[_enemyTank[i]->_tankKind]);
		string name = "enemy";
		name.append(sizeof(char), static_cast<char>(i));
		T_Timer::Register(name, 400);
	}
	_iterm = new T_Iterm(GetTickCount());
<<<<<<< HEAD

	_map.Load(_level);

=======
	_map._map = _map._mapSpare;
>>>>>>> parent of e0d9470... add feature
	_score = 0;
}
//�����Ͼֲ���//////////////////////////////////
void T_Game::Reset()
{
	_myTank.clear();
	_enemyTank.clear();
}
//��֡����//////////////////////////////////
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
		EndFrame(game);
		break;
	case STATE_RESTATE:
		break;
	case STATE_PAUSE:
		break;
	}
}
//��Ϸ�е�֡����Ⱦ//////////////////////////
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

	if (game->_iterm->_showTime > 0) {
		game->_iterm->_showTime--;
		game->_iterm->Draw(game->_totalImg->_levelImage);
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

<<<<<<< HEAD
	CvPoint pos = { 660,20 };
	for (int i = 0;i < game->_enemyLimit;i++) {
		T_Tool::Draw(game->_totalImg->_levelImage, game->_totalImg->_num, pos);
		pos.x += 40;
		if (i % 2 == 1) {
			pos.x = 660;
			pos.y += 30;
		}
	}

	pos = { 660,300 };
	for (unsigned int i = 0;i < game->_myTank.size();i++) {
		for (int j = 0;j < game->_myTank[i]->_hp;j++) {
			T_Tool::Draw(game->_totalImg->_levelImage, game->_totalImg->_blood, pos);
			pos.x += 40;
			if (i % 3 == 1) {
				pos.x = 660;
				pos.y += 30;
			}
		}
	}
=======
>>>>>>> parent of e0d9470... add feature
	

	game->_totalImg->ShowFrame();
}
//��Ϸ����ʱ��֡����Ⱦ//////////////////////
void T_Frame::EndFrame(T_Game * game)
{
	cvCopy(game->_totalImg->_end, game->_totalImg->_endUI);
	vector<int> score;
	while (game->_score) {
		score.push_back(game->_score % 10);
		game->_score /= 10;
	}
	if (score.size() == 0) {
		score.push_back(0);
	}
	CvPoint pos = { 450 - score.size()*game->_totalImg->_nums[score[0]]->width/2,200 };
	for (int i = score.size() - 1;i >= 0;i--) {
		T_Tool::Draw(game->_totalImg->_endUI, game->_totalImg->_nums[score[i]],pos);
		pos.x += game->_totalImg->_nums[score[i]]->width;
	}
	cvShowImage("TankGame", game->_totalImg->_endUI);
	cvWaitKey();
	game->_state=STATE_MENU;
}
