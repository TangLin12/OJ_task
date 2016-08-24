
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
	CvPoint _pos;//位置
	DIR _dir;//方向
	int _speed;//速度
	int _width, _height;//图片宽高
	bool _isNeedClear;//是否需要清除
	virtual void Draw(IplImage *background) = 0;//画图接口
};

class T_Spirit;
class T_Bullet :public T_BitMap{
public:
	IplImage* _img;//图片指针信息
	int _kind;//种类
	int _fireNum;//--爆炸图片

	T_Bullet(CvPoint tank_center_pos, DIR dir);


	void SetImage(IplImage* img);//设定图片

	void Draw(IplImage *background);//画图接口实现
	void Move();//运动

	void Intersenct(T_Spirit* spirit);//与spirit交错
	void DrawFire();//--画爆炸效果
};


class T_Spirit :public T_BitMap{
protected:

public:
	IplImage* _img[4];//四个方向图片
	CvPoint _prePos;//上一个位置
	int _hp;//血量
	vector<T_Bullet*> _bullet;//存储自己子弹
	int _preTime, _nowTime;//时间统计
	int _tankKind;//坦克种类	
	int _bulletKind;//子弹种类--应该放在子弹的构造函数中
	int _itermTime;//道具作用时间

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
