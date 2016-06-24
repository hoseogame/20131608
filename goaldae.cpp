#include"goaldae.h"

void GOAL_DAE::Init(int, int)
{
}

void GOAL_DAE::Update(int, int)
{
}

void GOAL_DAE::Render(int, int)
{
}

void GOAL_DAE::Init(int _nGoalDaeX, int _nGoalDaeY, int _nGoalDaeLength, clock_t _MoveTime, int _nDist)
{
	int _nLength;
	nMoveX = _nGoalDaeX;
	nMoveY = _nGoalDaeY;
	nLength = _nGoalDaeLength;
	MoveTime = _MoveTime;
	OldTime = clock();
	nDist = _nDist;
	_nLength = nLength * 2 + 1; // Note: 배열의 최대 길이
	for (int i = 0; i < _nLength; i++)
	{
		nLineX[i] = nMoveX + 2 * (i + 1);
	}
}
void GOAL_DAE::Update(clock_t _CurTime, int _Length)
{
	if (_CurTime - OldTime > MoveTime)
	{
		OldTime = _CurTime;
		if (nMoveX + nDist >= 2 && ((nLineX[_Length - 1] + 3) + nDist) <= 43)
		{
			nMoveX += nDist;
			for (int i = 0; i < _Length; i++)
			{
				nLineX[i] = nMoveX + 2 * (i + 1);
			}
		}
		else {
			nDist = nDist * -1; // -1 이 방향을 바꾸어 줌.
		}
	}
}
void GOAL_DAE::Render(int _nLength)
{
	ScreenPrint(nMoveX, nMoveY, "□");
	for (int i = 0; i < _nLength; i++)
		ScreenPrint(nLineX[i], nMoveY, "━");
	ScreenPrint(nLineX[_nLength - 1] + 2, nMoveY, "□");
}
void GOAL_DAE::Set_nMoveX(int _nMoveX) { nMoveX = _nMoveX; }
int GOAL_DAE::Get_nMoveX() { return nMoveX; }
void GOAL_DAE::Set_nMoveY(int _nMoveY) { nMoveY = _nMoveY; }
int GOAL_DAE::Get_nMoveY() { return nMoveY; }
void GOAL_DAE::Set_nLength(int _nLength) { nLength = _nLength; }
int GOAL_DAE::Get_nLength() { return nLength; }
void GOAL_DAE::Set_nLineX(int _nLineX, int i) { nLineX[i] = _nLineX; }
int GOAL_DAE::Get_nLineX(int i) { return nLineX[i]; }
void GOAL_DAE::Set_MoveTime(clock_t _MoveTime) { MoveTime = _MoveTime; }
clock_t GOAL_DAE::Get_MoveTime() { return MoveTime; }
void GOAL_DAE::Set_OldTime(clock_t _OldTime) { OldTime = _OldTime; }
clock_t GOAL_DAE::Get_OldTime() { return OldTime; }
void GOAL_DAE::Set_nDist(int _nDist) { nDist = _nDist; }
int GOAL_DAE::Get_nDist() { return nDist; }