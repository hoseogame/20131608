#pragma once
#include"Define.h"
class Screen
{
public:
	virtual void InitScreen() = 0;
	virtual	void ReadyScreen(int) = 0;
	virtual	void SuccessScreen() = 0;
	virtual	void FailureScreen() = 0;
	virtual void ResultScreen(int) = 0;
};