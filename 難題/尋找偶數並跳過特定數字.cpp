#include<stdio.h> 

// �мg�@�ӵ{���A�ϥ�for�j��ӦC�L1 ��20 �������Ҧ����ơA�òŦX�H�U�W�h�G
//1.�p�G�Ʀr�O10�A�h���L���L�X(continue)�C
//2.�p�G�Ʀr�W�L16�A�h���e�����j��(break)

int main(){
	
	int n=20;
	for(int i=2;i<=20;i+=2){
		if(i==10) continue;
		if(i>16) break;
		printf("%d ", i);
	}
	
	
	return 0;
}
