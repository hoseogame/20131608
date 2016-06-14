#include"Dudagi.h"
DUDAGI::DUDAGI()
{
}
DUDAGI::~DUDAGI()
{
}
void DUDAGI::Init(int _x, int _y)
{
	nX = _x;
	nY = _y;
	nState = SETUP;
}
void DUDAGI::Update(int _UpLimitTime, int _DownLimitTime)
{
	OutPutTime = rand() % _UpLimitTime + 10;
	StayTime = rand() % _DownLimitTime + 10;
	nState = UP;
}
void DUDAGI::Render(int _x, int _y)
{
	if (nState == UP)
		ScreenPrint(_x, _y, "กÜ");
	ScreenPrint(_x, _y + 1, "ขอ");
}

void DUDAGI::Set_nX(int _x) { nX = _x; }
int DUDAGI::Get_nX() { return nX; }
void DUDAGI::Set_nY(int _y) { nY = _y; }
int DUDAGI::Get_nY() { return nY; };
DUDAGI_STATE DUDAGI::Get_nState() { return nState; }
clock_t DUDAGI::Get_StayTime() { return StayTime; }
clock_t	DUDAGI::Get_OutPutTime() { return OutPutTime; }
clock_t	DUDAGI::Get_OldTime() { return OldTime; }
void DUDAGI::Set_nState(DUDAGI_STATE _nState) { nState = _nState; }
void DUDAGI::Set_StayTime(clock_t _StayTime) { StayTime = _StayTime; }
void DUDAGI::Set_OutPutTime(clock_t _OutPutTime) { OutPutTime = _OutPutTime; }
void DUDAGI::Set_OldTime(clock_t	_OldTime) { OldTime = _OldTime; }