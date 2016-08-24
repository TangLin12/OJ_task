
#ifndef _T_GAME_H_INCLUDE_
#define _T_GAME_H_INCLUDE_


#include"T_Tool.h"
#include"T_Keyboard.h"
#include"T_Spirit.h"
#include"T_Map.h"
#include"T_Time.h"
#include"T_Iterm.h"
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
class T_Resource;
#define MAXROW 15
#define MAXCOL 20



enum STATE {
	STATE_MENU,
	STATE_RUN,
	STATE_END,
	STATE_RESTATE,
	STATE_PAUSE
};//��Ϸ״̬

class T_Game {
private:
	int _level;//��ͼ�ؿ�

	T_Game();//��������
	static T_Game* _game;
	
	bool EdgeTest(IplImage* background, IplImage* img, CvPoint pos);//�߽����

	void Edge();//��������ı߽����
	void TestIntersect();//�����������ײ����

	void WinJudge();//�ж�ʤ��
	void AllMove();//����������ƶ�
	void AllAttack();//̹�˹�������
	void AllSense();//�ۺϱ߽���Ժ���ײ����
	void AllClear();//����
	void EnemyUpdate();//������������
	void ItermUpdate();//��������

	void Run();//���к���

	void Set();//��ǰ���趨
	void Reset();//�������

	class T_Garbo
	{
	public:
		~T_Garbo()
		{
			if (T_Game::_game) {
				T_Game::GetInstance()->DestoryInstance();
				delete T_Game::_game;
			}
		}//����������
	};//�����ͷ�
public:
	int _score;//�÷�
	int _enemyLimit;//��������
	int _enemyOnceSize;//����һ�γ�������
	T_Resource* _totalImg;//����ͼƬ��Դ
	vector<T_Spirit*> _myTank;//ʵ�����Լ�̹��
	vector<T_Spirit*> _enemyTank;//ʵ��������̹��
	T_Map _map;//ʵ������ͼ
	STATE _state;//״̬����
	T_Iterm* _iterm;//����ʵ����
	bool _win;//ʤ���ж�

	static T_Game* GetInstance();

	void Init();//��ʼ��Ϸ

	void DestoryInstance();
};


class T_Frame {
public:
	static void InitFrame(T_Game* game);
	static void RunFrame(T_Game* game);
	static void EndFrame(T_Game* game);
};




#endif
