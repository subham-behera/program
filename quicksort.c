#include<stdio.h>

int partition(int a[],int lb,int ub){
	int i,j,pivot,temp;
	pivot=a[lb];
	i=lb;
	j=ub;
	while(i<j){
		while(a[i]<=pivot){
			i++;
		}
		while(a[j]>pivot){
			j--;
		}
		if(i<j){
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	temp=a[lb];
	a[lb]=a[j];
	a[j]=temp;
	return j;
}
void quicksort(int a[],int lb,int ub){
	int loc;
	if(lb<ub){
		loc=partition(a,lb,ub);
		quicksort(a,lb,loc-1);
		quicksort(a,loc+1,ub);
	}
}

int main(){
	int i,n,a[50];
	printf("Enter Size:");
	scanf("%d",&n);
	printf("Enter element:");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("Quicksort\n");
	quicksort(a,0,n-1);
	for(i=0;i<6;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
