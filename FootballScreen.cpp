#include "FootballScreen.h"
void FBSCREEN::InitScreen()
{
	ScreenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━━┓");
	ScreenPrint(0, 1, "┃                                          ┃");
	ScreenPrint(0, 2, "┃             □━━━□                   ┃");
	ScreenPrint(0, 3, "┃                                          ┃");
	ScreenPrint(0, 4, "┃                        ///.   슛~~~      ┃");
	ScreenPrint(0, 5, "┃                       (^.^)              ┃");
	ScreenPrint(0, 6, "┃                      ┗┫ ┣┓           ┃");
	ScreenPrint(0, 7, "┃                         ┏┛             ┃");
	ScreenPrint(0, 8, "┃                     ⊙  ┛＼             ┃");
	ScreenPrint(0, 9, "┃                                          ┃");
	ScreenPrint(0, 10, "┃                                          ┃");
	ScreenPrint(0, 11, "┃       슛 골인 게임  Go! Go!              ┃");
	ScreenPrint(0, 12, "┃                                          ┃");
	ScreenPrint(0, 13, "┃                                          ┃");
	ScreenPrint(0, 14, "┃       j :왼쪽 l : 오른쪽 k :슛           ┃");
	ScreenPrint(0, 15, "┃                                          ┃");
	ScreenPrint(0, 16, "┃                                          ┃");
	ScreenPrint(0, 17, "┃                                          ┃");
	ScreenPrint(0, 18, "┃        ┗●┛  space 키를 눌러주세요     ┃");
	ScreenPrint(0, 19, "┃                                          ┃");
	ScreenPrint(0, 20, "┃                                          ┃");
	ScreenPrint(0, 21, "┃                                          ┃");
	ScreenPrint(0, 22, "┗━━━━━━━━━━━━━━━━━━━━━┛");
}
void FBSCREEN::ReadyScreen(int g_nStage)
{
	char string[100];

	ScreenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━━┓");
	ScreenPrint(0, 1, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	ScreenPrint(0, 2, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	ScreenPrint(0, 3, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	ScreenPrint(0, 4, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	ScreenPrint(0, 5, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	ScreenPrint(0, 6, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	ScreenPrint(0, 7, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	ScreenPrint(0, 8, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	ScreenPrint(0, 9, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	ScreenPrint(0, 10, "┃■■■■■                    ■■■■■■┃");
	sprintf(string, "┃■■■■■     %d   스테이지   ■■■■■■┃", g_nStage + 1);
	ScreenPrint(0, 11, string);
	ScreenPrint(0, 12, "┃■■■■■                    ■■■■■■┃");
	ScreenPrint(0, 13, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	ScreenPrint(0, 14, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	ScreenPrint(0, 15, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	ScreenPrint(0, 16, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	ScreenPrint(0, 17, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	ScreenPrint(0, 18, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	ScreenPrint(0, 19, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	ScreenPrint(0, 20, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	ScreenPrint(0, 21, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	ScreenPrint(0, 22, "┃■■■■■■■■■■■■■■■■■■■■■┃");
	ScreenPrint(0, 23, "┗━━━━━━━━━━━━━━━━━━━━━┛");
}
void FBSCREEN::BackScreen(int g_nStage,clock_t LimitTime,clock_t g_GameStartTime,int nGoalBall,int g_nBallCount)
{
	char string[100];

	ScreenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━━┓");
	ScreenPrint(0, 1, "┃                                          ┃");
	ScreenPrint(0, 2, "┃                                          ┃");
	ScreenPrint(0, 3, "┃                                          ┃");
	sprintf(string, "┃                                          ┃스테이지: %d", g_nStage + 1);
	ScreenPrint(0, 4, string);
	ScreenPrint(0, 5, "┃                                          ┃");
	sprintf(string, "┣━━━━━━━━━━━━━━━━━━━━━┫제한 시간: %d", LimitTime / 1000);
	ScreenPrint(0, 6, string);
	ScreenPrint(0, 7, "┃                                          ┃");
	sprintf(string, "┃                                          ┃현재 시간: %d", (clock() - g_GameStartTime) / 1000);
	ScreenPrint(0, 8, string);
	ScreenPrint(0, 9, "┃                                          ┃");
	sprintf(string, "┃                                          ┃목표 골인: %d ", nGoalBall);
	ScreenPrint(0, 10, string);
	ScreenPrint(0, 11, "┃                                          ┃");
	sprintf(string, "┃                                          ┃골인 공 개수: %d ", g_nBallCount);
	ScreenPrint(0, 12, string);

	ScreenPrint(0, 13, "┃                                          ┃");
	sprintf(string, "┃                                          ┃");
	ScreenPrint(0, 14, string);
	ScreenPrint(0, 15, "┃                                          ┃");
	sprintf(string, "┃                                          ┃");
	ScreenPrint(0, 16, string);
	ScreenPrint(0, 17, "┃                                          ┃");
	ScreenPrint(0, 18, "┃                                          ┃");
	ScreenPrint(0, 19, "┃                                          ┃");
	ScreenPrint(0, 20, "┃                                          ┃");
	ScreenPrint(0, 21, "┃                                          ┃");
	ScreenPrint(0, 22, "┃                                          ┃");
	ScreenPrint(0, 23, "┗━━━━━━━━━━━━━━━━━━━━━┛");
}
void FBSCREEN::GoalMessage(int nX, int nY)
{
	ScreenPrint(nX, nY, "☆ )) 골인 (( ★");
	ScreenPrint(nX, nY + 1, "＼(^^')/ ＼(\"*')/");
	ScreenPrint(nX, nY + 2, "   ■       ■");
	ScreenPrint(nX, nY + 3, "  ┘┐    ┌└");
}
void FBSCREEN::SuccessScreen()
{
	ScreenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━━┓");
	ScreenPrint(0, 1, "┃                                          ┃");
	ScreenPrint(0, 2, "┃                                          ┃");
	ScreenPrint(0, 3, "┃                                          ┃");
	ScreenPrint(0, 4, "┃                                          ┃");
	ScreenPrint(0, 5, "┃                                          ┃");
	ScreenPrint(0, 6, "┃                ////＼＼                  ┃");
	ScreenPrint(0, 7, "┃               q ∧  ∧ p                 ┃");
	ScreenPrint(0, 8, "┃               (└──┘)                 ┃");
	ScreenPrint(0, 9, "┃             ♬ 미션 성공 ♪              ┃");
	ScreenPrint(0, 10, "┃                                          ┃");
	ScreenPrint(0, 11, "┃                                          ┃");
	ScreenPrint(0, 12, "┃                                          ┃");
	ScreenPrint(0, 13, "┃                                          ┃");
	ScreenPrint(0, 14, "┃                                          ┃");
	ScreenPrint(0, 15, "┃                                          ┃");
	ScreenPrint(0, 16, "┃                                          ┃");
	ScreenPrint(0, 17, "┃                                          ┃");
	ScreenPrint(0, 18, "┃                                          ┃");
	ScreenPrint(0, 19, "┃                                          ┃");
	ScreenPrint(0, 20, "┃                                          ┃");
	ScreenPrint(0, 21, "┃                                          ┃");
	ScreenPrint(0, 22, "┃                                          ┃");
	ScreenPrint(0, 23, "┗━━━━━━━━━━━━━━━━━━━━━┛");
}
void FBSCREEN::FailureScreen()
{
	ScreenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━━┓");
	ScreenPrint(0, 1, "┃                                          ┃");
	ScreenPrint(0, 2, "┃                                          ┃");
	ScreenPrint(0, 3, "┃                                          ┃");
	ScreenPrint(0, 4, "┃                                          ┃");
	ScreenPrint(0, 5, "┃                                          ┃");
	ScreenPrint(0, 6, "┃                                          ┃");
	ScreenPrint(0, 7, "┃                                          ┃");
	ScreenPrint(0, 8, "┃                                          ┃");
	ScreenPrint(0, 9, "┃                                          ┃");
	ScreenPrint(0, 10, "┃                                          ┃");
	ScreenPrint(0, 11, "┃                    미션 실패 !!!!        ┃");
	ScreenPrint(0, 12, "┃                                          ┃");
	ScreenPrint(0, 13, "┃                                          ┃");
	ScreenPrint(0, 14, "┃                 ●┳━┓                 ┃");
	ScreenPrint(0, 15, "┃                   ┛  ┗                 ┃");
	ScreenPrint(0, 16, "┃                  ■■■■                ┃");
	ScreenPrint(0, 17, "┃                                          ┃");
	ScreenPrint(0, 18, "┃        다시 하시겠습니까? (y/n)          ┃");
	ScreenPrint(0, 19, "┃                                          ┃");
	ScreenPrint(0, 20, "┃                                          ┃");
	ScreenPrint(0, 21, "┃                                          ┃");
	ScreenPrint(0, 22, "┗━━━━━━━━━━━━━━━━━━━━━┛");
}
void FBSCREEN::ResultScreen(int g_nStage)
{
	char string[100];
	ScreenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━━┓");
	ScreenPrint(0, 1, "┃                                          ┃");
	ScreenPrint(0, 2, "┃                                          ┃");
	ScreenPrint(0, 3, "┃             □━━━□                   ┃");
	ScreenPrint(0, 4, "┃                                          ┃");
	ScreenPrint(0, 5, "┃                                          ┃");
	ScreenPrint(0, 6, "┃                                          ┃");
	ScreenPrint(0, 7, "┃                                          ┃");
	sprintf(string, "┃      성공한 스테이지 :  %2d               ┃", g_nStage + 1);
	ScreenPrint(0, 8, string);
	ScreenPrint(0, 9, "┃                                          ┃");
	ScreenPrint(0, 10, "┃                                          ┃");
	ScreenPrint(0, 11, "┃   ___▒▒▒___                           ┃");
	ScreenPrint(0, 12, "┃     (*^  ^*)                             ┃");
	ScreenPrint(0, 13, "┃ =====○==○=====                         ┃");
	ScreenPrint(0, 14, "┃                                          ┃");
	ScreenPrint(0, 15, "┃                                          ┃");
	ScreenPrint(0, 16, "┃                                          ┃");
	ScreenPrint(0, 17, "┃                                          ┃");
	ScreenPrint(0, 18, "┃                      ┗●┛              ┃");
	ScreenPrint(0, 19, "┃                                          ┃");
	ScreenPrint(0, 20, "┃                                          ┃");
	ScreenPrint(0, 21, "┃                                          ┃");
	ScreenPrint(0, 22, "┗━━━━━━━━━━━━━━━━━━━━━┛");
}