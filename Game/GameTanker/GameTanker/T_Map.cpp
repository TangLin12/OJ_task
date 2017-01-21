#include "T_Map.h"
<<<<<<< HEAD
#include<fstream>
//基本构造函数
=======

>>>>>>> parent of e0d9470... add feature
T_Map::T_Map()
{
	_map = {
		{ 0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,2 },
		{ 0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,2 },
		{ 0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,1,2 },
		{ 0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,2 },
		{ 0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,2,2 },
		{ 0,2,1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,2 },
		{ 0,2,1,0,1,0,0,0,0,1,0,0,1,0,0,1,0,0,0,2 },
		{ 0,2,1,0,1,0,2,0,1,1,2,0,0,0,0,0,0,0,2,2 },
		{ 0,1,1,1,1,0,3,3,3,3,3,3,3,0,0,0,0,0,0,2 },
		{ 0,1,0,1,1,1,3,3,3,3,3,3,3,3,3,3,3,0,0,2 },
		{ 0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,2 },
		{ 1,1,0,1,1,1,0,0,1,2,0,0,1,0,0,0,0,2,0,2 },
		{ 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,2 },
		{ 0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,2 },
		{ 2,2,2,2,2,2,2,2,1,7,1,2,2,2,2,2,2,2,2,2 },
	};
<<<<<<< HEAD
	_wallTime = -1;

}
//文件读图///////////////////////////////////////
void T_Map::Load(int kind)
{
	char filename[40];
	sprintf_s(filename, "./map/map%d.txt", kind);
	ifstream in(filename);
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			in >> _map[i][j];
		}
	}
	_wallTime = -1;
}
//备忘录读图///////////////////////////////////
void T_Map::Load(T_Memento memento)
{
	_map = memento._map;
}
//保存当前图///////////////////////////////////
T_Memento T_Map::Save()
{
	T_Memento memento(_map);
	return memento;
=======
	_wallTime = 0;
	_mapSpare = _map;
>>>>>>> parent of e0d9470... add feature
}
//读图的交错判定-与子弹/////////////////////////
void T_Map::Intersect(T_Bullet * bullet)
{
	if (bullet->_isNeedClear) {
		return;
	}
	int col = (bullet->_pos.x + bullet->_width) / PIXEL;
	int row = (bullet->_pos.y + bullet->_height) / PIXEL;
	if(col>19||row>15){
		bullet->_isNeedClear=true;
		return;
	}
	switch (_map[row][col])
	{
	case OBJ_BLOCK:
	case OBJ_STAR:
		bullet->_isNeedClear = true;
		_map[row][col] = 0;
		break;
	case OBJ_IRON:
		bullet->_isNeedClear = true;
		break;
	case OBJ_NULL:
	case OBJ_GRASS:
		break;
	default:
		break;
	}
}

//该点是否不能穿过
bool T_Map::CantMove(int col, int row)
{
	if (row > 16 || col > 19) {
		return true;
	}
	switch (_map[row][col])
	{
	case OBJ_NULL:
	case OBJ_GRASS:
		return false;	
	default:
		return true;
	}
}
//交错判定重载-与spirit//////////////////////
void T_Map::Intersect(T_Spirit* spirit) {
	int col = spirit->_pos.x / PIXEL;
	int row = spirit->_pos.y / PIXEL;
	CvRect player = { spirit->_pos.x,spirit->_pos.y,spirit->_width,spirit->_height };
	CvRect relate_wall = { col*PIXEL,(row + 1)*PIXEL,PIXEL,PIXEL };
	CvRect relate_wall_1 = { (col + 1)*PIXEL,row*PIXEL,PIXEL,PIXEL };
	CvRect relate_wall_2 = { (col + 1)*PIXEL,(row + 1)*PIXEL,PIXEL,PIXEL };
	
	if (CantMove(col, row) ||
		(CantMove(col, row + 1) && T_Tool::Intersect(player, relate_wall))||
		(CantMove(col + 1, row) && T_Tool::Intersect(player, relate_wall_1)) ||
		(CantMove(col + 1, row + 1) && T_Tool::Intersect(player, relate_wall_2))) {
		spirit->_pos = spirit->_prePos;
	}


}
//绘图方法//////////////////////////////////
void T_Map::Draw(IplImage * background, CvPoint pos, KIND kind)
{
	if (kind == OBJ_NULL) {
		return;
	}
	IplImage* _img = T_Resource::GetInstance()->_mapNode[kind];
	for (int i = 0;i < _img->height;i++) {
		for (int j = 0;j < _img->width;j++) {
			if (j + pos.x < 0 || j + pos.x >= background->width || i + pos.y < 0 || i + pos.y >= background->height) {			//go over the map
				continue;
			}

			int B = CV_IMAGE_ELEM(_img, uchar, i, j * 3 + 0);
			int G = CV_IMAGE_ELEM(_img, uchar, i, j * 3 + 1);
			int R = CV_IMAGE_ELEM(_img, uchar, i, j * 3 + 2);

			CV_IMAGE_ELEM(background, uchar, i + pos.y, (j + pos.x) * 3 + 0) = B;
			CV_IMAGE_ELEM(background, uchar, i + pos.y, (j + pos.x) * 3 + 1) = G;
			CV_IMAGE_ELEM(background, uchar, i + pos.y, (j + pos.x) * 3 + 2) = R;
		}
	}
}
<<<<<<< HEAD
//存储memento
void T_Archive::AddIterm(T_Memento memento)
{
	_mementoArray.push_back(memento);
}
//读取memento
T_Memento T_Archive::Load(int state)
{
	return _mementoArray[state];
}
=======
>>>>>>> parent of e0d9470... add feature
