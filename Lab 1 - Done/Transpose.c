#include<stdio.h>
#include<conio.h>



void transpose(int a[10][10],int r,int c){
	int temp[10][10];
	int i,j;
	
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			temp[j][i] = a[i][j];
		}
	}
	
	
	printf("Transpose of matrix: \n");
	for(i=0;i<c;i++){
		printf("|");
		for(j=0;j<r;j++){
			printf(" %d ",temp[i][j]);
		}
		printf("|\n");
	}
	
}

int main(){
	int mat[10][10];
	int r,c;
	
	printf("Rows: ");
	scanf("%d",&r);
	printf("Cols: ");
	scanf("%d",&c);
	
	int i,j;
	printf("Enter elements in %d x %d matrix:\n",r,c);

	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			scanf("%d",&mat[i][j]);	
		}
	}

		transpose(mat,r,c);
	
	return 0;


}
