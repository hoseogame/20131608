#include"Mangchi.h"
void MANGCHI::Render(int _x, int _y)
{
	ScreenPrint(_x - 4, _y - 1, "≧旨收旬");
	ScreenPrint(_x - 4, _y, "↖早統早㏑㏑↖↗");
	ScreenPrint(_x - 4, _y + 1, "≧曲收旭");
}
void MANGCHI::Render_Stay(int _x, int _y)
{
	ScreenPrint(_x - 4, _y - 2, "    ↘");
	ScreenPrint(_x - 4, _y - 1, "  旨收旬");
	ScreenPrint(_x - 4, _y, "  早  早");
	ScreenPrint(_x - 4, _y + 1, "  曲收旭");
	ScreenPrint(_x - 4, _y + 2, "    ‵");
	ScreenPrint(_x - 4, _y + 3, "    ‵");
	ScreenPrint(_x - 4, _y + 4, "    ↘");
	ScreenPrint(_x - 4, _y + 5, "    ↙");
}
void MANGCHI::Init(int _x, int _y)
{
	nIsAttack = 0;
	nIndex = 0;
	nMoveX = _x;
	nMoveY = _y;
	StartTime = 0;
	DelayTime = 300;
}
void MANGCHI::Update(int _x, int _y)
{
}
int MANGCHI::Get_nIsAttack() { return nIsAttack; }
int MANGCHI::Get_StartTime() { return StartTime; }
int MANGCHI::Get_DelayTime() { return DelayTime; }
int MANGCHI::Get_nIndex() { return nIndex; }
int MANGCHI::Get_nMoveX() { return nMoveX; }
int MANGCHI::Get_nMoveY() { return nMoveY; }
void MANGCHI::Set_nIsAttack(int _nIsAttack) { nIsAttack = _nIsAttack; }
void MANGCHI::Set_nIndex(int _nIndex) { nIndex = _nIndex; }
void MANGCHI::Set_nMoveX(int _nMoveX) { nMoveX = _nMoveX; }
void MANGCHI::Set_nMoveY(int _nMoveY) { nMoveY = _nMoveY; }
void MANGCHI::Set_StartTime(clock_t _g_GameStartTime) { StartTime = _g_GameStartTime; }
void MANGCHI::Set_DelayTime(clock_t num) { DelayTime = num; }