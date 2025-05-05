#include<stdio.h>
#include<math.h>

bool NumIsPrimeNum(long long num){
	switch(num){
		case 1:
			return false;
		case 2:
			return true;
		case 3:
			return true;
	}
	long long sq;bool isDivisible=false;
	sq=ceil(sqrt(num));
	//printf("%d", sq);
	for(long long i=2;i<=sq;i++){
		if(num%i==0) isDivisible=true;
	}
	return !isDivisible;
}

int main(){
	
	long long num;
	scanf("%lld", &num);
	switch(NumIsPrimeNum(num)){
		case true:
			printf("是質數\n");
			break;
		case false:
			printf("非質數\n");
			break;
	}
	
	return 69;
} 
