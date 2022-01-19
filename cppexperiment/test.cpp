#include <stdio.h>
#include <stdlib.h>
#include "conio.h"
//#include "windows.h"

#define kbUP 72
#define kbLEFT 75
#define kbRIGHT 77
#define kbDOWN 80 

//캐릭터 이동
//1.키보드 입력에 대한 이벤트를 알아야 한다.
//2.원하는 위치로 커서를 이동 시킬 수 있어야 한다.
void gotoXY(int x, int y)
{
	COORD Cursor;
	Cursor.X = x;
	Cursor.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cursor);
}

int main(int argc, char argv[])
{
	char cPosition;
	int iCenterX = 7, iCenterY = 7;
	//Center
	gotoXY(iCenterX, iCenterY);
	printf("*");
	while (1)
	{
		if (kbhit())
		{
			system("cls");
			cPosition = getch();
			switch (cPosition)
			{
			case 'w':
			case kbUP:
				iCenterY--;//up
			case 's':
			case kbDOWN:
				iCenterY++;//down
			case 'a':
			case kbLEFT:
				iCenterX--;//left
			case 'd':
			case kbRIGHT:
				iCenterX++;//right
				break;
			}
			// 맵 크기 설정
			if (iCenterX <= 5)
			{
				iCenterX++;
			}
			if (iCenterX >= 20)
			{
				iCenterX--;
			}
			if (iCenterY <= 5)
			{
				iCenterY++;
			}
			if (iCenterY >= 20)
			{
				iCenterY--;
			}

		}
		gotoXY(iCenterX, iCenterY);
		printf("*");
		Sleep(10);

		if (iCenterX == 7 && iCenterY == 10)
		{
			printf("이벤트 발생1\n");
		}
		if (iCenterX == 10 && iCenterY == 10)
		{
			printf("이벤트 발생3\n");
		}
		if (iCenterX == 20 && iCenterY == 15)
		{
			printf("이벤트 발생2\n");
		}
	}


	return 0;
}