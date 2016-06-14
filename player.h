#pragma once
#include"Object.h"
class PLAYER :public Object
{
private:
	int nCenterX, nCenterY;
	int nMoveX, nMoveY;
	int nX, nY;
	int nLength;
	char strPlayer[11] = "¦±¦¬¡Ü¦¬¦°";
public:
	PLAYER();
	~PLAYER();
	void Init(int,int);
	void Update(int, int);
	void Render(int,int);


	void Set_nMoveX(int);
	void Set_nMoveY(int);
	int Get_nMoveX();
	int Get_nMoveY();
	void Set_nCenterX(int);
	void Set_nCenterY(int);
	int Get_nCenterX();
	int Get_nCenterY();
	void Set_nLength(int);
	int Get_nLength();
	void Set_nX(int);
	void Set_nY(int);
	int Get_nX();
	int Get_nY();

};