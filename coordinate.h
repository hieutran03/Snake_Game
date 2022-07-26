#ifndef coordinate_H
#define coordinate_H
#include"common.h"

//coordinate

struct coordinate{
	int x, y;
	void set(int x, int y){
		this->x = x;
		this->y = y;
	}

	void operator = (coordinate c){
		this->x = c.x;
		this->y = c.y;
	}
	void set_char(char graph[][Y], char _char){
		graph[x][y] = _char;
	}
	char get_char(char graph[][Y]){
		return graph[x][y];
	}

}; 
typedef struct coordinate coor;
#endif
