#include <stdio.h>
#include<math.h>

#define PI 3.1415

long fact(int n){
	if(n>=1)
		return n*fact(n-1);
	else
		return 1;
}

float degToRad(int deg){
	return (deg * PI)/180;
}
float macSerSin(int deg,float accuracy){
	float x,term,nume,deno,sum = 0;
	x = degToRad(deg);
	nume = x;
	deno = 1;
	int i = 1;
	do{
		term = nume/deno;//always in form of p/q
		nume = (-1)*nume*pow(x,2);
		deno =fact(i+2);
		sum+=term;
		i+=2;
	}while(fabs(term)>accuracy);
	return sum;
}

int main(){
	int deg;
	float acc;
	printf("Enter Degree: ");
	scanf("%d",&deg);
	printf("Enter decimal Accuracy (ex 0.01 accuracy checks for 1 digit decimal accuracy): ");
	scanf("%f",&acc);
	while(acc<0||acc>=1){
		printf("\n\nAccuracy must be between 0 and 1\n");
		printf("Enter decimal Accuracy (ex 0.01 accuracy checks for 1 digit decimal accuracy): ");
		scanf("%f",&acc);
	}
	printf("\n\nSine of %d is %0.3f",deg,macSerSin(deg,acc));
	
}
