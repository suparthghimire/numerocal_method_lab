#include<iostream>
#include<math.h>
#define MAX 6

using namespace std;

void non_linear(float x[], float y[]) {
    float sumX[2] = { 0,0 };
    float sumY[2] = { 0,0 };
    for (int i = 0;i < MAX;i++) {
        sumX[0] += x[i];
        sumX[1] += x[i] * x[i];
    }
    for (int i = 0;i < MAX;i++) {
        sumY[0] += log(y[i]);
        sumY[1] += x[i] * log(y[i]);
    }
    cout << sumX[0] << " " << sumX[1] << endl;
    cout << sumY[0] << " " << sumY[1] << endl;
    float b = ((MAX * sumY[1]) - (sumX[0] * sumY[0])) / ((MAX * sumX[1]) - ((sumX[0]) * (sumX[0])));
    float a = exp((sumY[0] / MAX) - b * (sumX[0] / MAX));
    cout << "Fitted Equation: " << endl << "y = " << a << "e^(" << b << "x)" << endl;
}

int main() {
    float x[MAX] = { 0,1,3,5,7,9 };
    float y[MAX] = { 1,0.891,0.708,0.562,0.447,0.355 };
    non_linear(x, y);
}

