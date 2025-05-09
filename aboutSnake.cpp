#define  _CRT_SECURE_NO_WARNINGS
#include "aboutSnake.h"
char edge[9] = {
	'+','-','+',
	'|',' ','|',
	'+','-','+'
};
vector<vector<char>> map;
int mapSize[2];
void createMap(int width,int height)
{
	int i, j;
	vector<char> line;
	mapSize[0] = width;
	mapSize[1] = height;
	line.push_back(edge[0]);
	for (i = 0; i < width; i++)
	{
		line.push_back(edge[1]);
	}
	line.push_back(edge[2]);
	map.emplace_back(line);
	
	
	/*for (i = 0; i < width+2; i++)
	{
		cout << map[0][i];
	}*/
	
		
		
		//cout << map[0][0];
	line.clear();


	for (j = 0; j < height; j++) 
	{
		line.push_back(edge[3]);
		for (i = 0; i < width; i++)
		{
			line.push_back(' ');
		}
		line.push_back(edge[5]);
		map.emplace_back(line);
		line.clear();
	}
	line.push_back(edge[6]);
	for (i = 0; i < width; i++)
	{
		line.push_back(edge[7]);
	}
	line.push_back(edge[8]);
	map.emplace_back(line);
	line.clear();
}
void showMap()
{
	int i, j;
	for (i = 0; i < mapSize[1]+2 ; i++)
	{
		for (j = 0; j < mapSize[0]+2 ; j++)
			cout << map[i][j];
		cout << endl;
	}


}