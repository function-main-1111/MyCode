#include<stdio.h> 

// 璸衡案计羆㎝(2+4+6++n)ㄤいnタ案计パ龄絃︽块
//璝块ぃ琌タ案计玥祘Α穦璶―ㄏノΩ块块计琌タ案计ゎ

int main(){
	
	int n;
	do{
		scanf("%d", &n);
	}while( !(n%2==0 && n>0) );
	
	printf("%d", (n/2)*(2+n)/2);
	
	
	return 0;
}
