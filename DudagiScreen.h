#pragma once
#include"GameScreen.h"
class DUSCREEN:public Screen
{
public:
	void InitScreen();
	void ReadyScreen(int);
	void SuccessScreen();
	void RunningScreen();
	void FailureScreen();
	// Note: ���� ���� ��쿡 ��µǸ鼭 �ٽ� �Ұ������� ���� ȭ���̴�.
	void ResultScreen(int);
};