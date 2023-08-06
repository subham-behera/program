#include<stdio.h>

void input(int [][3],int);
void display(int [][10],int,int);
void tomat(int [][3],int,int,int,int [][10]);

int main(){
	int a,b,c;
	printf("Enter the row of Matrix:");
	scanf("%d",&a);
	printf("Enter the column of matrix:");
	scanf("%d",&b);
	printf("Enter the total non-zero:");
	scanf("%d",&c);
	int arr[20][3];
	arr[0][0]=a;
	arr[0][1]=b;
	arr[0][2]=c;
	input(arr,c);
	int mat[a][b];
	tomat(arr,a,b,c,mat);
	printf("Sparsh Matrix:\n");
	display(mat,a,b);
	return 0;
}

void input(int a[][3],int r){
	a[r][3];
	int i,j;
	printf("Enter the input:\n");
	for(i=1;i<=r;i++){
		scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);	
	}
	printf("Triplet Matrix:\n");
	for(i=0;i<=r;i++){
		for(j=0;j<3;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}

void tomat(int a[][3],int r,int c,int n,int new[][10]){
	int i,j;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			new[i][j]=0;
		}
	}
	for(i=1;i<=n;i++){
		new[a[i][0]][a[i][1]]=a[i][2];
	}
}

void display(int a[][10],int r,int c){
	int i,j;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){	
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}
