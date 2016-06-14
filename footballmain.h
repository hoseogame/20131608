#pragma once
#include"Scene.h"
#include"player.h"
#include"ball.h"
#include"goaldae.h"
#include"GameScreen.h"
#include"FootballScreen.h"
typedef struct FOOTBALL_EFFECT
{
	clock_t StratTime; // 효과 발생 시각
	clock_t StayTime;  // 효과 지속 시간	
} FOOTBALL_EFFECT;
typedef struct FOOTBALL_STAGE_INFO
{
	int nGoalBall;			// 골인해야 할 볼의 개수 
	clock_t LimitTime;      // 제한 시간 
	int nGoalDaeLength;		// 골대 길이 
	int nGoalDaeX;			// 골대 이동 X 좌표
	int nGoalDaeY;			// 골대 이동 Y 좌표 
	clock_t MoveTime;		// 골대 이동 시간 간격
	int nDist;				// 골대 이동 거리
} FOOTBALL_STAGE_INFO;

class FOOTBALL:public Scene
{
private:
	GOAL_DAE g_sGoalDae;
	BALL *g_sBall =new BALL;
	PLAYER *g_sPlayer=new PLAYER;
	FOOTBALL_EFFECT g_sEffect;
	FBSCREEN *g_Screen=new FBSCREEN;
	int g_nGoal;
	int	g_nBallCount;
	int g_nGoalBallCount;
	int g_nStage;
	int	g_nIsGoal;
	clock_t g_LimitTime;
	clock_t g_GameStartTime;
	clock_t g_UpdateOldTime;
	GAME_STATE g_GameState;
	bool check = true;
public:
	FOOTBALL();
	void Init();
	void Update();
	void Render();
	void GameMain();
};
