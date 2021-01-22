#include<iostream>
#include<math.h>
#define k 3
using namespace std;


float func(float x) {
    return exp(x / 2);
}

float simpson_three_eight(float a, float b) {
    float h = (b - a) / k;
    float temp_h = h;
    float sum = func(a) + func(b);
    for (float i = a + temp_h;i < b;i += temp_h) {
        sum += 3 * func(i);
    }
    return ((3 * h) / 8) * sum;
}

int main() {
    system("cls");
    float a = 1;
    float b = 5;
    cout << "|f(x)dx = " << simpson_three_eight(a, b) << endl;
}