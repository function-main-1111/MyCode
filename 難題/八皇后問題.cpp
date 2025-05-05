#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//�b 8��8 ����ڶH�ѴѽL�W�A
//�ӦZ�����d��Q�r�M�﨤�u�A
//�ؼЩ�m 8 �ӬӦZ�A 
//�ϱo�C�ӬӦZ�����������������C

const char S=' ';
const char Q='Q';
const char A='.';
int cnt=0;

void PutQueen(char arr[8][8], int row, int col){
	//��W'-'�N����A��ӦZ 
	//�Q�r�u �׹﨤 ��'-'
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
    
    //�M���C��
    //�e���C��row�����@�ӦZ�A���L�e���w���ӦZ��row
    for(int i=startRow; i<8; i++){
    	for(int j=0; j<8; j++){
    		if(cnt>=100){
    			return;
			}
			//�C�鳣�л\arr�A�H�^���쥼�U��e��n�ӬӦZ�����p
			memcpy(arr, arr0, sizeof(arr));
			//�ӦZ�হ���N������A�����Ncontinue�ݤU�@��
			if(arr[i][j]!=S){
				continue;
			}
			PutQueen(arr, i, j);
			//�Y�w�g�U�F��8�ӬӦZ�A�h��ܥX��
			//�_�h�B�z�U�@�ӬӦZ (��n+1��)
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
