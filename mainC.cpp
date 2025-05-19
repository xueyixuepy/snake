#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include "aboutSnake.h"
#include "aboutFile.h"
#include <windows.h> 
#include <cstdlib>  

void clearConsole() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}
using namespace std;
void keyToMove(char key,int* moveTo)
{
	
	switch (key) {
	case 'w':if (moveTo[1] != 1)moveTo[0] = 0, moveTo[1] = -1; break;
	case 's':
		if ( moveTo[1] != -1)
		moveTo[0] = 0, moveTo[1] = 1; 
		break;
	case 'a':	if (moveTo[0] != 1)moveTo[0] = -1, moveTo[1] = 0; break;
	case 'd':if (moveTo[0] != -1)moveTo[0] = 1, moveTo[1] = 0; break;
	}
}

int main()
{
	int moveTo[2] = { 0 };
	createMap(40, 20);
	bool isEat = 0;
	char key;
	snakeHead xiaoshe(1, 1);
	bool firstKey = 1;
	if (welcomeToGame())
		xiaoshe.initSnake();
	else
		goto END;
	//addFood(8, 10);
	//addFood(5, 10);
	//addFood(6, 10);
	//addFood(6, 8);
	BEGIN:
	while (true)
	{
		if (_kbhit()) {

			key = _getch();
			if (firstKey)
			{
				if (key == 'a')
					key = ' ';
				else if (key == 'w' || key == 's' || key == 'd')
					firstKey = 0;
			}
			if (key == '=') {
				xiaoshe.speedUp();
			}
			else if (key == '-')
			{
				xiaoshe.speedDown();
			}
			keyToMove(key, moveTo);
			if (key == 'q') break; // 按 q 退出
		}
		//如果小蛇撞死了
		if (xiaoshe.move(moveTo[0], moveTo[1], 1))
		{
			xiaoshe.printSnake();
			showMap();
			std::cout << "得分:" << xiaoshe.score << "          " << "相对速度:" << 1.0 / xiaoshe.speed * 1000;
			cout << endl;
			Sleep(1000);
			//更新最高分
			if (xiaoshe.score > getHighestScore())
			{
				writeHighestScore(xiaoshe.score);
			}
			if (gameOver( getHighestScore() - xiaoshe.score))
			{
				clearMap();
				xiaoshe.initSnake();
				moveTo[0] = 0;
				moveTo[1] = 0;
				firstKey = 1;
				goto BEGIN;
			}
			else
			{
				goto END;
			}
			break;
		}
		xiaoshe.printSnake();

		showMap();
		std::cout <<"得分:" <<xiaoshe.score<<"          "<<"相对速度:"<<1.0/xiaoshe.speed * 1000;
		Sleep(xiaoshe.speed); 
		clearConsole();
	}
	END:
	return 0;
}