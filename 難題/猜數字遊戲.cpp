#include<stdio.h> 
#include<stdlib.h>
#include<time.h>

//本遊戲內部設定一個固定的目標數字（例如target = 7），使用者需要輸入數字來猜測該數字。
//遊戲規則如下：
//1.若輸入0，則提前結束遊戲(break)，不再繼續猜測。
//2.若輸入的數字不在1~10 之間，則提示輸入錯誤，要求重新輸入(continue)，不進行後續判斷。
//3.若輸入的數字小於目標數字，顯示"太小了！再試一次。"
// 4.若輸入的數字大於目標數字，顯示"太大了！再試一次。"
// 5.若輸入的數字等於目標數字，顯示"恭喜！你猜對了！"

int main(){
	
	int target, guess;
	srand(time(0));
	target=1+rand()%100;
	
	printf("1~100猜數字\n");
	while(true){
		scanf("%d", &guess);
		if(guess==0) break;
		if(guess>100 || guess<=0) printf("重新輸入\n");
		else if(guess==target){
			printf("恭喜！你猜對了！\n");
			break;
		}
		else if(guess<target){
			printf("太小了！我暈針\n");
		}
		else if(guess>target){
			printf("太大了dady\n");
		}
	}
	
	return 0;
}
