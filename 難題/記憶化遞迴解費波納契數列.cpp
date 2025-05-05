#include<stdio.h>
#include<stdlib.h>
#include<time.h>


long long *cache=NULL, current;

//void ensure_capacity;

long long Fib(long long n){
	
	if(n<=current){
		return cache[n];
	}
	
	cache[n]=Fib(n-1)+Fib(n-2);
	current=n;
	return cache[n];
	
}

int main(){
	
	long long n=1;double startClk;
	cache= (long long *) realloc(cache, (n+1)*sizeof(long long));
	cache[0]=0;cache[1]=1;current=1;
	
	while(true){
		printf("�O�i�ǫ���");
		scanf("%lld", &n);
		if(n<1) break;
		startClk=clock();
//		ensure_capacity();
		if(n>current){
			cache= (long long *) realloc(cache, (n+1)*sizeof(long long));
		}
		printf("��%lld\n\n", Fib(n));
		printf("��O�ɶ�%.10fms\n\n", (clock()-startClk)/CLOCKS_PER_SEC);
	}
	
	free(cache);
	
	return 0;
}

//void ensure_capacity(){
//	
//}
