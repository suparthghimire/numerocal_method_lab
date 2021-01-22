#include<iostream>
#include<iomanip>
#include<math.h>
// #include "trapazoial.h"
#define MAX 4

using namespace std;


float func(float x) {
    return x * x;
}
float trapazoial_composite(float h, int i, float a, float b) {
    int k = pow(2, i) + 1;
    float sum = func(a) + func(b);
    float temp_h = h;
    for (float i = a + temp_h;i < b;i += temp_h) {
        sum += 2 * func(i);
    }
    return sum * h * 0.5;
}


float romberg(float a, float b) {
    float hi[MAX];
    float h = (b - a);
    for (int i = 0;i < MAX;i++) {
        hi[i] = (h) / pow(2, i);
    }
    float I[MAX][MAX];
    for (int i = 0;i < MAX;i++) {
        for (int j = 0;j < MAX;j++) {
            if (j == 0) {
                I[i][j] = trapazoial_composite(hi[i], i, a, b);
            }
        }
    }
    for (int i = 1;i < MAX;i++) {
        for (int j = 0;j < MAX - i;j++) {
            I[j][i] = (I[j + 1][i - 1]) + ((float)1 / 3) * (I[j + 1][i - 1] - I[j][i - 1]);
        }
    }

    return I[0][MAX - 1];
}


int main() {
    system("cls");
    float a = 0;
    float b = 8;
    cout << " " << b << endl;
    cout << "|f(x)dx=" << romberg(a, b) << endl;
    cout << " " << a;
}