#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	
	
	
	srand(time(NULL));
	
	int a, b=rand()%3+1;
	printf("1.�ŤM 2.���Y 3.��\n");
	scanf("%d", &a);
	
	   printf("�A: ");
    switch (a) {
        case 1: printf("�ŤM"); break;
        case 2: printf("���Y"); break;
        case 3: printf("��"); break;
        default: printf("�L�Ŀ��\n"); return 0;
    }

    printf(" �q��: ");
    switch (b) {
        case 1: printf("�ŤM\n"); break;
        case 2: printf("���Y\n"); break;
        case 3: printf("��\n"); break;
    }
	
	if(a==b){
		printf("����\n");
	}
	if(a==1 && b==3 || a==2 && b==1 || a==3 && b==2){
		printf("Ĺ�F\n");
	}
	else{
		printf("��F\n");
	}
	
}
