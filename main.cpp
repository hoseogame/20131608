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
		std::cout << "������ ������ �����Ͻÿ�." << std::endl;
		std::cout << "1.ǲ������ 2.�δ������� (�����ϰ� ������ �ƹ�Ű�� �Է��Ͻÿ�.)" << std::endl;
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