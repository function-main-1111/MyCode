#include<stdio.h>
#include<conio.h>
#include<windows.h>
//#include<time.h>
//#include<unistd.h>

#define HEIGHT 10
#define WIDTH 20
#define PWD 1234



enum state_codes {
	_insertCard=0,
	_enterPwd=	1,
	_sltFnct=	2,
	_withdraw=	3,
	_balance=	4,
	_1000=		5,
	_3000=		6,
	_5000=		7,
	_errorPwd=	8,
	_locked=	9,
	_retCard=	10,
	_end=		11
};

enum ret_codes {
	goMenu=		0,
	goEnterPwd=	1,
	goSlt=		2,
	goWithdraw=	3,
	get1000=	4,
	get3000=	5,
	get5000=	6,
	inquiry=	7,
	errPwd=		8,
	lock=		9,
	retCard=	10,
	endProgram=	11
};



void PrintGraphic(char graphic[HEIGHT][WIDTH+1]){
	for(int i=0; i<HEIGHT; i++){
		if(graphic[i][0]=='@'){
			for(int j=1; j<WIDTH; j++){
				if(graphic[i][j]=='@') return;
				printf("%c", graphic[i][j]);
			}
		}
		printf("%s\n", graphic[i]);
	}
}
void ClearGraphic(void){
	printf("\033[H");
}
void ClearGraphic2(void){
	printf("\033[H");
	char graphic[HEIGHT][WIDTH+1]={
		"                    ",
		"                    ",
		"                    ", 
		"                    ",
		"                    ",
		"                    ",
		"                    ",
		"                    ",
		"                    ",
		"                    "
		
	};
	PrintGraphic(graphic);
	printf("\033[H");
}

