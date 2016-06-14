#pragma once
#include"Scene.h"
#include"player.h"
#include"ball.h"
#include"goaldae.h"
#include"GameScreen.h"
#include"FootballScreen.h"
typedef struct FOOTBALL_EFFECT
{
	clock_t StratTime; // ȿ�� �߻� �ð�
	clock_t StayTime;  // ȿ�� ���� �ð�	
} FOOTBALL_EFFECT;
typedef struct FOOTBALL_STAGE_INFO
{
	int nGoalBall;			// �����ؾ� �� ���� ���� 
	clock_t LimitTime;      // ���� �ð� 
	int nGoalDaeLength;		// ��� ���� 
	int nGoalDaeX;			// ��� �̵� X ��ǥ
	int nGoalDaeY;			// ��� �̵� Y ��ǥ 
	clock_t MoveTime;		// ��� �̵� �ð� ����
	int nDist;				// ��� �̵� �Ÿ�
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
