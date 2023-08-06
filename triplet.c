#include<stdio.h>

void input(int [][10],int,int);
void createsparsh(int [][10],int,int,int [][3]);
void display(int [][3],int);
static int cou=1;
int main(){
	int a,b;
	printf("Enter the size of Matrix:");
	scanf("%d%d",&a,&b);
	int arr[a][b];
	input(arr,a,b);
	int mat[cou][3];
	createsparsh(arr,a,b,mat);
	display(mat,cou);
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
	printf("Triplet Matrix:\n");
	int i,j;
	for(i=0;i<r;i++){
		for(j=0;j<3;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}

