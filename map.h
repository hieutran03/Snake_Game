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
	int minN = 0, maxN = X-1;
	while(1){
		x = minN + rand() % (maxN + 1 - minN);
		y = minN + rand() % (maxN + 1 - minN);
		if(graph[x][y] != 'o')
			break;
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
