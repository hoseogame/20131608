void ScreenInit();
void ScreenFlipping();
void ScreenClear();
void ScreenRelease();
void ScreenPrint( int x, int y, char *string );
void SetColor( unsigned short color );
static int g_nScreenIndex;
static HANDLE g_hScreen[2];
