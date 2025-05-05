#include<stdio.h>

void PrintEven(int n){
	
	if(n==1){
		return ;
	}
	
	if(n%2==0){
		printf("%d ", n);
	}
	
	PrintEven(n-1);
	
}

int main(){
	
	int a;
	scanf("%d", &a);
	PrintEven(a);
	
	return 0;
}
