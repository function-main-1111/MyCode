#include<stdio.h>
#include<time.h>
#include<stdlib.h>


void QuickSort(int arr[], int n, int startId, int endId);
void Push(int vt[], int a);
int Pop(int vt[]);
void RandArrInRange(int arr[], int n, int mini, int maxi);
void PrintArrLine(int arr[], int n);

int main(){
	
	srand(time(NULL));
	
	int n;
	scanf("%d", &n);
	int arr[n];
	
	RandArrInRange(arr, n, 1, 100);
	PrintArrLine(arr, n);
	QuickSort(arr, n, 0, n-1);
	PrintArrLine(arr, n);
	
	
	return 0;
}

void QuickSort(int arr[], int n, int startId, int endId){
	
	if(startId>=endId){
		return;
	}
	
	int vt[1+endId-startId+1];
	//vt[0]代表vector有幾個值，index從1開始 
	vt[0]=0;//目前0個值 
	//基準值 
	int pivotId=startId+rand()%(endId-startId+1);
	
	//先把小的push進vt 
	int cntNewPivotId=startId;
	for(int i=startId; i<=endId; i++){
		//跳過基準值本身 
		if(i==pivotId){
			continue;
		}
		
		if(arr[i]<=arr[pivotId]){
			Push(vt, arr[i]);
			cntNewPivotId++;
		}
	}
	
	//把基準值push進vt
	Push(vt, arr[pivotId]);
	
	//把大的push進vt 
	for(int i=startId; i<=endId; i++){
		//跳過基準值本身 
		if(i==pivotId){
			continue;
		}
		
		if(arr[pivotId]<arr[i]){
			Push(vt, arr[i]);
		}
	}
	
	//vt pop填入arr 
	for(int i=endId; i>=startId; i--){
		arr[i]=Pop(vt);
	}
	
	//new pivot前後再各自排序
	//排序小於基準值區塊
	QuickSort(arr, n, startId, cntNewPivotId-1);
	//排序大於基準值區塊
	QuickSort(arr, n, cntNewPivotId+1, endId);
	
	
}

void Push(int vt[], int a){
	vt[0]++;
	vt[vt[0]]=a;
}
int Pop(int vt[]){
	vt[0]--;
	return vt[vt[0]+1];
}

void RandArrInRange(int arr[], int n, int mini, int maxi){
	for(int i=0; i<n; i++){
		arr[i]=mini+rand()%(maxi-mini+1);
	}
}

void PrintArrLine(int arr[], int n){
	for(int i=0; i<n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}
