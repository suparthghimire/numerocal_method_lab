#include<iostream>
#include<math.h>
#define k 4
using namespace std;


float func(float x) {
    return x * x * x + 2;
}

float trapazoial_composite(float a, float b) {
    float h = (b - a) / k;
    float temp_h = h;
    float f[k];
    int j = 0;
    for (float i = a;i <= b;i = i + temp_h) {
        f[j++] = func(i);
    }

    float sum = 0;
    for (int i = 1;i < k;i++) {
        sum += 2 * f[i];
    }

    sum += f[0] + f[k];
    return sum * h * 0.5;
}

int main() {
    system("cls");
    float a = 2;
    float b = 8;
    cout << "|f(x)dx = " << trapazoial_composite(a, b) << endl;
}