
#ifndef _T_TOOL_H_INCLUDE_
#define _T_TOOL_H_INCLUDE_

#include<cv.h>
#include<highgui.h>

enum DIR {
	DIR_UP = 0,
	DIR_DOWN = 1,
	DIR_LEFT = 2,
	DIR_RIGHT = 3,
	DIR_NULL = 4
};

class T_Tool {
public:
	T_Tool();
	~T_Tool();

<<<<<<< HEAD
	static CvPoint RandPos();//敌人坦克出现
	static DIR GameAI();//敌人AI
	static void Draw(IplImage* background, IplImage* img, CvPoint pos);//公有画图接口
	static bool Intersect(CvRect r1, CvRect r2);//交错判定
=======
	static CvPoint RandPos();
	static DIR GameAI();
	static bool Intersect(CvRect r1, CvRect r2);
>>>>>>> parent of e0d9470... add feature
};

#endif
