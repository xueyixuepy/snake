#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include "aboutSnake.h"
#include <windows.h> 
using namespace std;
void keyToMove(char key,int* moveTo)
{
	
	switch (key) {
	case 'w':moveTo[0] = 0, moveTo[1] = -1; break;
	case 's':moveTo[0] = 0, moveTo[1] = 1; break;
	case 'a':moveTo[0] = -1, moveTo[1] = 0; break;
	case 'd':moveTo[0] = 1, moveTo[1] = 0; break;
	}
}
int main()
{
	int moveTo[2] = { 0 };
	createMap(40, 20);
	snakeHead xiaoshe(1, 1);
	int speed = 1;
	bool isEat = 0;
	addFood(8, 10);
	addFood(5, 10);
	while (true)
	{
		if (_kbhit()) {
			char key = _getch();
			keyToMove(key, moveTo);
			if (key == 'q') break; // °´ q ÍË³ö
		}
		xiaoshe.move(moveTo[0], moveTo[1], 1);
		xiaoshe.printSnake();

		showMap();
		Sleep(1000); 
	}
	return 0;
}