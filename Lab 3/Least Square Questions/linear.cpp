#include<iostream>
#include<math.h>
#define MAX 8
using namespace std;


void linear(float x[], float y[]) {
    float sumX[2] = { 0,0 };
    float sumY[2] = { 0,0 };
    for (int i = 0;i < MAX;i++) {
        sumX[0] += x[i];
        sumX[1] += x[i] * x[i];
    }
    for (int i = 0;i < MAX;i++) {
        sumY[0] += y[i];
        sumY[1] += y[i] * x[i];
    }

    float b = ((MAX * sumY[1]) - (sumX[0] * sumY[0])) / ((MAX * sumX[1]) - ((sumX[0]) * (sumX[0])));
    float a = ((sumY[0] / MAX) - b * (sumX[0] / MAX));

    cout << "Fitted Equation: " << endl << "y = " << a << " + " << b << "x" << endl;
    float x_temp = 140;
    cout << endl << "Estimation: " << a + b * x_temp;
}

int main() {
    float x[MAX] = { 175,165,160,180,150,170,155,185 };
    float y[MAX] = { 68,58,59,71,51,62,53,68 };
    linear(x, y);
}