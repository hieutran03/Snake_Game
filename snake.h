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
	graph[7][8] = graph[8][8] = 'o';
	graph[9][8] = '+';
	sna.head.set(9,8);
	coordinate c;
	c.set(8,8);
	sna.body.push_back(c);
	c.set(7,8);
	sna.body.push_back(c);
	
}
void bodyMove(char graph[][Y], coor prev_head, vector<coor> &body){
		coor prev_back = body[body.size()-1];
		
		for(int i = body.size()-1; i > 0; i--){
			body[i] = body[i-1];
		}
		body[0] = prev_head;
		body[0].set_char(graph, 'o'); 
 		prev_back.set_char(graph, '.');
}
bool checkMove(snake sna, char graph[][Y]){
	if(sna.head.get_char(graph) == 'o' || sna.head.x<0 || sna.head.x >= X || sna.head.y < 0 || sna.head.y >= Y){
		return 0;
	}
	return 1;
}
bool eatApple(char graph[][Y], snake sna){
	if(sna.head.get_char(graph) == 'x'){
		createApple(graph);
		return 1;
	}
	return 0;
}
bool snakeMove(char graph[][Y], snake &sna, char option){
	coor prev_head = sna.head;
	if(option == 'w' || option == 'W'){
		sna.head.y--;
	}else if (option == 's'|| option == 'S'){
		sna.head.y++;
	}else if(option == 'a'|| option == 'A'){
		sna.head.x--;
	}else if(option == 'd'|| option == 'D'){
		sna.head.x++;
	}else{
		return 1;
	}
	if(!checkMove(sna, graph)){
		sna.head = prev_head;
		return 0;
	}
	
	if(!eatApple(graph, sna))
		bodyMove(graph, prev_head, sna.body);
	else{
		prev_head.set_char(graph, 'o');
		sna.body.insert(sna.body.begin(), prev_head);
	}
	sna.head.set_char(graph, '+');

	return 1;
}


#endif
