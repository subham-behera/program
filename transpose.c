#include<stdio.h>

void input(int [][10],int,int);
void createsparsh(int [][10],int,int,int [][3]);
void display(int [][3],int);
void transpose(int [][3],int [][3],int);

static int cou=1;
int main(){
	int a,b;
	printf("Enter the size of Matrix:");
	scanf("%d%d",&a,&b);
	int arr[a][b];
	input(arr,a,b);
	int mat1[cou][3];
	createsparsh(arr,a,b,mat1);
	printf("Triplet Matrix:\n");
	display(mat1,cou);
	int mat2[cou][3];
	transpose(mat1,mat2,cou);
	printf("Transpose Matrix:\n");
	display(mat2,cou);
	return 0;
}

void input(int a[][10],int r,int c){
	int i,j;
	printf("Enter the input:\n");
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			printf("At %d%d:",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	printf("Sparsh Matrix:\n");
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			if(a[i][j]!=0){
				cou+=1;
			}
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}

void createsparsh(int a[][10],int r,int c,int sp[][3]){
	int i,j,k=1;
	a[r][c];
	sp[0][0]=r;
	sp[0][1]=c;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			if(a[i][j]!=0){
				sp[k][0]=i;
				sp[k][1]=j;
				sp[k][2]=a[i][j];
				k++;
			}
		}
	}
	sp[0][2]=k-1;
}

void display(int a[][3],int r){
	int i,j;
	for(i=0;i<r;i++){
		for(j=0;j<3;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}

void transpose(int a[][3],int b[][3],int c){
	int i,j,k,n;
	b[0][0]=a[0][1];
	b[0][1]=a[0][0];
	b[0][2]=a[0][2];
	k=1;
	n=a[0][2];
	for(i=0;i<a[0][1];i++){
		for(j=1;j<=n;j++){
			if(i==a[j][1]){
				b[k][0]=i;
				b[k][1]=a[j][0];
				b[k][2]=a[j][2];
				k++;
			}
		}
	}
}
