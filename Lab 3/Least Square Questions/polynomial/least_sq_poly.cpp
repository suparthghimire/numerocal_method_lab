#include<iostream>
#include<math.h>
#include<iomanip>
#include "inverse.h"
#define MAX_VAL 4
using namespace std;

int index(int i, int j) {
    return i * MAX_VAL + j;
}
void poly_func(float x[], float y[]) {

    float X_Coeff[MAX_VAL];
    float Y_Coeff[MAX_VAL];

    int count = 0;
    for (int i = 1;i <= MAX_VAL;i++) {
        float sumCurr = 0;
        for (int j = 0;j < MAX_VAL;j++) {
            sumCurr += pow(x[j], i);
        }
        X_Coeff[count++] = sumCurr;
    }

    count = 0;
    for (int i = 0;i < MAX_VAL;i++) {
        float sumCurr = 0;
        for (int j = 0;j < MAX_VAL;j++) {
            sumCurr += pow(x[j], i) * y[j];
        }
        Y_Coeff[count++] = sumCurr;
    }

    float eqnMatrix[MAX_VAL - 1][MAX_VAL - 1];
    eqnMatrix[0][0] = MAX_VAL;
    for (int i = 0;i < MAX_VAL - 1;i++) {
        for (int j = 0;j < MAX_VAL - 1;j++) {
            if (index(i, j) != 0) {
                eqnMatrix[i][j] = X_Coeff[i + j - 1];
            }
        }
    }
    
    
    
   
    float valMatrix[MAX_VAL - 1][MAX_VAL - 1];
    for (int i = 0; i < MAX_VAL - 1; i++) {
        for (int j = 0;j < MAX_VAL - 1;j++) {
            if (j == 0) {
                valMatrix[i][j] = Y_Coeff[i];
            }
            else {
                valMatrix[i][j] = 0;
            }
        }
    }
    
    
     for(int i=0;i<MAX_VAL-1;i++){
    	for(int j=0;j<MAX_VAL-1;j++){
    		cout<<valMatrix[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl<<endl;

    
    cout << "Fitted Equation" << endl;
    cout << "y = ";
    for (int i = MAX_VAL - 2;i >= 0;i--) {
        if (i == 0) {
            cout << inverse(eqnMatrix, valMatrix).a[i];
        }
        else {
            cout << inverse(eqnMatrix, valMatrix).a[i] << " * x ^ " << i << " + ";
        }
    }
}

int main() {
    system("CLS");
    float x[MAX_VAL] = { 2,4,6,8 };
    float y[MAX_VAL] = { 1.4,2.0,2.4,2.6 };
    poly_func(x, y);
}
