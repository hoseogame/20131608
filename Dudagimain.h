#pragma once
#include"Scene.h"
#include"Mangchi.h"
#include"DudagiScreen.h"
#include"Dudagi.h"
#include"Object.h"
typedef struct DUDAGI_STAGE_INFO
{
	int nCatchDudagi;
	clock_t LimitTime;
	clock_t UpLimitTime;
	clock_t DownLimitTime;
} DUDAGI_STAGE_INFO;
typedef struct DUDAGI_XY
{
	int nX, nY;
} DUDAGI_XY;
class DUDAGIGAME :public Scene
{
private:
	MANGCHI*	g_Mangchi = new MANGCHI;
	DUSCREEN *g_Screen=new DUSCREEN;
	DUDAGI	*g_Dudagi = new DUDAGI[9];
	GAME_STATE	g_nGameState;
	int         g_nIsSuccess;
	int			g_nStage;
	int			g_nGrade; // Á¡¼ö 
	int			g_nStageCount;
	int			g_nDudagiCount;
	clock_t		g_GameStartTime, g_UpdateOldTime, g_RemainTime;
	int			g_nTotalGrade; // ÃÑÁ¡
	bool check = true;
public:
	DUDAGIGAME();
	void Init();
	void Update();
	void Render();
	void GameMain();
};