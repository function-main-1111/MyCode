#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	
	
	
	srand(time(NULL));
	
	int a, b=rand()%3+1;
	printf("1.剪刀 2.石頭 3.布\n");
	scanf("%d", &a);
	
	   printf("你: ");
    switch (a) {
        case 1: printf("剪刀"); break;
        case 2: printf("石頭"); break;
        case 3: printf("布"); break;
        default: printf("無效選擇\n"); return 0;
    }

    printf(" 電腦: ");
    switch (b) {
        case 1: printf("剪刀\n"); break;
        case 2: printf("石頭\n"); break;
        case 3: printf("布\n"); break;
    }
	
	if(a==b){
		printf("平手\n");
	}
	if(a==1 && b==3 || a==2 && b==1 || a==3 && b==2){
		printf("贏了\n");
	}
	else{
		printf("輸了\n");
	}
	
}
