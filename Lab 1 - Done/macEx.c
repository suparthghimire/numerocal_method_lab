#include<stdio.h>
#include<conio.h>
#include<unistd.h>

double powera(int x,int n){
	if(n==0)
		return 1;
	else
		return x*powera(x,n-1);
}
double fact(int n){
	if(n>=1)
		return n*fact(n-1);
	else
		return 1;
}



double macEx(int power,int depth){
	double sum=0;
	double temp;
	while(1){
		int i;
			
		for(i=1;i<=depth;i++){
			sum += (double)powera(power,i)/fact(i);
		}
		
		depth++;
		
		if (temp == sum){
			break;
		}
		
		temp = sum;
		sum = 0;
		sleep(0.5);
	}
	return temp+1;
}
int main(){
	int depth = 1;
	int power = 2;

//		printf("\nEnter power: ");
//		scanf("%d",&power);
		
		printf("The Value of e^%d is %lf",power,macEx(power,depth));
	
}



