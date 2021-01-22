#include<iostream>
#include<math.h>
#include<iomanip>
#define MAX 4
using namespace std;

float calcX(float xn[], float x, int i) {
    float temp = 1;
    for (int j = 0;j < i;j++) {
        temp = (float)temp * ((float)x - (float)xn[j]);
    }
    return (float)temp;
}

float newton_central(float xn[], float fxn[][MAX], float x) {
    for (int i = 1;i < MAX;i++) {
        for (int j = 0;j < MAX - i;j++) {
            fxn[j][i] = ((float)fxn[j + 1][i - 1] - (float)fxn[j][i - 1]) / ((float)xn[i + j] - (float)xn[j]);
        }
    }
    float sum = fxn[0][0];
    for (int i = 1;i < MAX;i++) {
        sum += ((float)calcX(xn, x, i) * (float)fxn[0][i]);
    }
    return sum;
}

int main() {

    float xn[MAX] = { 1.2,1.3,1.4,1.5 };
    float fxn[MAX][MAX];
    fxn[0][0] = 1.063;
    fxn[1][0] = 1.091;
    fxn[2][0] = 1.119;
    fxn[3][0] = 1.145;

    float x = (1.35);
    cout << "Ans " << newton_central(xn, fxn, x);
}
