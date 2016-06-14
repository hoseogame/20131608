#pragma once
#include"Object.h"
class MANGCHI:public Object
{
private:
	int	nIsAttack;         // ��ġ ���� 
	clock_t	StartTime;     // Ÿ�� ���°� ���۵� �ð�
	clock_t	DelayTime;     // Ÿ�� ������ ���� �ð�
	int	nIndex;            // ��ǥ �迭�� �����ϱ� ���� �ε���
	int	nMoveX, nMoveY;    // ��� ������ �� ��ǥ	
public:
	void Render(int, int);
	void Render_Stay(int, int);
	void Init(int, int);
	void Update(int, int);

	int Get_nIsAttack();
	int Get_StartTime();
	int Get_DelayTime();
	int Get_nIndex();
	int Get_nMoveX();
	int Get_nMoveY();
	void Set_nIsAttack(int _nIsAttack);
	void Set_nIndex(int _nIndex);
	void Set_nMoveX(int _nMoveX);
	void Set_nMoveY(int _nMoveY);
	void Set_StartTime(clock_t _g_GameStartTime);
	void Set_DelayTime(clock_t num);
};