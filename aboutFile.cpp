#define  _CRT_SECURE_NO_WARNINGS
#include "aboutFile.h"



int getHighestScore()
{
	ifstream inFile("score.txt");
    string score;
    if (inFile.is_open()) {
        getline(inFile, score);
        inFile.close();
        return stoi(score);
    }
    else {
        cout << "无法打开文件";
        return -1;
    }
}
void writeHighestScore(int score)
{
    ofstream outFile("score.txt");  // 创建并打开文件

    if (outFile.is_open()) {
        outFile << score;
        outFile.close();  // 关闭文件
    }
}
