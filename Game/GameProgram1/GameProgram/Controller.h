#include"Image.h"

class MY_GameManage {
private:
	MY_BackGround _gameUi;
	MY_Charactor _char;
public:
	MY_GameManage();
	void Run();
	void CharactorUpdate();
};