#pragma once
#include"Define.h"
#include"Object.h"
class GOAL_DAE :public Object
{
private:
	int nMoveX, nMoveY;     // �̵� ��ǥ 
	int nLength;			// ��� ����	
	int nLineX[7];			// ���� ���� x ��ǥ (7��)
	clock_t	MoveTime;		// �̵� �ð� ����
	clock_t	OldTime;	    // ���� �̵� �ð�
	int	nDist;				// �̵� �Ÿ�
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