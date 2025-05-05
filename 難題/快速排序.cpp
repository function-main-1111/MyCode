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
	//vt[0]�N��vector���X�ӭȡAindex�q1�}�l 
	vt[0]=0;//�ثe0�ӭ� 
	//��ǭ� 
	int pivotId=startId+rand()%(endId-startId+1);
	
	//����p��push�ivt 
	int cntNewPivotId=startId;
	for(int i=startId; i<=endId; i++){
		//���L��ǭȥ��� 
		if(i==pivotId){
			continue;
		}
		
		if(arr[i]<=arr[pivotId]){
			Push(vt, arr[i]);
			cntNewPivotId++;
		}
	}
	
	//���ǭ�push�ivt
	Push(vt, arr[pivotId]);
	
	//��j��push�ivt 
	for(int i=startId; i<=endId; i++){
		//���L��ǭȥ��� 
		if(i==pivotId){
			continue;
		}
		
		if(arr[pivotId]<arr[i]){
			Push(vt, arr[i]);
		}
	}
	
	//vt pop��Jarr 
	for(int i=endId; i>=startId; i--){
		arr[i]=Pop(vt);
	}
	
	//new pivot�e��A�U�۱Ƨ�
	//�ƧǤp���ǭȰ϶�
	QuickSort(arr, n, startId, cntNewPivotId-1);
	//�ƧǤj���ǭȰ϶�
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
