#include "T_Tool.h"

T_Tool::T_Tool()
{
}

T_Tool::~T_Tool()
{
}

CvPoint T_Tool::RandPos()
{
	CvPoint pos;
	switch (rand()%3)
	{
	case 0:
		pos = { 0,0 };
		break;
	case 1:
		pos = { 9 * 32,0 };
		break;
	case 2:
		pos = { 18 * 32, 0 };
		break;
	default:
		pos = { 0,0 };
		break;
	}
	return CvPoint(pos);
}

DIR T_Tool::GameAI()
{
	switch (rand()%4)
	{
	case 0:
		return DIR_UP;
	case 1:
		return DIR_DOWN;
	case 2:
		return DIR_LEFT;
	case 3:
		return DIR_RIGHT;
	default:
		return DIR_UP;
	}

}

bool T_Tool::Intersect(CvRect r1, CvRect r2)
{
	int c1_x = r1.x + r1.width / 2;
	int c1_y = r1.y + r1.height / 2;

	int c2_x = r2.x + r2.width / 2;
	int c2_y = r2.y + r2.height / 2;

	if ((abs(c1_x - c2_x) == r1.width / 2 + r2.width / 2) || (abs(c1_y - c2_y) == r1.height / 2 + r2.height / 2)) {
		return false;
	}

	if ((abs(c1_x - c2_x) > r1.width / 2 + r2.width / 2) || (abs(c1_y - c2_y) > r1.height / 2 + r2.height / 2)) {
		return false;
	}
	else {
		return true;
	}
	return false;
}

