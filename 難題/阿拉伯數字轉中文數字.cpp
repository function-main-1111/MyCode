#include<stdio.h>

void PrintCh(int a){
	
	switch(a){
		
		case 0: printf("零");break;
		case 1: printf("一");break;
		case 2:	printf("二");break;
		case 3:	printf("三");break;
		case 4: printf("四");break;
		case 5:	printf("五");break;
		case 6:	printf("六");break;
		case 7: printf("七");break;
		case 8: printf("八");break;
		case 9: printf("九");break;
		case 10:printf("十");
	}
	
}

int main(){
	
	int a;
	scanf("%d", &a);
	if(a>10||a<0){
		printf("無效數字");
	}
	PrintCh(a);
	
	return 0;
}


