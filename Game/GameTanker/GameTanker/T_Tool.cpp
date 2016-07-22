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

void T_Tool::Draw(IplImage * background, IplImage * img, CvPoint pos)
{
	for (int i = 0;i < img->height;i++) {
		for (int j = 0;j < img->width;j++) {
			if (j + pos.x < 0 || j + pos.x >= background->width || i + pos.y < 0 || i + pos.y >= background->height) {
				continue;
			}

			int B = CV_IMAGE_ELEM(img, uchar, i, j * 3 + 0);
			int G = CV_IMAGE_ELEM(img, uchar, i, j * 3 + 1);
			int R = CV_IMAGE_ELEM(img, uchar, i, j * 3 + 2);



			CV_IMAGE_ELEM(background, uchar, i + pos.y, (j + pos.x) * 3 + 0) = B;
			CV_IMAGE_ELEM(background, uchar, i + pos.y, (j + pos.x) * 3 + 1) = G;
			CV_IMAGE_ELEM(background, uchar, i + pos.y, (j + pos.x) * 3 + 2) = R;
		}
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

