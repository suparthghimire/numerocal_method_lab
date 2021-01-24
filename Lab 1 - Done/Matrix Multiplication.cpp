#include<stdio.h>
#include<conio.h>


void matrixMul(int a[10][10],int b[10][10],int r1,int c1,int r2,int c2){
	int c[10][10];
	int i,j,k;
	
	for(i=0;i<r1;i++){
		for(j=0;j<c2;j++){
			c[i][j] = 0;
			for(k=0;k<c1;k++){
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	
	
	printf("\nThe Product is: \n");
	for(i=0;i<r1;i++){
		printf("|");
		for(j=0;j<c2;j++){
			printf(" %d ",c[i][j]);
		}
		printf("|\n");
	}
}



int main(){
	int mat1[10][10];
	int mat2[10][10];
	int r1,c1;
	int r2,c2;
	
	printf("For matrix 1\nRows: ");
	scanf("%d",&r1);
	printf("Cols: ");
	scanf("%d",&c1);
	
	printf("For matrix 2\nRows: ");
	scanf("%d",&r2);
	printf("Cols: ");
	scanf("%d",&c2);
	
	while(c1!=r2){
		printf("Row and Columns in correct. Re-enter Values \n");
		printf("For matrix 1\nRows: ");
		scanf("%d",&r1);
		printf("Cols: ");
		scanf("%d",&c1);
	
		printf("For matrix 2\nRows: ");
		scanf("%d",&r2);
		printf("Cols: ");
		scanf("%d",&c2);
	}
	
	int i,j;
	printf("Enter elements in %d x %d matrix:\n",r1,c1);

	for(i=0;i<r1;i++){
		for(j=0;j<c1;j++){
			scanf("%d",&mat1[i][j]);	
		}
	}



	printf("Enter elements in %d x %d matrix:\n",r2,c2);

	for(i=0;i<r2;i++){
		for(j=0;j<c2;j++){
			scanf("%d",&mat2[i][j]);	
		}
	}

	
		matrixMul(mat1,mat2,r1,c1,r2,c2);
	
	return 0;
}
