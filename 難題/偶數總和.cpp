#include<stdio.h> 

// �p�ⰸ�ƪ��`�M(2+4+6+�K+n)�A�䤤n���������ơA�i����L�ۦ��J�C
//�Y��J�����O�����ơA�h�{���|�n�D�ϥΪ̦A����J�A�����J���ƬO�����Ƭ���

int main(){
	
	int n;
	do{
		scanf("%d", &n);
	}while( !(n%2==0 && n>0) );
	
	printf("%d", (n/2)*(2+n)/2);
	
	
	return 0;
}
