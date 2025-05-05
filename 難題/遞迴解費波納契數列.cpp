#include<stdio.h>
#include<time.h>

int Fib(int n){
	
	switch(n){
		case 1:
			return 1;
		case 2:
			return 1;
	}
	
	return Fib(n-1)+Fib(n-2);
	
}

int main(){
	
	int n; double startClk;
	while(true){
		printf("¶Oªi¯Ç«´²Ä");
		scanf("%d", &n);
		if(n<1) break;
		startClk=clock();
		printf("¬°%d\n", Fib(n));
	}
	
	
	return 0;
} 
