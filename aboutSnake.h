#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <utility>
#include "aboutFile.h"
#include <random> 
using namespace std;
void createMap(int width, int height);
void showMap();
class snakeBodyNode {
public:
    int x;
    int y;
    snakeBodyNode* next;
    char bodyChar;

    snakeBodyNode();  // 构造函数声明
};

class snakeHead {
public:
    int headX;
    int headY;
    int speed;
    std::string color;
    char headChar;
    int score;
    int foodScore;
    snakeBodyNode* bodyNode;

    // 构造函数
    snakeHead(int x, int y);

    // 成员函数
    void initSnake();
    int move(int xToword, int yToword, int speed);
    void printSnake();
    void speedUp();
    void speedDown();
};
int addFood(int x, int y);
void randomAddFood(int width, int height);
int welcomeToGame();
int gameOver(int how);
void clearMap();
void clearInputBuffer();