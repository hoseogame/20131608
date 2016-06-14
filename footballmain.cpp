#include"footballmain.h"
FOOTBALL_STAGE_INFO g_sStageInfo[2] = { { 3, 1000 * 20, 1, 20, 3, 300, 1 },{ 10, 1000 * 30, 2, 20, 5, 300, 1 } };


FOOTBALL::FOOTBALL()
{
	g_nGoal = 0;
	g_nBallCount = 0;
	g_nGoalBallCount = 0;
	g_nStage = -1;
	g_nIsGoal = 0;
	g_LimitTime = 0;
	g_GameStartTime = 0;
	g_UpdateOldTime = 0;
	g_GameState = INIT;
}
void FOOTBALL::Init()
{
	int nLength, i;

	if (g_nStage == -1)
	{
		g_nStage = 0;
	}

	g_LimitTime = g_sStageInfo[g_nStage].LimitTime;  // ���� �ð� ����
	g_nGoalBallCount = g_sStageInfo[g_nStage].nGoalBall; // ��ǥ ���� ����
	g_sPlayer->Init(0, 0);
	// ���� �ʱ�ȭ
	g_sBall->Init(g_sPlayer->Get_nMoveX(), g_sPlayer->Get_nMoveY() - 1);

	// ��� �ʱ�ȭ
	g_sGoalDae.Init(g_sStageInfo[g_nStage].nGoalDaeX, g_sStageInfo[g_nStage].nGoalDaeY, g_sStageInfo[g_nStage].nGoalDaeLength, g_sStageInfo[g_nStage].MoveTime, g_sStageInfo[g_nStage].nDist);
	// ȿ�� 
	g_sEffect.StayTime = 2000; // 2�� ����
	g_nGoal = 0;      // �������� �Ϸ� ����
	g_UpdateOldTime = clock();
	g_nBallCount = 0;  // ������ ���� ����
}
void FOOTBALL::Update()
{
	clock_t CurTime = clock();
	int nLength = g_sGoalDae.Get_nLength() * 2 + 1; // Note: �迭�� �ִ� ����
	int i;

	switch (g_GameState)
	{
	case READY:
		if (CurTime - g_UpdateOldTime > 2000)  // 2��
		{
			g_GameState = RUNNING;
			g_GameStartTime = CurTime;
		}
		break;
	case RUNNING:
		if (CurTime - g_GameStartTime > g_LimitTime) // Note: ���� �ð�
		{
			g_GameState = STOP;
			return;
		}
		else {
			// Note: ���
			g_sGoalDae.Update(CurTime, nLength);

			if (g_sBall->Get_nIsReady() == false) // �̵� ���� �� 
			{	// �̵� �ð� ���ݿ� ���� �̵�
				if ((CurTime - g_sBall->Get_OldTime()) > g_sBall->Get_MoveTime())
				{
					if (g_sBall->Get_nMoveY() - 1 > 0)
					{
						g_sBall->Update(g_sBall->Get_nMoveX(), g_sBall->Get_nMoveY());
						g_sBall->Set_OldTime(CurTime); // ���� �̵� �ð��� ���ϱ� ���� ���� �ð��� ���� �ð� ������ ����
						// ��� ���� �浹
						if (g_sBall->Get_nMoveX() >= g_sGoalDae.Get_nLineX(0) && g_sBall->Get_nMoveX() + 1 <= g_sGoalDae.Get_nLineX(nLength - 1) + 1)
						{
							if (g_sBall->Get_nMoveY() <= g_sGoalDae.Get_nMoveY())
							{   // �� �ʱ�ȭ
								g_sBall->Init(g_sPlayer->Get_nMoveX(), g_sPlayer->Get_nMoveY() - 1);
								g_nBallCount++;  // ������ ���� ����										

								if (g_nBallCount == g_nGoalBallCount) // ���� ��ǥ ������ ������ ������ SUCCESS
								{
									g_GameState = STOP;
									g_nGoal = 1;
									return;
								}

								// ȿ�� ���
								if (g_nIsGoal == 0)
								{
									g_nIsGoal = 1;
									g_sEffect.StratTime = CurTime;
								}
							}
							// ��� �浹 
						}
						else if ((g_sBall->Get_nMoveX() >= g_sGoalDae.Get_nLineX(0) - 2 && g_sBall->Get_nMoveX() <= g_sGoalDae.Get_nLineX(0) - 1) ||
							(g_sBall->Get_nMoveX() + 1 >= g_sGoalDae.Get_nLineX(0) - 2 && g_sBall->Get_nMoveX() + 1 <= g_sGoalDae.Get_nLineX(0) - 1) ||
							(g_sBall->Get_nMoveX() >= g_sGoalDae.Get_nLineX(nLength - 1) + 2 && g_sBall->Get_nMoveX() <= g_sGoalDae.Get_nLineX(nLength - 1) + 3) ||
							(g_sBall->Get_nMoveX() + 1 >= g_sGoalDae.Get_nLineX(nLength - 1) + 2 && g_sBall->Get_nMoveX() + 1 <= g_sGoalDae.Get_nLineX(nLength - 1) + 3))
						{
							if (g_sBall->Get_nMoveY() <= g_sGoalDae.Get_nMoveY())
							{   // �� �ʱ�ȭ
								g_sBall->Init(g_sPlayer->Get_nMoveX(), g_sPlayer->Get_nMoveY() - 1);
							}
						}
					}
					else { // �� �ʱ�ȭ
						g_sBall->Init(g_sPlayer->Get_nMoveX(), g_sPlayer->Get_nMoveY() - 1);
					}
				}
			}
			else {
				g_sBall->Set_nMoveX(g_sPlayer->Get_nMoveX());
			}

			// ȿ�� 
			if (g_nIsGoal == 1)
			{
				if (CurTime - g_sEffect.StratTime > g_sEffect.StayTime)
					g_nIsGoal = 0;
			}
		}
		break;
	case STOP:
		if (g_nGoal == 1)
		{
			g_GameState = SUCCESS;
			g_UpdateOldTime = CurTime;
		}
		else {
			g_GameState = FAILED;
		}
		break;
	case SUCCESS:
		if (CurTime - g_UpdateOldTime > 3000)
		{
			g_UpdateOldTime = CurTime;
			++g_nStage;
			Init();
			if (g_nStage < 2)
			{
				g_GameState = READY;
			}
			else
			{
				--g_nStage;
				g_GameState = RESULT;
			}
		}
		break;
	}
}
void FOOTBALL::Render()
{
	char string[100] = { 0, };
	int nLength = g_sGoalDae.Get_nLength() * 2 + 1;
	ScreenClear();
	switch (g_GameState)
	{
	case INIT:
		if (g_nStage == 0)
			g_Screen->InitScreen();
		break;
	case READY:
		g_Screen->ReadyScreen(g_nStage);
		break;
	case RUNNING:
		g_Screen->BackScreen(g_nStage, g_sStageInfo[g_nStage].LimitTime, g_GameStartTime, g_sStageInfo[g_nStage].nGoalBall, g_nBallCount);
		g_sPlayer->Render(g_sPlayer->Get_nX(), g_sPlayer->Get_nMoveY());
		g_sGoalDae.Render(nLength);
		// Note: ȿ�� ���  	
		if (g_nIsGoal == 1)
		{
			g_Screen->GoalMessage(10, 10);
		}
		g_sBall->Render(g_sBall->Get_nMoveX(), g_sBall->Get_nMoveY());
		break;
	case SUCCESS:
		g_Screen->SuccessScreen();
		break;
	case FAILED:
		g_Screen->FailureScreen();
		break;
	case RESULT:
		g_Screen->ResultScreen(g_nStage);
		check = false;
		break;
	}

	// Note: ������ �� 
	ScreenFlipping();
}
void FOOTBALL::GameMain()
{
	int nKey, nRemain;
	ScreenInit();
	Init();        // �ʱ�ȭ
	while (check)
	{
		if (_kbhit())
		{
			nKey = _getch();
			switch (nKey)
			{
			case 'j':
				if (g_sPlayer->Get_nMoveX() > 2) // ���� �浹 ��� ��ǥ üũ
				{
					g_sPlayer->Update(g_sPlayer->Get_nMoveX() - 1, g_sPlayer->Get_nMoveY());
					nRemain = g_sPlayer->Get_nLength() - g_sPlayer->Get_nCenterX() + 1; // ��ü ���� - ( �߽� ��ǥ + 1 )�� ���� ����
					// Note: 2�÷��� �̵��ϱ� ���� �κ� ( ���� ��ģ ��� ) 
					if (g_sPlayer->Get_nMoveX() - g_sPlayer->Get_nCenterX() < 2 || g_sPlayer->Get_nMoveX() + nRemain > 43)
						g_sPlayer->Update(g_sPlayer->Get_nMoveX() - 1, g_sPlayer->Get_nMoveY());
					g_sPlayer->Set_nX(g_sPlayer->Get_nMoveX() - g_sPlayer->Get_nCenterX());
				}
				break;
			case 'l':
				if (g_sPlayer->Get_nMoveX() + 1 < 43) // ������ �浹 ��� ��ǥ üũ
				{
					g_sPlayer->Update(g_sPlayer->Get_nMoveX() + 1, g_sPlayer->Get_nMoveY());
					nRemain = g_sPlayer->Get_nLength() - g_sPlayer->Get_nCenterX() + 1; // ��ü ���� - ( �߽� ��ǥ + 1 )�� ���� ����
					// Note: 2�÷��� �̵��ϱ� ���� �κ� ( ���� ��ģ ��� )
					if (g_sPlayer->Get_nMoveX() + nRemain > 43 || (g_sPlayer->Get_nMoveX() - g_sPlayer->Get_nCenterX() < 2))
						g_sPlayer->Update(g_sPlayer->Get_nMoveX() + 1, g_sPlayer->Get_nMoveY());

					g_sPlayer->Set_nX(g_sPlayer->Get_nMoveX() - g_sPlayer->Get_nCenterX());
				}
				break;
			case 'k':
				if (g_sBall->Get_nIsReady() && g_GameState == RUNNING)
				{
					g_sBall->Update(g_sPlayer->Get_nMoveX(), g_sPlayer->Get_nMoveY()); 
					g_sBall->Set_OldTime(clock());
					g_sBall->Set_nIsReady(false);
				}
				break;

			case 'y':
			case 'Y':
				if (g_GameState == FAILED)
				{
					Init();
					g_GameState = READY;
				}
				break;
			case 'n':
			case 'N':
				if (g_GameState == FAILED)
				{
					g_GameState = RESULT;
				}
				break;

			case ' ':
				if (g_GameState == INIT && g_nStage == 0)
				{
					g_GameState = READY;
					g_UpdateOldTime = clock();  // ready�� �����ð� ������ �ֱ� ���� 							
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