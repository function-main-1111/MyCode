#include<stdio.h> 

// 請寫一個程式，使用for迴圈來列印1 到20 之間的所有偶數，並符合以下規則：
//1.如果數字是10，則跳過不印出(continue)。
//2.如果數字超過16，則提前結束迴圈(break)

int main(){
	
	int n=20;
	for(int i=2;i<=20;i+=2){
		if(i==10) continue;
		if(i>16) break;
		printf("%d ", i);
	}
	
	
	return 0;
}
