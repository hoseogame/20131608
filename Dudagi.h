#pragma once
#include"Object.h"
typedef enum _DUDAGI_STATE { SETUP, UP, DOWN } DUDAGI_STATE;
class DUDAGI :public Object
{
private:
	int nX;
	int nY;
	DUDAGI_STATE nState;	// Note: �δ��� ����	
	clock_t   StayTime;     // Note: ���� �� ��� �ð�
	clock_t	OutPutTime;     // Note: ������ �� ��� �ð�
	clock_t	OldTime;        // Note: ���� �ð�		
public:
	DUDAGI();
	~DUDAGI();
	void Init(int, int);
	void Update(int, int);
	void Render(int, int);

	void Set_nX(int);
	int Get_nX();
	void Set_nY(int);
	int Get_nY();
	DUDAGI_STATE Get_nState();
	clock_t Get_StayTime();
	clock_t	Get_OutPutTime();
	clock_t	Get_OldTime();
	void Set_nState(DUDAGI_STATE _nState);
	void Set_StayTime(clock_t _StayTime);
	void Set_OutPutTime(clock_t _OutPutTime);
	void Set_OldTime(clock_t	_OldTime);
};