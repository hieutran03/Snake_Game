#ifndef snake_H
#define snake_H
#include"common.h"
#include "coordinate.h"
#include "map.h"
struct snake{
	coordinate head;
	vector<coordinate> body;
	coor back(){
		return body[body.size()-1];
	}
	coor top(){
		return body[0];
	}
};
void initSnake(char graph[][Y], snake &sna){
	int x = X/2, y = Y/2;
	graph[x-1][y] = (char)15;
	graph[x][y] = 'o';
	graph[x+1][y] = '+';
	sna.head.set_coor(x+1,y);
	coordinate c;
	c.set_coor(x,y);
	sna.body.push_back(c);
	c.set_coor(x-1,y);
	sna.body.push_back(c);
	
}
void bodyMove(char graph[][Y], coor prev_head, vector<coor> &body){
		coor prev_back = body[body.size()-1];
		
		for(int i = body.size()-1; i > 0; i--){
			body[i] = body[i-1];
		}
		body[0] = prev_head;
		body[0].set_char(graph, 'o');
		body[body.size()-1].set_char(graph,(char)15); 
 		prev_back.set_char(graph, '.');
}
bool checkMove(snake sna, char graph[][Y]){
	if(sna.head.get_coor() == sna.back().get_coor())
		return 1;
	if(sna.head.get_char(graph) == 'o' || sna.head.x<0 || sna.head.x >= X || sna.head.y < 0 || sna.head.y >= Y){
		return 0;
	}
	return 1;
}
bool isAteApple(char graph[][Y], snake sna, int point){
	if(point >= X*Y-4 && sna.head.get_char(graph) == 'x')
		return 1;
	if(sna.head.get_char(graph) == 'x'){
		createApple(graph);
		return 1;
	}
	return 0;
}
bool snakeMove(char graph[][Y], snake &sna, char option, int &point){
	coor prev_head = sna.head;
	if(option == 72){
		sna.head.y--;
	}else if (option == 80){
		sna.head.y++;
	}else if(option == 75){
		sna.head.x--;
	}else if(option == 77){
		sna.head.x++;
	}else{
		return 1;
	}
	if(sna.head.get_coor() == sna.top().get_coor()){
		sna.head = prev_head;
		return 1;
	}
	
	if(!checkMove(sna, graph)){
		sna.head = prev_head;
		return 0;
	}
	
	int check_is_ate_apple = isAteApple(graph, sna, point);
	if(check_is_ate_apple == 0)
		bodyMove(graph, prev_head, sna.body);
	else if(check_is_ate_apple == 1){
		prev_head.set_char(graph, 'o');
		sna.body.insert(sna.body.begin(), prev_head);
		point++;	
	}
	sna.head.set_char(graph, '+');
	

	return 1;
}


#endif
