#include<iostream>
#include<math.h>
#define k 4
using namespace std;


float func(float x) {
    return exp(x / 2);
}

float simpson_one_three_composite(float a, float b) {
    float h = (b - a) / k;
    float temp_h = h;
    float f[k];
    int j = 0;
    for (float i = a;i <= b;i = i + temp_h) {
        f[j++] = func(i);
    }
    float sum = f[0] + f[k];

    for (int i = 1;i < k;i++) {
        if (i % 2 != 0) sum += 4 * f[i];
        else sum += 2 * f[i];
    }
    return (h / 3) * sum;
}

int main() {
    system("cls");
    float a = 1;
    float b = 5;
    cout << "|f(x)dx = " << simpson_one_three_composite(a, b) << endl;
}