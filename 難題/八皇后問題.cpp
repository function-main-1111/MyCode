#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//在 8×8 的國際象棋棋盤上，
//皇后攻擊範圍十字和對角線，
//目標放置 8 個皇后， 
//使得每個皇后彼此都不能攻擊到對方。

const char S=' ';
const char Q='Q';
const char A='.';
int cnt=0;

void PutQueen(char arr[8][8], int row, int col){
	//放上'-'代表不能再放皇后 
	//十字線 斜對角 放'-'
	for(int i=0; i<8; i++){
		arr[i][col]=A;
		arr[row][i]=A;
		if(row+i<8 && col+i<8){
			arr[row+i][col+i]=A;
		}
		if(row+i<8 && col-i>=0){
			arr[row+i][col-i]=A;
		}
		if(row-i>=0 && col-i>=0){
			arr[row-i][col-i]=A;
		}
		if(row-i>=0 && col+i<8){
			arr[row-i][col+i]=A;
		}
	}
	arr[row][col]=Q;
}

void PrintChessBoard(char arr[8][8]){
	for(int i=0; i<8; i++){
    	for(int j=0; j<8; j++){
			printf("%2c", arr[i][j]); 
		}
		printf("\n");
	}
}

void EightQueen(int n, char arr0[8][8], int startRow){
    
    char arr[8][8];
    
    //遍歷每格
    //前面每個row必有一皇后，跳過前面已有皇后的row
    for(int i=startRow; i<8; i++){
    	for(int j=0; j<8; j++){
    		if(cnt>=100){
    			return;
			}
			//每圈都覆蓋arr，以回溯到未下當前第n個皇后的情況
			memcpy(arr, arr0, sizeof(arr));
			//皇后能此格放就直接放，不能放就continue看下一格
			if(arr[i][j]!=S){
				continue;
			}
			PutQueen(arr, i, j);
			//若已經下了第8個皇后，則顯示出來
			//否則處理下一個皇后 (第n+1個)
			if(n==8){
				cnt++;
				printf("%d\n", cnt);
				PrintChessBoard(arr);
				printf("\n");
			}
			else{
				EightQueen(n+1, arr, i);
			}
		}
	}
    
}



int main(){
	char arr[8][8]=
	{
		{ S, S, S, S, S, S, S, S},
		{ S, S, S, S, S, S, S, S},
		{ S, S, S, S, S, S, S, S},
		{ S, S, S, S, S, S, S, S},
		{ S, S, S, S, S, S, S, S},
		{ S, S, S, S, S, S, S, S},
		{ S, S, S, S, S, S, S, S},
		{ S, S, S, S, S, S, S, S}
	};
	
	EightQueen(1, arr, 0);
	
	return 0;
}
