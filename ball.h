#pragma once
#include"Object.h"
class BALL :public Object
{
private:
	bool nIsReady;        // �غ� ����(1), ������(0)
	int nMoveX, nMoveY;  // �̵� ��ǥ
	clock_t MoveTime;    // �̵� �ð� ����
	clock_t OldTime;     // ���� �̵� �ð�
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