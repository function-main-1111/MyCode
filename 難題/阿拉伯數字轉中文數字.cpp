#include<stdio.h>

void PrintCh(int a){
	
	switch(a){
		
		case 0: printf("�s");break;
		case 1: printf("�@");break;
		case 2:	printf("�G");break;
		case 3:	printf("�T");break;
		case 4: printf("�|");break;
		case 5:	printf("��");break;
		case 6:	printf("��");break;
		case 7: printf("�C");break;
		case 8: printf("�K");break;
		case 9: printf("�E");break;
		case 10:printf("�Q");
	}
	
}

int main(){
	
	int a;
	scanf("%d", &a);
	if(a>10||a<0){
		printf("�L�ļƦr");
	}
	PrintCh(a);
	
	return 0;
}


