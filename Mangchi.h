#pragma once
#include"Object.h"
class MANGCHI:public Object
{
private:
	int	nIsAttack;         // 망치 상태 
	clock_t	StartTime;     // 타격 상태가 시작된 시각
	clock_t	DelayTime;     // 타격 상태의 지연 시각
	int	nIndex;            // 좌표 배열에 접근하기 위한 인덱스
	int	nMoveX, nMoveY;    // 대기 상태일 때 좌표	
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