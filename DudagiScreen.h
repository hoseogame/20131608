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
	// Note: 실패 했을 경우에 출력되면서 다시 할것인지를 묻는 화면이다.
	void ResultScreen(int);
};