#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
#define HEIGHT 20
#define WIDTH 10

int angle=0;

char backGroundGrahic[HEIGHT+1+3][WIDTH+1]={
	"          ",
	"          ",
	"          ",
	"          ",
	"          ",
	"          ",
	"          ",
	"          ",
	"          ",
	"          ",
	"          ",
	"          ",
	"          ",
	"          ",
	"          ",
	"          ",
	"          ",
	"          ",
	"          ",
	"          ",
	"          ",
	"          ",
	"          ",
	"----------"
};

//	int leftPos;
//	int rightPos;
//	int topPos;
//	int bottomPos;
typedef struct block{
	char name;
	int id;
	int shape[4][4];
	
}block;

//0 1 2 3 
//4 5 6 7
//8 9 10 11
//12 13 14 15
void CreateBlockById(block *b ,int id){
	switch(id){
		case 0:{//¥Îscope¥iÁ×§Kshape¤¬¬Û¤zÂZ 
			b->name='I';
			int shape[4][4]={
				{0,1,2,3},
				{0,4,8,12},
				{12,13,14,15},
				{3,7,11,15}
			};
			memcpy(b->shape, shape, sizeof(shape));
			b->id=id;
			return;
		}
		case 1:{ 
			b->name='T';
			int shape[4][4]={
				{0,1,2,5},
				{2,6,10,5},
				{8,9,10,5},
				{0,4,8,5}
			};
			memcpy(b->shape, shape, sizeof(shape));
			b->id=id;
			return;
		} 
		case 2:{
			b->name='O';
			int shape[4][4]={
				{0,1,4,5},
				{0,1,4,5},
				{0,1,4,5},
				{0,1,4,5}
			};
			memcpy(b->shape, shape, sizeof(shape));
			b->id=id;
			return;
		}
		case 3:{
			b->name='J';
			int shape[4][4]={
				{0,4,5,6},
				{0,1,4,8},
				{0,1,2,6},
				{1,5,8,9}
			};
			memcpy(b->shape, shape, sizeof(shape));
			b->id=id;
			return;
		}
		case 4:{
			b->name='L';
			int shape[4][4]={
				{0,1,5,9},
				{4,5,6,2},
				{0,4,8,9},
				{0,1,2,4}
				
			};
			memcpy(b->shape, shape, sizeof(shape));
			b->id=id;
			return;
		}
		case 5:{
			b->name='Z';
			int shape[4][4]={
				{0,1,5,6},
				{2,6,9,5},
				{4,9,10,5},
				{1,4,8,5}
			};
			memcpy(b->shape, shape, sizeof(shape));
			b->id=id;
			return;
		}
		case 6:{
			b->name='S';
			int shape[4][4]={
				{1,2,5,4},
				{1,5,6,10},
				{5,6,8,9},
				{0,4,5,9}
			};
			memcpy(b->shape, shape, sizeof(shape));
			b->id=id;
			return;
		}
		default:{
			b->name='\0';
			memcpy(b->shape, 0, sizeof(b->shape));
			b->id=id;
			return;
		}
	}
}

int TurnRight(int angle){
	angle++;
	if(angle>3)angle=0;
	return angle;
}
int TurnLeft(int angle){
	angle--;
	if(angle<0)angle=3;
	return angle;
}

void PrintGraphic(char grahic[HEIGHT+1+3][WIDTH+1]){
	for(int i=3;i<HEIGHT+1+3;i++){
		printf("%s\n", grahic[i]);
	}
}

void ResetCursor(void){
	printf("\033[H");
}

void DrawBlockGraphic(char grahic[HEIGHT+1+3][WIDTH+1], int x, int y, int ba[4]){
	for(int i=0;i<4;i++){
		grahic[y+ba[i]/4][x+ba[i]%4]='#';
	}
}

char GetInput(void){
	if(kbhit()){
		return getch();
	}
	return '\0';
}

bool BlockIsHitOnXY(int ba[4], int x, int y, char grahic[HEIGHT+1+3][WIDTH+1]){
	for(int i=0;i<4;i++){
		if(grahic[y+ba[i]/4][x+ba[i]%4]!=' '){
			return true;
		}
	}
	return false;
}

bool RowCanEliminate(char row[WIDTH+1]){
	for(int i=0;i<WIDTH;i++){
		if(row[i]==' ') return false;
	}
	return true;
}

void TryEliminateRow(char grahic[HEIGHT+1+3][WIDTH+1]){
	for(int i=HEIGHT+2;i>0;i--){
		if(!RowCanEliminate(grahic[i])) continue;
		Sleep(130);
		for(int j=i;j>0;j--){
			strcpy(grahic[j], grahic[j-1]);
		}
		i++;
		PrintGraphic(grahic);
		ResetCursor();
	}
}

int main(){
	srand(time(NULL));
	block b;
	char input;
	int x,y, a;
	
	char grahic0[HEIGHT+1+3][WIDTH+1];
	char grahic[HEIGHT+1+3][WIDTH+1];	
	
	memcpy(grahic0, backGroundGrahic, sizeof(backGroundGrahic));
	memcpy(grahic, grahic0, sizeof(backGroundGrahic));
	PrintGraphic(grahic);
	ResetCursor();
	Sleep(2500);
	
	while(true){
		
		CreateBlockById(&b, rand()%7);
		if(BlockIsHitOnXY(b.shape[angle], 4, 3, grahic0)) break;
		x=4;y=3;a=0;
		
		while(true){
			if(BlockIsHitOnXY(b.shape[angle], x, y, grahic0)) break;
			memcpy(grahic, grahic0, sizeof(backGroundGrahic));
			Sleep(20);
			input=GetInput();
			if(input=='e' && !BlockIsHitOnXY(b.shape[TurnRight(angle)], x, y, grahic0)){
				angle=TurnRight(angle);
				
			}
			if(input=='q' && !BlockIsHitOnXY(b.shape[TurnLeft(angle)], x, y, grahic0)){
				angle=TurnLeft(angle);
				
			}
			if(input=='a' && !BlockIsHitOnXY(b.shape[angle], x-1, y, grahic0)){
				x--;
			}
			if(input=='d' && !BlockIsHitOnXY(b.shape[angle], x+1, y, grahic0)){
				x++;
			}
			if(input=='s' && !BlockIsHitOnXY(b.shape[angle], x, y+1, grahic0)){
				y++;
			}
			DrawBlockGraphic(grahic, x, y, b.shape[angle]);
			PrintGraphic(grahic);
			ResetCursor();
			
			if(a%10==0){
				y++;
			}
			a++;
		}
		TryEliminateRow(grahic);
		memcpy(grahic0, grahic, sizeof(backGroundGrahic));
		
		
	}
	
	
	
	return 0;
}


