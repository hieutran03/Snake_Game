#include "common.h"
#include "snake.h"
#include "coordinate.h"
#include "map.h"
using namespace std;



typedef coordinate coor;


int main(){
	system("color 60");
	
	char graph[X][Y];
	initMap(graph);
	
	snake sna;
	initSnake(graph, sna);
	
	createApple(graph);
	
	showMap(graph);
	cout << endl;
	
	int point = 0;
	cout << "YOUR POINT: " << point << endl;
	
	int life = 3;
	cout << "YOUR LIFE: " << life << endl;
	
	char option;
	do{
		option = getch();
		system("cls");
		
		if(!snakeMove(graph,sna,option, point))
		{
			showMap(graph);
			cout << "YOUR POINT: " << point << endl;
			life--;
			cout << "CANT'MOVE" << endl;
			cout << "YOUR LIFE: "  << life;
		}else{
			showMap(graph);
			cout << "YOUR POINT: " << point << endl;
			cout << "YOUR LIFE: "  << life;
		}
		if(point == X*Y-3){
			cout << "YOU WIN";
			return 0;
		}
		cout << endl;
	}while(option != 'x'&& life > 0);
	cout << "<END GAME>" << endl;	
	system("pause");
}