int state_insertCard(void){
	ClearGraphic();
	char graphic[HEIGHT][WIDTH+1]={
		"                    ",
		"                    ",
		"      1.���J�d��    ", 
		"      0.����        ",
		"                    ",
		"                    ",
		"                    ",
		"                    ",
		"                    ",
		"                    "
		
	};
	PrintGraphic(graphic);
	int input;
	while(true){
		input=_getch()-'0';
		if(input==1) return goEnterPwd;
		if(input==0) return endProgram;
	}
	
}
int state_enterPwd(void){
	int input;
	while(true){
		ClearGraphic2();
		char graphic[HEIGHT][WIDTH+1]={
			"                    ",
			"                    ",
			"     ��J�K�X       ", 
		   "@  �K�X:@           ",
			"                    ",
			"                    ",
			"                    ",
			"                    ",
			"                    ",
			"                    "
			
		};
		PrintGraphic(graphic);
		scanf("%d", &input);
		if(input!=PWD){
			return errPwd;
		}
		return goSlt;
	}
}
int balance=5000000;
int state_sltFnct(void){
	ClearGraphic();
	char graphic[HEIGHT][WIDTH+1]={
		"                    ",
		"                    ",
		"     1.����         ", 
		"     2.�d�߾l�B     ",
		"     0.�������     ",
		"                    ",
		"                    ",
		"                    ",
		"                    ",
		"                    "
		
	};
	PrintGraphic(graphic);
	int input;
	while(true){
		input=_getch()-'0';
		if(input==1) return goWithdraw;
		if(input==2) return inquiry;
		if(input==0) return retCard;
	}	
}
int state_withdraw(void){
	ClearGraphic();
	char graphic[HEIGHT][WIDTH+1]={
		"                    ",
		"                    ",
		"      1. 1000$      ", 
		"      2. 3000$      ",
		"      3. 5000$      ",
		"                    ",
		"                    ",
		"                    ",
		"   0.��^           ",
		"                    "
	};
	PrintGraphic(graphic);
	int input;
	while(true){
		input=_getch()-'0';
		if(input==1) return get1000;
		if(input==2) return get3000;
		if(input==3) return get5000;
		if(input==0) return goSlt;
	}
}
int state_balance(void){
	ClearGraphic2();
	char graphic[HEIGHT][WIDTH+1]={
		"                    ",
		"                    ",
		"                    ", 
		"     			     ",
		"                    ",
		"                    ",
		"                    ",
		"                    ",
		"     1.�~��         ",
		"     2.�h�d         "
		
	};
	sprintf(graphic[3], "  �l�B:%7d      ", balance);
	PrintGraphic(graphic);
	int input;
	while(true){
		input=_getch()-'0';
		if(input==1) return goSlt;
		if(input==2) return retCard;
	}
}
int state_1000(void){
	balance-=1000;
	ClearGraphic();
	char graphic[HEIGHT][WIDTH+1]={
		"                    ",
		"                    ",
		"                    ", 
		"     �Ш��r1000$    ",
		"                    ",
		"                    ",
		"                    ",
		"  1.�h�d            ",
		"  2.��ܾl�B        ",
		"  0.��^            "
	};
	PrintGraphic(graphic);
	int input;
	while(true){
		input=_getch()-'0';
		if(input==1) return retCard;
		if(input==2) return inquiry;
		if(input==0) return goSlt;
	}
}
int state_3000(void){
	balance-=3000;
	ClearGraphic();
	char graphic[HEIGHT][WIDTH+1]={
		"                    ",
		"                    ",
		"                    ", 
		"     �Ш��r3000$    ",
		"                    ",
		"                    ",
		"                    ",
		"  1.�h�d            ",
		"  2.��ܾl�B        ",
		"  0.��^            "
	};
	PrintGraphic(graphic);
	int input;
	while(true){
		input=_getch()-'0';
		if(input==1) return retCard;
		if(input==2) return inquiry;
		if(input==0) return goSlt;
	}
}
int state_5000(void){
	balance-=5000;
	ClearGraphic();
	char graphic[HEIGHT][WIDTH+1]={
		"                    ",
		"                    ",
		"                    ", 
		"     �Ш��r5000$    ",
		"                    ",
		"                    ",
		"                    ",
		"  1.�h�d            ",
		"  2.��ܾl�B        ",
		"  0.��^            "
	};
	PrintGraphic(graphic);
	int input;
	while(true){
		input=_getch()-'0';
		if(input==1) return retCard;
		if(input==2) return inquiry;
		if(input==0) return goSlt;
	}
}
int errcnt=0;
int state_errorPwd(void){
	ClearGraphic();
	char graphic[HEIGHT][WIDTH+1]={
		"                    ",
		"                    ",
		"                    ", 
		"      �K�X���~�I    ",
		"                    ",
		"                    ",
		"                    ",
		"                    ",
		"                    ",
		"                    "
		
	};
	PrintGraphic(graphic);
	Sleep(2000);
	errcnt++;
	if(errcnt==3) 
		return lock;
	return goEnterPwd;
	
}
int state_locked(void){
	ClearGraphic();
	char graphic[HEIGHT][WIDTH+1]={
		"                    ",
		"                    ",
		"                    ", 
		"      �w��w�b��    ",
		"                    ",
		"                    ",
		"                    ",
		"                    ",
		"                    ",
		"                    "
		
	};
	PrintGraphic(graphic);
	Sleep(2000);
	return endProgram;
}
int state_end(void){
	
}
int state_retCard(void){
	ClearGraphic();
	char graphic[HEIGHT][WIDTH+1]={
		"                    ",
		"                    ",
		"                    ", 
		"     �d���w�h�X     ",
		"     �еy�ᴡ�d     ",
		"                    ",
		"                    ",
		"                    ",
		"                    ",
		"                    "
		
	};
	PrintGraphic(graphic);
	Sleep(2000);
	return goMenu;
}

int (*state[])(void)={
	state_insertCard,
	state_enterPwd,
	state_sltFnct,
	state_withdraw,
	state_1000,
	state_3000,
	state_5000,
	state_balance,
	state_errorPwd,
	state_locked,
	state_retCard,
	state_end
};

//int input;

int main(){
	
	enum state_codes curState;
	enum ret_codes rc;
	
	int cur=state_insertCard();
	
	while(true){
		
		cur=state[cur]();
		if(cur==11) break;
		
	}
	
	
	
	return 0;
} 
