#include<stdio.h> 
#include<stdlib.h>
#include<string.h>

//1.�t�Τ��w�]�K�X��1234�A�ϥΪ̻ݭn��J���T���K�X�~��n�J�C
//2.���ϥΪ̦ܤֿ�J�@���K�X�A�p�G�K�X���~�h���ܭ��s��J�A�����J���T����C
//3.��n�J���\��A���ϥΪ̿�ܾާ@�G
//�E���1�G���"�w��i�J�t��"�C
//�E���2�G���"�ק�]�w"�C
//�E���0�G�����t�ΡA�ø��X�j��

typedef struct{
	char name[20];
	int pwd;
} account;

void init_account(account *self, const char *name, int pwd){
	strncpy(self->name, name, sizeof(self->name)-1);
	self->pwd=pwd;
}

void destroy_account(account *self){
	free(self);
}

bool PwdIsCorrect(account *self, int pwd){
	return self->pwd==pwd;
}

account *new_account(const char *name, int pwd){
	account *ac= (account*) malloc(sizeof(account));
	init_account(ac, name, pwd);
	return ac;
}

int main(){
	
	int pwd=1234;
	char *myName="Ming" ;
	
	int etrPwd, selet;
	
	account *me=new_account(myName, pwd);
	//init_account(&me, myName, pwd);
	printf("�b��\n%s\n", me->name);
	printf("�п�J�K�X ");
	scanf("%d", &etrPwd);
	while(!PwdIsCorrect(me, etrPwd)){
		printf("�K�X���~�A�Э��s��J\n");
		scanf("%d", &etrPwd);
		if(etrPwd==-1){
			destroy_account(me);
			return 0;
		}
	}
	while(true){
		printf("��ܾާ@�G\n���1�G���\"�w��i�J�t��\"\n���2�G���\"�ק�]�w\"\n���0�G�����t��\n  ");
		scanf("%d", &selet);
		if(selet==0) break;
		switch(selet){
			case 1:
				printf("�w��i�J�t��\n\n");
				break;
			case 2:
				printf("�ק�]�w\n\n");
				break;
			default:
				printf("�Э��s��J\n\n");
				break;
		}
	}
	
	destroy_account(me);
	
	return 0;
}
