#include"ball.h"
BALL::BALL()
{
}
BALL::~BALL()
{
}
void BALL::Init(int _nMoveX, int _nMoveY)
{
	// 공의 초기화
	nMoveX = _nMoveX;
	nMoveY = _nMoveY;
	nIsReady = true;
	MoveTime = 100;
}

void BALL::Update(int _x, int _y)
{
	nMoveX = _x;
	nMoveY = _y - 1;
}

void BALL::Render(int _x,int _y)
{
	ScreenPrint(_x, _y, "⊙");
}

void BALL::Set_nMoveX(int _nMoveX) { nMoveX = _nMoveX; }
int BALL::Get_nMoveX() { return nMoveX; }
void BALL::Set_nMoveY(int _nMoveY) { nMoveY = _nMoveY; }
int BALL::Get_nMoveY() { return nMoveY; }
void BALL::Set_nIsReady(bool _nIsReady) { nIsReady = _nIsReady; }
bool BALL::Get_nIsReady() { return nIsReady; }
void BALL::Set_MoveTime(clock_t _MoveTime) { MoveTime = _MoveTime; }
clock_t BALL::Get_MoveTime() { return MoveTime; }
void BALL::Set_OldTime(clock_t _OldTime) { OldTime = _OldTime; }
clock_t BALL::Get_OldTime() { return OldTime; }