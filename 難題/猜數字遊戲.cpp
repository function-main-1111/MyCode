#include<stdio.h> 
#include<stdlib.h>
#include<time.h>

//���C�������]�w�@�өT�w���ؼмƦr�]�Ҧptarget = 7�^�A�ϥΪ̻ݭn��J�Ʀr�Ӳq���ӼƦr�C
//�C���W�h�p�U�G
//1.�Y��J0�A�h���e�����C��(break)�A���A�~��q���C
//2.�Y��J���Ʀr���b1~10 �����A�h���ܿ�J���~�A�n�D���s��J(continue)�A���i�����P�_�C
//3.�Y��J���Ʀr�p��ؼмƦr�A���"�Ӥp�F�I�A�դ@���C"
// 4.�Y��J���Ʀr�j��ؼмƦr�A���"�Ӥj�F�I�A�դ@���C"
// 5.�Y��J���Ʀr����ؼмƦr�A���"���ߡI�A�q��F�I"

int main(){
	
	int target, guess;
	srand(time(0));
	target=1+rand()%100;
	
	printf("1~100�q�Ʀr\n");
	while(true){
		scanf("%d", &guess);
		if(guess==0) break;
		if(guess>100 || guess<=0) printf("���s��J\n");
		else if(guess==target){
			printf("���ߡI�A�q��F�I\n");
			break;
		}
		else if(guess<target){
			printf("�Ӥp�F�I�ڷw�w\n");
		}
		else if(guess>target){
			printf("�Ӥj�Fdady\n");
		}
	}
	
	return 0;
}
