#ifndef map_H
#define map_H
#include"common.h"
#include"math.h"
// map

void initMap(char graph[][Y]){
	for(int j = 0; j < Y; j++)
		for(int i = 0; i < X; i++)
			graph[i][j] = '.';
}

void createApple(char graph[][Y]){
	int x, y;
	int min_x = 0, max_x = X-1;
	int min_y = 0, max_y = Y-1;
	int seed = 0;
	while(1){
		x = min_x + rand() % (max_x + 1 - min_x);
		y = min_y + rand() % (max_y + 1 - min_y);
		if(graph[x][y] == '.')
		{
			seed++;
			srand(seed);
			break;
		}
	
	}
 	graph[x][y] = 'x';
}
void showMap(char graph[][Y]){
	for(int j = 0; j < Y; j++)
	{
		for(int i = 0; i < X; i++)
			cout << graph[i][j] << " ";
		cout << endl;
	}
}


#endif
