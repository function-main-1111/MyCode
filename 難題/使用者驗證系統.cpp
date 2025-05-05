#include<stdio.h> 
#include<stdlib.h>
#include<string.h>

//1.系統內預設密碼為1234，使用者需要輸入正確的密碼才能登入。
//2.讓使用者至少輸入一次密碼，如果密碼錯誤則提示重新輸入，直到輸入正確為止。
//3.當登入成功後，讓使用者選擇操作：
//‧選擇1：顯示"歡迎進入系統"。
//‧選擇2：顯示"修改設定"。
//‧選擇0：結束系統，並跳出迴圈

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
	printf("帳號\n%s\n", me->name);
	printf("請輸入密碼 ");
	scanf("%d", &etrPwd);
	while(!PwdIsCorrect(me, etrPwd)){
		printf("密碼錯誤，請重新輸入\n");
		scanf("%d", &etrPwd);
		if(etrPwd==-1){
			destroy_account(me);
			return 0;
		}
	}
	while(true){
		printf("選擇操作：\n選擇1：顯示\"歡迎進入系統\"\n選擇2：顯示\"修改設定\"\n選擇0：結束系統\n  ");
		scanf("%d", &selet);
		if(selet==0) break;
		switch(selet){
			case 1:
				printf("歡迎進入系統\n\n");
				break;
			case 2:
				printf("修改設定\n\n");
				break;
			default:
				printf("請重新輸入\n\n");
				break;
		}
	}
	
	destroy_account(me);
	
	return 0;
}
