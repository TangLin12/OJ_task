#include "Controller.h"



MY_GameManage::MY_GameManage(){
	MY_Background
}

void MY_GameManage::Run(){
	cvNamedWindow("Dump")
	_gameUi.Show(".\\res\\background0.bmp");
	while (true) {
		_gameUi.Show(".\\res\\background0.bmp");
		CharactorUpdate();
		cvWaitKey(0);
	}
}

void MY_GameManage::CharactorUpdate(){
	_char.Move(_gameUi.GetWidth(), _gameUi.GetHeight());
	_char.Draw(_gameUi.GetNowImage(),_char._pos);
}
