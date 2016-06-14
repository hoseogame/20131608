#pragma once
#include"Define.h"
class Object
{
public:
	virtual void Init(int x,int y) = 0;
	virtual void Update(int x,int y) = 0;
	virtual void Render(int x,int y) = 0;
};