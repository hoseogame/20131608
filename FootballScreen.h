#pragma once
#include"GameScreen.h"
class FBSCREEN:public Screen
{
public:
	void InitScreen();
	void ReadyScreen(int);
	void BackScreen(int, clock_t, clock_t, int, int);
	void GoalMessage(int, int);
	void SuccessScreen();
	void FailureScreen();
	// Note: ���� ���� ��쿡 ��µǸ鼭 �ٽ� �Ұ������� ���� ȭ���̴�.
	void ResultScreen(int);
};