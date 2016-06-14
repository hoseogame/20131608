#include"player.h"
PLAYER::PLAYER()
{
}
PLAYER::~PLAYER()
{
}
void PLAYER::Set_nMoveX(int _nMoveX) { nMoveX = _nMoveX; }
void PLAYER::Set_nMoveY(int _nMoveY) { nMoveY = _nMoveY; }
int PLAYER::Get_nMoveX() { return nMoveX; }
int PLAYER::Get_nMoveY() { return nMoveY; }
void PLAYER::Init(int _x, int _y)
{
	nCenterX = 4;
	nCenterY = 0;
	nMoveX = 20;
	nMoveY = 22;
	nX = nMoveX - nCenterX;
	nLength = strlen(strPlayer);
}
void PLAYER::Update(int _x, int _y)
{
	nMoveX = _x;
	nMoveY = _y;
}
void PLAYER::Render(int _x, int _y)
{
	char string[100] = { 0, };
	if (_x < 2)  //  ���� Ŭ���� ó��
		ScreenPrint(2, _y, &strPlayer[(_x - 2)*-1]);	 // ��ǥ�� �迭 �ε��� 
	else if (nMoveX + (nLength - nCenterX + 1) > 43) // ������ Ŭ���� ó��
	{
		strncat(string, strPlayer, nLength - ((nMoveX + nCenterX + 1) - 43));
		ScreenPrint(_x, _y, string);
	}
	else { // 1 �÷��� �̵�
		ScreenPrint(_x, _y, strPlayer);
	}
}
void PLAYER::Set_nCenterX(int _nCenterX) { nCenterX = _nCenterX; }
void PLAYER::Set_nCenterY(int _nCenterY) { nCenterY = _nCenterY; }
int PLAYER::Get_nCenterX() { return nCenterX; }
int PLAYER::Get_nCenterY() { return nCenterY; }
void PLAYER::Set_nLength(int _nLength) { nLength = _nLength; };
int PLAYER::Get_nLength() { return nLength; };
void PLAYER::Set_nX(int _nX) { nX = _nX; }
void PLAYER::Set_nY(int _nY) { nY = _nY; }
int PLAYER::Get_nX() { return nX; }
int PLAYER::Get_nY() { return nY; }