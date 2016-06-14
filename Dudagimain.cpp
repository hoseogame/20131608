#pragma once
#include"Dudagimain.h"
DUDAGI_XY	g_Point[9] = { { 10, 15 },{ 20, 15 },{ 30, 15 },
{ 10, 10 },{ 20, 10 },{ 30, 10 },
{ 10, 5 },{ 20, 5 },{ 30, 5 }
};
DUDAGI_STAGE_INFO g_StageInfo[3] = { { 2, 1000 * 10, 6000, 4000 },{ 5, 1000 * 10, 2000, 2000 },
{ 50, 1000 * 120, 1000, 1000 } };
DUDAGIGAME::DUDAGIGAME()
{
	g_nGameState = INIT;
	g_nIsSuccess = 0;
	g_nStage = -1;
	g_nGrade = 0; // ���� 
	g_nStageCount = 1;
	g_nDudagiCount = 0;
	g_nTotalGrade = 0;
}
void DUDAGIGAME::Init()
{
	int i;

	if (g_nStage == -1) // 1���� �ʱ�ȭ�� �Ǵ� �κп� ���� ó�� ����
	{
		g_nStage = 0;
	}
	g_nDudagiCount = 0; // ���� �δ��� ����	
	g_nGrade = 0;
	// Note: ��ġ �¾�
	g_Mangchi->Init(38, 10);
	for (i = 0; i < 9; i++)
	{
		g_Dudagi[i].Init(g_Point[i].nX, g_Point[i].nY);
		g_Dudagi[i].Set_StayTime(rand() % g_StageInfo[g_nStage].DownLimitTime + 10); // Note: �ּ� 10�� �ȴ�.
		g_Dudagi[i].Set_OldTime(clock());
		g_Dudagi[i].Set_OutPutTime(rand() % g_StageInfo[g_nStage].UpLimitTime + 10); //�ּ� 10�� �ȴ�.
	}
}
void DUDAGIGAME::Update()
{
	int i;
	clock_t CurTime = clock();

	switch (g_nGameState)
	{
	case READY:
		if (CurTime - g_UpdateOldTime > 2000)  // 2��
		{
			g_nGameState = RUNNING;
			g_GameStartTime = CurTime;
		}
		break;
	case RUNNING:
		if ((CurTime - g_GameStartTime) > g_StageInfo[g_nStage].LimitTime)
		{
			g_nGameState = STOP;
			return;
		}
		else {
			// �δ��� ������Ʈ	
			for (i = 0; i < 9; i++)
			{
				switch (g_Dudagi[i].Get_nState())
				{
				case SETUP:
					g_Dudagi[i].Set_OldTime(CurTime);
					g_Dudagi[i].Update((int)g_StageInfo[g_nStage].UpLimitTime, (int)g_StageInfo[g_nStage].DownLimitTime);
					break;
				case UP:
					if (CurTime - g_Dudagi[i].Get_OldTime() > g_Dudagi[i].Get_OutPutTime())
					{
						g_Dudagi[i].Set_OldTime(CurTime);
						g_Dudagi[i].Set_nState(DOWN);
					}
					break;
				case DOWN:
					if (CurTime - g_Dudagi[i].Get_OldTime() > g_Dudagi[i].Get_StayTime())
						g_Dudagi[i].Set_nState(SETUP);
					break;
				}
			}

			// ��ġ ������Ʈ 
			if (g_Mangchi->Get_nIsAttack())
			{
				// �浹 �׽�Ʈ ��ġ�� ���� �ϳ��� �δ����� ���� �� �ֱ⿡ �ϳ��� ������� �浹 üũ�� ���� ���´�.
				for (i = 0; i < 9; i++)
				{
					if (g_Dudagi[i].Get_nState() == UP && i == g_Mangchi->Get_nIndex())
					{
						g_nGrade += 10;
						g_nDudagiCount++;
						g_Dudagi[i].Set_nState(DOWN); // �׾����� �ٿ� ���·� �ٷ� ��ȯ�� �ϵ��� �Ѵ�.															
						break;
					}
				}
				// Note: ��ġ�� ���¸� �������ִ� �κ� ��ġ�� ���� ���� ������ �ð� ���� �ӹ����� �ϱ� ���� �κ�
				if (CurTime - g_Mangchi->Get_StartTime() > g_Mangchi->Get_DelayTime())
				{
					g_Mangchi->Set_nIsAttack(0);
				}
			}
			g_RemainTime = (g_StageInfo[g_nStage].LimitTime - (CurTime - g_GameStartTime)) / 1000; // ���� ���� ���� �ð�
		}
		break;
	case STOP:
		// �����̳� ���и� �Ǵ����־ ����� ���ִ� �κ��� �;� �Ѵ�.
		if (g_nDudagiCount >= g_StageInfo[g_nStage].nCatchDudagi)
		{
			g_UpdateOldTime = CurTime;
			g_nGameState = SUCCESS;
			g_nTotalGrade += g_nGrade;
		}
		else {
			g_nGameState = FAILED;
		}
		break;
	case SUCCESS:
		if (CurTime - g_UpdateOldTime > 3000)
		{
			g_UpdateOldTime = CurTime;
			g_nGrade = 0;
			++g_nStage;
			Init();
			g_nGameState = READY;
		}
		break;
	}
}
void DUDAGIGAME::Render()
{
	int i;
	char string[100];

	ScreenClear();

	switch (g_nGameState)
	{
	case INIT:
		if (g_nStage == 0)
			g_Screen->InitScreen();
		break;

	case READY:
		g_Screen->ReadyScreen(g_nStage);
		break;

	case RUNNING:
		g_Screen->RunningScreen();

		sprintf(string, "��ǥ �δ��� : %d  ���� �δ��� : %d", g_StageInfo[g_nStage].nCatchDudagi, g_nDudagiCount);
		ScreenPrint(2, 1, string);
		sprintf(string, "�������� : %d ���� : %d ���� �ð� : %d ", g_nStage + 1, g_nGrade, g_RemainTime);
		ScreenPrint(2, 2, string);

		for (i = 0; i < 9; i++)
		{
			g_Dudagi[i].Render(g_Dudagi[i].Get_nX(), g_Dudagi[i].Get_nY());
		}

		if (g_Mangchi->Get_nIsAttack())
			g_Mangchi->Render(g_Point[g_Mangchi->Get_nIndex()].nX, g_Point[g_Mangchi->Get_nIndex()].nY);
		else
			g_Mangchi->Render_Stay(g_Mangchi->Get_nMoveX(), g_Mangchi->Get_nMoveY());
		break;

	case SUCCESS:
		g_Screen->SuccessScreen();
		sprintf(string, "%d", g_nStage + 1);
		ScreenPrint(20, 11, string);
		sprintf(string, "%d", g_nDudagiCount);
		ScreenPrint(21, 17, string);
		sprintf(string, "%d", g_nTotalGrade);
		ScreenPrint(14, 19, string);
		break;

	case FAILED:
		g_Screen->FailureScreen();
		sprintf(string, "%d", g_nStage + 1);
		ScreenPrint(16, 11, string);
		break;

	case RESULT:
		g_Screen->ResultScreen(g_nTotalGrade);
		check = false;
		break;
	}
	ScreenFlipping();
}
void DUDAGIGAME::GameMain()
{
	int nKey;
	ScreenInit();
	Init();        // �ʱ�ȭ
	while (check)
	{
		if (_kbhit())
		{
			if (g_nGameState == RESULT)
				break;

			nKey = _getch();
			switch (nKey)
			{
			case ' ':
				if (g_nGameState == INIT && g_nStage == 0)
				{
					g_nGameState = READY;
					g_UpdateOldTime = clock();  // ready�� �����ð� ������ �ֱ� ���� 							
				}
				break;
			case '1':  // ��ġ Ű �Է� 1 ~ 9����
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				if (g_Mangchi->Get_nIsAttack() == 0 && g_nGameState == RUNNING)
				{
					g_Mangchi->Set_nIndex(nKey - '1');
					g_Mangchi->Set_StartTime(clock());
					g_Mangchi->Set_nIsAttack(1);
				}
				break;

			case 'y':
			case 'Y':
				if (g_nGameState == FAILED)
				{
					Init();
					g_nGameState = READY;
					g_nGrade = 0;
					g_UpdateOldTime = clock();
				}
				break;
			case 'n':
			case 'N':
				if (g_nGameState == FAILED)
				{
					g_nGameState = RESULT;
				}
				break;
			}
		}
		Update();    // ������ ����
		Render();    // ȭ�� ���
	}
	ScreenRelease();
	return;
}