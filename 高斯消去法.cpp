#include<stdio.h> 
#include<string.h> 

void printMatrix(float m[3][4]){
	for(int i=0; i<3; i++){
		printf("[");
		for(int j=0; j<4; j++){
			printf("%4g", m[i][j]);
		}
		printf("]\n");
	}
}

void MatrixMulti(float a[3][3], float b[3][4], float c[3][4]){
	for(int i=0; i<3; i++){
		for(int j=0; j<4; j++){
			c[i][j]=0;
			for(int k=0; k<3; k++){
				c[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
}

void tryRowSwap(float m[3][4]){
	float cpy[3][4];
	memcpy(cpy, m, sizeof(float)*12);
	
	if(m[0][0]==0){
		if(m[1][0]!=0){
			float p12[3][3]={
						{0,1,0},
						{1,0,0},
						{0,0,1}
					};
			MatrixMulti(p12, cpy, m);
			memcpy(cpy, m, sizeof(float)*12);
		}
		else{
			float p13[3][3]={
						{0,0,1},
						{0,1,0},
						{1,0,0}
					};
			MatrixMulti(p13, cpy, m);
			memcpy(cpy, m, sizeof(float)*12);
		}
	}
	if(m[1][1]==0){
		float p23[3][3]={
						{1,0,0},
						{0,0,1},
						{0,1,0}
					};
		MatrixMulti(p23, cpy, m);
	}
}

int main(){
	
	float m[3][4], result[3][4], cpy[3][4], pivot;
	
	//块计
	 
	for(int i=0; i<3; i++){
		for(int j=0; j<4; j++){
			scanf("%f", &m[i][j]);
		}
	}
	printf("\n");
	for(int i=0; i<3; i++){
		printf("%gX+%gY+%gZ=%g\n", m[i][0], m[i][1], m[i][2], m[i][3]);
	}
	printf("\n");
	
	
	float identity[3][3]={
						{1,0,0},
						{0,1,0},
						{0,0,1}
					};
	
	memcpy(result, m, sizeof(m));
	printMatrix(result);printf("\n");
	
	
	//[pivot x x x]
	//[  x 	 x x x]
	//[  x 	 x x x]
	//璝pivot0, 玥ユ传 
	tryRowSwap(result);
	//printMatrix(result);printf("\n");
	pivot=result[0][0];
	memcpy(cpy, result, sizeof(result));
	
	//ノrow1ㄓrow2, row3
	float e21[3][3]={
						{1,					 0,0},
						{-result[1][0]/pivot,1,0},
						{0,					 0,1}
					};
	MatrixMulti(e21, result, cpy);
	float e31[3][3]={
						{1,					 0,0},
						{0,					 1,0},
						{-result[2][0]/pivot,0,1}
					};
	MatrixMulti(e31, cpy, result);
	memcpy(cpy, result, sizeof(result));
	//[x x x x]
	//[0 x x x]
	//[0 x x x]
	printMatrix(result);printf("\n");
	
	//[x   x	x x]
	//[0 pivot  x x]
	//[0 	    x x]
	//璝pivot0, 玥ユ传
	tryRowSwap(result);
	pivot=result[1][1];
	memcpy(cpy, result, sizeof(result));
	
	float e32[3][3]={
						{1,0,0},
						{0,1,0},
						{0,-result[2][1]/pivot,1}
					};
	MatrixMulti(e32, cpy, result);
	memcpy(cpy, result, sizeof(result));
	//[x x x x]
	//[0 x x x]
	//[0 0 x x]
	//à
	printMatrix(result);printf("\n");
	
	//[x x   x 	 x]
	//[0 x   x 	 x]
	//[0 0 pivot x]
	pivot=result[2][2];
	//scalar
	float s3[3][3]={
						{1,0,0},
						{0,1,0},
						{0,0,1/pivot}
					};
	MatrixMulti(s3, cpy, result);
	memcpy(cpy, result, sizeof(result));
	float e23[3][3]={
						{1,0,0},
						{0,1,-result[1][2]},
						{0,0,1}
					};
	MatrixMulti(e23, result, cpy);
	float e13[3][3]={
						{1,0,-result[0][2]},
						{0,1,0},
						{0,0,1}
					};
	MatrixMulti(e13, cpy, result);
	memcpy(cpy, result, sizeof(result));
	//[x x 0 x]
	//[0 x 0 x]
	//[0 0 1 x]
	printMatrix(result);printf("\n");
	
	//[x x 		0 x]
	//[0 pivot  0 x]
	//[0 0 		1 x]
	pivot=result[1][1];
	float s2[3][3]={
						{1,0,0},
						{0,1/pivot,0},
						{0,0,1}
					};
	MatrixMulti(s2, result, cpy);
	float e12[3][3]={
						{1,-result[0][1],0},
						{0,1,0},
						{0,0,1}
					};
	MatrixMulti(e12, cpy, result);
	memcpy(cpy, result, sizeof(result));
	//[x 0 0 x]
	//[0 1 0 x]
	//[0 0 1 x]
	printMatrix(result);printf("\n");
	
	//[pivot 0 0 x]
	//[0 	1 0 x]
	//[0 	0 1 x]
	pivot=result[0][0];
	float s1[3][3]={
						{1/pivot,0,0},
						{0,1,0},
						{0,0,1}
					};
	MatrixMulti(s1, cpy, result);
	memcpy(cpy, result, sizeof(result));
	//[1 0 0 x]
	//[0 1 0 x]
	//[0 0 1 x]
	//―秆Θ 
	printMatrix(result);printf("\n");
	
	printf("X=%g, Y=%g, Z=%g \n", result[0][3], result[1][3], result[2][3]);
	
	//代戈 
	// 0 1 4 -4 1 3 3 -2  3 7 5 6 
	// 19 -8 1
	
	//3 4 -2 1 2 -3 5 -4 5 2 3 9
	//-9 12 10
	
	//4 -2 5 12 -3 7 6 -5 2 8 -3 10
	//3.11017 0.516949 0.118644
	
	//2 1 -3  4  -1 2  5 -2  3  7  6 -1
 	//-3.5 3.5 -2.5
	
	//3 5 -7 1 8 -3 4 9 1 2 3 6
	//1 1 1
	
	//1 -2 3 9 -1 3 0 -4 2 -5 5 17
	//1 -1 2
	
	
	return 666;
}
