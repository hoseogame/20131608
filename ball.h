#pragma once
#include"Object.h"
class BALL :public Object
{
private:
	bool nIsReady;        // 준비 상태(1), 슛상태(0)
	int nMoveX, nMoveY;  // 이동 좌표
	clock_t MoveTime;    // 이동 시간 간격
	clock_t OldTime;     // 이전 이동 시각
public:
	BALL();
	~BALL();
	void Init(int, int);
	void Update(int, int);
	void Render(int, int);
	void Set_nMoveX(int);
	int Get_nMoveX();
	void Set_nMoveY(int);
	int Get_nMoveY();
	void Set_nIsReady(bool);
	bool Get_nIsReady();
	void Set_MoveTime(clock_t);
	clock_t Get_MoveTime();
	void Set_OldTime(clock_t);
	clock_t Get_OldTime();
};