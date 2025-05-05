#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ll long long

//[F(n)   F(n-1)] = [1 1]^(n-1)
//[F(n-1) F(n-2)]	[1 0]

//2^10=1024
//1. a=2  r=1  n=10
//2. a=4  r=1  n=5
//3. a=4  r=4  n=4
//4. a=16 r=4  n=2
//5. a=256 r=4 n=1
//6. a*r=1024

//M=AB
//Mij=sigma k=1, n Aik*bkj

void MatrixMultip(ll m1[2][2], ll m2[2][2]){
	ll m3[2][2];
	for(int i=0;i<2; i++){
		for(int j=0;j<2; j++){
			m3[i][j]=0;
			for(int k=0;k<2; k++){
				m3[i][j]+=m1[i][k]*m2[k][j];
			}
		}
	}
	//copy
	for(int i=0;i<2; i++){
		for(int j=0;j<2; j++){
			m1[i][j]=m3[i][j];
		}
	}
}

void MatrixFastPow(ll matrix[2][2], ll n){
	
	ll matrix2[2][2]={ {1, 0},
					   {0, 1} };
	while(n>1){
		if(n%2!=0){
			MatrixMultip(matrix2, matrix);
		}
		MatrixMultip(matrix, matrix);
		n/=2;
	}
	MatrixMultip(matrix, matrix2);
}

ll Fib(ll n){
	
	switch(n){
		case 1:
			return 1;
		case 2:
			return 1;
	}
	
	ll fibMatrix[2][2]={ {1, 1},
						 {1, 0} };
	MatrixFastPow(fibMatrix, n-1);
	
	return fibMatrix[0][0];
	
}

int main(){
	
	ll n=1;double startClk;
	
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

