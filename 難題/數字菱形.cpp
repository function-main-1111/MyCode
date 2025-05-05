#include<stdio.h>

void newIterator(int *arr, int n){
	for(int i=0; i<(n+1)/2; i++){
		arr[i]=arr[n-i-1]=i+1;
	}
}

void newIteratorFib(int *arr, int n){
	if(n==1){
		arr[0]=1;
		return;
	}
	arr[1]=1;
	for(int i=2; i<n; i++){
		arr[i]=arr[i-1]+arr[i-2];
	}
}

void printIterator(int *arr, int n){
	for(int i=0; i<n; i++){
		printf("%d", arr[i]);
	}
}

int main(){
	int n, m;
	scanf("%d", &n);
	m=2*n-1;
	int iterator[m];
	bool flip=false;
	for(int i=1; i>0; ){
		for(int j=1; j<=n-i;j++){
			printf(" ");
		}
		//newIteratorFib(iterator, i*2-1);
		newIterator(iterator, i*2-1);
		printIterator(iterator, i*2-1);
		printf("\n");
		//到中間翻轉回去 
		if(i==n) flip=true;
		switch(flip){
			case true:
				i--;break;
			case false:
				i++;break;
		}
	}
	
	return 69;
} 
