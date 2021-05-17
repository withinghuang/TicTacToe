#include "tictactoe.h"
#include <iostream>
TicTacToe::TicTacToe(){
	checkerboard = new char[3][3];
	init();
}
void TicTacToe::showBoard(void){
	std::cout << "   | A | B | C | ";
	for (int x =0;x<3;x++){
	std::cout << std::endl<<"-----------------"<<std::endl;
		std::cout << x+1 << " ";
		for (int y=0;y<3;y++){
			std::cout << " | "<<checkerboard[x][y];
		}
		std::cout << " | ";
	}
	std::cout <<std::endl;	
}

TicTacToe::~TicTacToe(){
	delete [] checkerboard;
}

bool TicTacToe::placePiece(bool player,int x,int y){
	if (checkerboard[x][y]=='X' || checkerboard[x][y]=='O'){
		return false;
	}
	if (player){
		checkerboard[x][y]='O';
		return true;
	}
	else{
		checkerboard[x][y]='X';
		return true;
	}
}
void TicTacToe::init(void){	
	for (int x =0;x<3;x++){
		for (int y=0;y<3;y++){
			checkerboard[x][y] = ' ';
		}
	}
}
void TicTacToe::play(void){
	bool currentPlayer = true;
	while (true){
		char position[2];
		if (currentPlayer){
			std::cout << "O player:";
		}else{
			std::cout << "X player:";}
		std::cin >> position;
		int x = int ((position[0])) - 49;
		int y = int ((position[1])) - 65;
		if (placePiece(currentPlayer,x,y)){
			if (checkWin(currentPlayer,x,y)){
				std::cout << "game end\n";
				init();
				continue;
			}
			currentPlayer = !currentPlayer;
			showBoard();
		}
		else{
			std::cout << "place error!\n";
		}
	}
}

bool TicTacToe::checkWin(bool player,int x,int y){
	int by = y;int ey = y;
	int bx = x;int ex = x;
	char piece;
	if (player){piece = 'O';}
	else{piece='X';};
	/*y axis*/
	while((by >= 0) && (checkerboard[x][by]==piece)){
		by = by-1;
	}
	while((ey <=2) && (checkerboard[x][ey]==piece)){
		ey = ey+1;
	}
	if ((ey-by-1)>=3)return true;
	/*x axis*/
	by=y;ey=y;bx=x;ex=x;
	while((bx >= 0) && (checkerboard[bx][y]==piece)){
		bx = bx-1;
	}
	while((ex <= 2) && (checkerboard[ex][y]==piece)){
		ex=ex+1;
	}
	if((ex-bx-1)>=3)return true;
	/* x=y aixs*/
	by=y;ey=y;bx=x;ex=x;
	while((bx >=0) && (by>=0) && (checkerboard[bx][by]==piece)){
		bx--;by--;
	}
	while((ex <= 2) && (ey <= 2) && checkerboard[ex][ey]==piece){
		ex++;ey++;
	}
	if ((ey-by-1)>=3)return true;
	/* x =-y */
	by=y;ey=y;bx=x;ex=x;
	while(bx<=2 && by>=0 && checkerboard[bx][by]==piece){
		bx++;by--;
	}
	while(ex>=0 && ey<=2 && checkerboard[ex][ey]==piece){
		ex--;ey++;
	}
	if((ey-by-1)>=3)return true;
	return false;
}


