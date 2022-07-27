#include "common.h"
#include "snake.h"
#include "coordinate.h"
#include "map.h"
using namespace std;



typedef coordinate coor;


int main(){
	system("color 70");
	char graph[X][Y];
	initMap(graph);
	snake sna;
	initSnake(graph, sna);
	createApple(graph);
	showMap(graph);
	cout << endl;
	char option;
	int life = 3;
	do{
		option = getch();
		system("cls");
		
		if(!snakeMove(graph,sna,option))
		{
			showMap(graph);
			life--;
			cout << "CANT'MOVE" << endl;
			cout << "YOUR LIFE: " << life;
		}else{
			showMap(graph);
		}
		cout << endl;
	}while(option != 'x'&& life > 0);
	cout << "<END GAME>";
}
