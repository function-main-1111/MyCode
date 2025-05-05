#include<stdio.h>
#include<stdlib.h>
#include<time.h>


long long Fib(long long n){
	
	switch(n){
		case 1:
			return 1;
		case 2:
			return 1;
	}
	
	long long a=1, b=1;
	
	for(long long i=3;i<=n;i++){
		a^=b^=a^=b;
		b+=a;
	}
	
	return b;
	
}

int main(){
	
	long long n=1;double startClk;
	
	while(true){
		printf("費波納契第");
		scanf("%lld", &n);
		if(n<1) break;
		startClk=clock();
		printf("為%lld\n\n", Fib(n));
		printf("花費時間%.10fms\n\n", (clock()-startClk)/CLOCKS_PER_SEC);
	}
	
	return 0;
}

//void ensure_capacity(){
//	
//}
