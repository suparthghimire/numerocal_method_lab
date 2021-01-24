#include<stdio.h>
#include<conio.h>
#include<math.h>


int checkDet(int mat[][100],int row){
	int det=0;
	int sub[100][100];
	int i,j,x;

	if (row == 2)
		return mat[0][0]*mat[1][1] - mat[0][1]*mat[1][0];
	else{		
		for(x=0;x<row;x++){
			int subR = 0;
			for(i=1;i<row;i++){
				int subC = 0;
				for(j=0;j<row;j++){
					if(j==x)
						continue;
						sub[subR][subC] = mat[i][j]; 
						subC++;
				}
				subR++;
			}
			det = det + (pow(-1,x) * mat[0][x] * checkDet(sub,row-1));
		}  
	}
	return det;
}

void rev(int mat[][100],int row){
	
}


int main(){
	int a[100][100];
	int row;
	
	int i,j;
	printf("Enter Row of matrix: ");
	scanf("%d",&row);
	printf("Enter %dx%d matrix\n",row,row);
	for(i=0;i<row;i++)
		for(j=0;j<row;j++)
			scanf("%d",&a[i][j]);
	
	int det = checkDet(a,row);
	printf("Det A = %d",det);
	if(det==0){
		printf("\nInverse is not possible for det(A)=0.");
	}
//	revMat(/mat,row);
	

	
}
