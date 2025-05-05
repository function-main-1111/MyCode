#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<math.h>
#define MAX 60

char graphic[MAX][MAX];
char ghDefaul[MAX][MAX];
int ax=MAX/6, bx=MAX/2, cx=5*MAX/6;
int avt[10], bvt[10], cvt[10];
float delateSec=0.05;
int n;

void draw();

int pop(int v[]){
	int rt=v[v[0]];
	v[0]--;
	return rt;
}
void push(int v[], int n){
	v[0]++;
	v[v[0]]=n;
}

void clear_screen_smooth() {
    printf("\033[H"); // 將游標移到左上角
}

void hanoi(int n, int from[], int to[], int other[]){
	
	if(n==1){
		
		//printf("環%d從%c放到%c\n", n, from, to);
		push(to, pop(from));
		draw();
		usleep(delateSec*1000000);
		
		
		return;
	}
	hanoi(n-1, from, other, to);
	//printf(
	//"環%d從%c放到%c\n", n, from, to);
	
	push(to, pop(from));
	draw();
	usleep(delateSec*1000000);
	hanoi(n-1, other, to, from);
	
	return;
}

void draw(){
	
	memcpy(graphic, ghDefaul, sizeof(graphic));
	
	for(int i=1;i<=avt[0];i++){
		for(int j=0;j<avt[i]*2-1;j++){
			graphic[MAX-2-i][ax-avt[i]+1+j]='=';
		}
	}
	for(int i=1;i<=bvt[0];i++){
		for(int j=0;j<bvt[i]*2-1;j++){
			graphic[MAX-2-i][bx-bvt[i]+1+j]='=';
		}
	}
	for(int i=1;i<=cvt[0];i++){
		for(int j=0;j<cvt[i]*2-1;j++){
			graphic[MAX-2-i][cx-cvt[i]+1+j]='=';
		}
	}
	clear_screen_smooth();
	
	for(int i=MAX-17;i<MAX;i++){
		for(int j=0;j<MAX;j++){
			printf("%1c", graphic[i][j]);
		}
		printf("\n");
	}
	
}

void init(){
	avt[0]=bvt[0]=cvt[0]=0;
	char a[MAX];
	for(int i=0;i<MAX;i++){
		a[i]=' ';
	}
	for(int i=0;i<MAX;i++){
		strcpy(ghDefaul[i], a);
	}
	ghDefaul[MAX-1][ax]='A';
	ghDefaul[MAX-1][bx]='B';
	ghDefaul[MAX-1][cx]='C';
	for(int i=0;i<MAX;i++){
		ghDefaul[MAX-2][i]='-';
	}
	for(int i=0;i<n+1;i++){
		ghDefaul[MAX-3-i][ax]='|';
		ghDefaul[MAX-3-i][bx]='|';
		ghDefaul[MAX-3-i][cx]='|';
	}
	
}

int main(){
		
	scanf("%d", &n);
	printf("預估時間%.2f秒\n", 2.5+delateSec*pow(2.0, n)-1.0 );
	init();
	sleep(2.5);
	for(int i=n;i>0;i--){
		push(avt, i);
	}
	//draw();
	
	hanoi(n, avt, cvt, bvt);
	
	
	return 0;
}
