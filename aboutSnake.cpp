#define  _CRT_SECURE_NO_WARNINGS
#include "aboutSnake.h"
char edge[9] = {
	'+','-','+',
	'|',' ','|',
	'+','-','+'
};
//左是纵坐标，右是横坐标
vector<vector<char>> gameMap;
int gameMapSize[2];
map<string, string> snakeColor = {
		{"black",      "\033[30m"},
		{"red",        "\033[31m"},
		{"green",      "\033[32m"},
		{"yellow",     "\033[33m"},
		{"blue",       "\033[34m"},
		{"magenta",    "\033[35m"},
		{"cyan",       "\033[36m"},
		{"white",      "\033[37m"},
};
snakeBodyNode::snakeBodyNode()
	: next(nullptr), bodyChar('*') {}
snakeHead::snakeHead(int x, int y)
	: headX(x), headY(y), speed(1),
	color("green"), bodyNode(nullptr), headChar('#') {}

// 初始化蛇身（原函数为空）
void snakeHead::initSnake() {
	// 可在此添加初始化逻辑
}

// 移动函数实现
void snakeHead::move(int xToword, int yToword, int speed) {
	bool isEat = 0;
	int temX = headX;
	int temY = headY;
	headX += xToword * speed;
	headY += yToword * speed;
	if (gameMap[headY][headX] == '$')
		isEat = 1;
	if (bodyNode != nullptr) {
		snakeBodyNode* linkBody = bodyNode;
		swap(linkBody->x, temX);
		swap(linkBody->y, temY);
		while (linkBody->next != nullptr) {
			swap(linkBody->next->x, temX);
			swap(linkBody->next->y, temY);
			linkBody = linkBody->next;
		}
		if (isEat) {
			linkBody->next = new snakeBodyNode;
			linkBody->next->x = linkBody->x - xToword;
			linkBody->next->y = linkBody->y - yToword;
		}
	}
	else {
		if (isEat) {
			bodyNode = new snakeBodyNode;
			bodyNode->x = headX - xToword;
			bodyNode->y = headY - yToword; 
		}
	}
}

// 打印蛇到地图
void snakeHead::printSnake() {
	for (int i = 1; i < gameMapSize[1]+1; i++) {
		for (int j = 1; j < gameMapSize[0] + 1; j++) {
			if (gameMap[i][j] == headChar || gameMap[i][j] == '*') {
				gameMap[i][j] = ' ';
			}
		}
	}


	// 更新头部和身体位置
	gameMap[headY][headX] = headChar;
	snakeBodyNode* linkBody = bodyNode;
	while (linkBody != nullptr) {
		gameMap[linkBody->y][linkBody->x] = linkBody->bodyChar;
		linkBody = linkBody->next;
	}
}



void createMap(int width,int height)
{
	int i, j;
	vector<char> line;
	gameMapSize[0] = width;
	gameMapSize[1] = height;
	line.push_back(edge[0]);
	for (i = 0; i < width; i++)
	{
		line.push_back(edge[1]);
	}
	line.push_back(edge[2]);
	gameMap.emplace_back(line);
	
	line.clear();


	for (j = 0; j < height; j++) 
	{
		line.push_back(edge[3]);
		for (i = 0; i < width; i++)
		{
			line.push_back(' ');
		}
		line.push_back(edge[5]);
		gameMap.emplace_back(line);
		line.clear();
	}
	line.push_back(edge[6]);
	for (i = 0; i < width; i++)
	{
		line.push_back(edge[7]);
	}
	line.push_back(edge[8]);
	gameMap.emplace_back(line);
	line.clear();
}
void showMap()
{
	int i, j;
	for (i = 0; i < gameMapSize[1]+2 ; i++)
	{
		for (j = 0; j < gameMapSize[0]+2 ; j++)
			cout << gameMap[i][j];
		cout << endl;
	}
}

void addFood(int x, int y)
{
	gameMap[y][x] = '$';
}
