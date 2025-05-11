#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include "aboutSnake.h"
#include <windows.h> 
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
	snakeHead xiaoshe(1, 1);
	bool isEat = 0;
	addFood(8, 10);
	addFood(5, 10);
	addFood(6, 10);
	addFood(6, 8);
	while (true)
	{
		if (_kbhit()) {
			char key = _getch();
			if (key == '=') {
				xiaoshe.speedUp();
			}
			else if (key == '-')
			{
				xiaoshe.speedDown();
			}
			keyToMove(key, moveTo);
			if (key == 'q') break; // °´ q ÍË³ö
		}

		if (xiaoshe.move(moveTo[0], moveTo[1], 1))
		{
			xiaoshe.printSnake();
			showMap();
			cout << xiaoshe.score;
			break;
		}
		xiaoshe.printSnake();

		showMap();
		cout << xiaoshe.score;
		Sleep(xiaoshe.speed); 
	}
	return 0;
}