#ifndef coordinate_H
#define coordinate_H
#include"common.h"

//coordinate

struct coordinate{
	int x, y;
	void set_coor(int x, int y){
		this->x = x;
		this->y = y;
	}
	coordinate get_coor(){
		return *this;
	}
	
	void set_char(char graph[][Y], char _char){
		graph[x][y] = _char;
	}
	char get_char(char graph[][Y]){
		return graph[x][y];
	}
	void operator = (coordinate c){
		this->x = c.x;
		this->y = c.y;
	}
	bool operator == (coordinate c){
		if(this->x == c.x && this->y == c.y)
			return 1;
		return 0;	
	}
}; 
typedef struct coordinate coor;
#endif
