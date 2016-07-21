
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

	static CvPoint RandPos();
	static DIR GameAI();
	static bool Intersect(CvRect r1, CvRect r2);
};

#endif
