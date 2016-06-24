#pragma once
#include"Define.h"
#include"Object.h"
class GOAL_DAE :public Object
{
private:
	int nMoveX, nMoveY;     // 이동 좌표 
	int nLength;			// 골대 길이	
	int nLineX[7];			// 골인 라인 x 좌표 (7개)
	clock_t	MoveTime;		// 이동 시간 간격
	clock_t	OldTime;	    // 이전 이동 시간
	int	nDist;				// 이동 거리
public:
	void Init(int,int);
	void Update(int, int);
	void Render(int, int);
	void Init(int, int, int, clock_t, int);
	void Update(clock_t, int);
	void Render(int);
	void Set_nMoveX(int);
	int Get_nMoveX();
	void Set_nMoveY(int);
	int Get_nMoveY();
	void Set_nLength(int);
	int Get_nLength();
	void Set_nLineX(int, int);
	int Get_nLineX(int);
	void Set_MoveTime(clock_t);
	clock_t Get_MoveTime();
	void Set_OldTime(clock_t);
	clock_t Get_OldTime();
	void Set_nDist(int);
	int Get_nDist();
};