
#ifndef _T_SPIRIT_H_INCLUDED_
#define _T_SPIRIT_H_INCLUDED_

#include<cv.h>
#include<highgui.h>
#include<vector>

using namespace std;

enum DIR ;

#define PIXEL 32

class T_BitMap {
public:
	CvPoint _pos;//λ��
	DIR _dir;//����
	int _speed;//�ٶ�
	int _width, _height;//ͼƬ���
	bool _isNeedClear;//�Ƿ���Ҫ���
	virtual void Draw(IplImage *background) = 0;//��ͼ�ӿ�
};

class T_Spirit;
class T_Bullet :public T_BitMap{
public:
	IplImage* _img;//ͼƬָ����Ϣ
	int _kind;//����
	int _fireNum;//--��ըͼƬ

	T_Bullet(CvPoint tank_center_pos, DIR dir);


	void SetImage(IplImage* img);//�趨ͼƬ

	void Draw(IplImage *background);//��ͼ�ӿ�ʵ��
	void Move();//�˶�

	void Intersenct(T_Spirit* spirit);//��spirit����
	void DrawFire();//--����ըЧ��
};


class T_Spirit :public T_BitMap{
protected:

public:
	IplImage* _img[4];//�ĸ�����ͼƬ
	CvPoint _prePos;//��һ��λ��
	int _hp;//Ѫ��
	vector<T_Bullet*> _bullet;//�洢�Լ��ӵ�
	int _preTime, _nowTime;//ʱ��ͳ��
	int _tankKind;//̹������	
	int _bulletKind;//�ӵ�����--Ӧ�÷����ӵ��Ĺ��캯����
	int _itermTime;//��������ʱ��

	virtual void SetImage(IplImage* img[]) = 0;
	virtual void Draw(IplImage* background) = 0;
	virtual	void Move(DIR dir) = 0;
	virtual void Intersect(T_Spirit* pSpirit) {}
	void Attack();
	CvRect GetRecet();
};


class T_MyTank :public T_Spirit{
public:
	

	T_MyTank();

	void SetImage(IplImage* img[]);
	void Draw(IplImage *background);
	void Move(DIR dir);
	void Intersect(T_Spirit* pSpirit);

};

class T_EnemyTank :public T_Spirit {
public:
	T_EnemyTank(CvPoint pos);

	void SetImage(IplImage* img[]);
	void Draw(IplImage *background);
	void Move(DIR dir);
};
#endif
