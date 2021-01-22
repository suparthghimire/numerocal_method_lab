#include<iostream>
#include<math.h>
#define MAX 5
using namespace std;
float calcX(float xn[], float x, int i) {
    float temp = 1;
    for (int j = 0;j < i;j++) {
        temp = temp * (x - xn[j]);
    }
    return temp;
}

float newton_central(float xn[], float fxn[][MAX], float x) {
    for (int i = 1;i < MAX;i++) {
        for (int j = 0;j < MAX - i;j++) {
            fxn[j][i] = (fxn[j + 1][i - 1] - fxn[j][i - 1]) / (xn[i + j] - xn[j]);
        }
    }
    float sum = fxn[0][0];
    for (int i = 1;i < MAX;i++) {
        sum += calcX(xn, x, i) * fxn[0][i];
    }
    return sum;
}

float first_der(float x[MAX], float fx[MAX][MAX], float xi) {

    float dx = 0.001;
    float func_sum_val = newton_central(x, fx, xi + dx);
    float func_sum_diff = newton_central(x, fx, xi - dx);
    return (func_sum_val - func_sum_diff) / ((float)2 * dx);

}

int main() {
    system("cls");
    float x[MAX] = { 1,2,3,4,5 };
    float fx[MAX][MAX];
    fx[0][0] = sin(1);
    fx[1][0] = sin(2);
    fx[2][0] = sin(3);
    fx[3][0] = sin(4);
    fx[4][0] = sin(5);

    cout << "derivative: " << first_der(x, fx, 3);
}
