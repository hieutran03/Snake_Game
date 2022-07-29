#include "common.h"
#include "snake.h"
#include "coordinate.h"
#include "map.h"
using namespace std;

#define DELAY 20

typedef coordinate coor;


int main() {
	system("color 60");

	int point = 0;
	cout << "YOUR POINT: " << point << endl;

	int life = 3;
	cout << "YOUR LIFE: " << life << endl;

	char graph[X][Y];
	initMap(graph);

	snake sna;
	initSnake(graph, sna);

	createApple(graph);

	showMap(graph);
	cout << endl;



	bool isVictory = 0;
	char option = 1;
	do {

		if (_kbhit())
			option = _getch();
		system("cls");
		cout << "YOUR POINT: " << point << endl;
		cout << "YOUR LIFE: " << life << endl;
		int check_snake_move = snakeMove(graph, sna, option, point);
		showMap(graph);

		wait(DELAY);
		if (check_snake_move == 0)
		{
			life--;
		}
		if (point == X * Y - 3)
		{
			isVictory = 1;
			break;
		}
		cout << endl;
	} while (option != 'x' && life > 0);

	system("cls");
	cout << "YOUR POINT: " << point << endl;
	cout << "YOUR LIFE: " << life << endl;
	showMap(graph);

	if (isVictory) {
		cout << "YOU WIN!" << endl;
	}
	else
		cout << "YOU LOSE" << endl;
	cout << "<END GAME>" << endl;
	system("pause");
}
