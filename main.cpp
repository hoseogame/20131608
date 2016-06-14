#pragma once
#include"Define.h"
#include"Scene.h"
#include"footballmain.h"
#include"Dudagimain.h"
void main(void)
{
	int select = 0;
	bool check = true;
	Scene *scene;
	while (check)
	{
		system("cls");
		std::cout << "실행할 게임을 선택하시오." << std::endl;
		std::cout << "1.풋볼게임 2.두더지게임 (종료하고 싶으면 아무키나 입력하시오.)" << std::endl;
		std::cin >> select;
		switch (select)
		{
		case 1:
			scene = new FOOTBALL;
			break;
		case 2:
			scene = new DUDAGIGAME;
			break;
		default:
			exit(0);
		}
		scene->GameMain();
	}
}