#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <utility>
using namespace std;
void createMap(int width, int height);
void showMap();
class snakeBodyNode {
public:
    int x;
    int y;
    snakeBodyNode* next;
    char bodyChar;

    snakeBodyNode();  // ���캯������
};

class snakeHead {
public:
    int headX;
    int headY;
    int speed;
    std::string color;
    char headChar;
    snakeBodyNode* bodyNode;

    // ���캯��
    snakeHead(int x, int y);

    // ��Ա����
    void initSnake();
    void move(int xToword, int yToword, int speed);
    void printSnake();
};
void addFood(int x, int y);