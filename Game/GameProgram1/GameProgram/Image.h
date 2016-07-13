#ifndef _IMAGE_H_INCLUDED_
#define _IMAGE_H_INCLUDED_

#include<cv.h>
#include<highgui.h>

class MY_BitMap {
protected:
	IplImage* _img;
	int _width;
	int _height;
public:
	MY_BitMap() { ; }
	~MY_BitMap() { ; }

	int GetWidth() { return _width; }
	int GetHeight() { return _height; }
	IplImage* GetNowImage() { return _img; }
};

class MY_BackGround :private MY_BitMap {
public:
	MY_BackGround(const char* filename) {
		_img = cvLoadImage(filename);
		if (_img) {
			_width = _img->width;
			_height = _img->height;
		}
	}

	void Show(const char* window_name) {
		cvShowImage(window_name, _img);
	}
};

class MY_Obj :private MY_BitMap {
protected:
	CvPoint _pos;
public:
	MY_Obj(const char* filename,CvPoint pos):_pos(pos) {
		_img = cvLoadImage(filename);
		if (_img) {
			_width = _img->width;
			_height = _img->height;
		}
	}

	void Draw(IplImage* bg_img, IplImage* top_img) {
		if (bg_img != NULL&&top_img != NULL) {
			for (int i = 0;i < top_img->height;i++) {
				for (int j = 0;j < top_img->width;j++) {
					int B = CV_IMAGE_ELEM(img, uchar, i, j * 3 + 0);
					int G = CV_IMAGE_ELEM(img, uchar, i, j * 3 + 1);
					int R = CV_IMAGE_ELEM(img, uchar, i, j * 3 + 2);

					if (j + _pos.x < 0 || j + _pos.x >= bg_img->width || i + _pos.y < 0 || i + _pos.y >= bg_img->height) {
						continue;
					}

					CV_IMAGE_ELEM(bg, uchar, i + posY, (j + posX) * 3 + 0) = B;
					CV_IMAGE_ELEM(bg, uchar, i + posY, (j + posX) * 3 + 1) = G;
					CV_IMAGE_ELEM(bg, uchar, i + posY, (j + posX) * 3 + 2) = R;
				}
			}
		}
		else {
			return;
		}
	}
};

#endif