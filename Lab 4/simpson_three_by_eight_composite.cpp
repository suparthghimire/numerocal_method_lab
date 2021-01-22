#include<iostream>
#include<iomanip>
#include<math.h>
#define k 12
using namespace std;


float func(float x) {
    return sin(x / 2);
}

float simpson_three_eight_composite(float a, float b) {
    float h = (b - a) / k;

    float temp_h = h;
    float sum = func(a) + func(b);
    int j = 0;
    for (float i = a + temp_h;i < b;i += temp_h) {
        if (j % 3 != 0) sum += 3 * func(i);
        else sum += 2 * func(i);
        j++;
    }

    return ((3 * h) / 8) * sum;
}

int main() {
    system("cls");
    float a = 1;
    float b = 2;
    cout << "|f(x)dx = " << simpson_three_eight_composite(a, b) << endl;
}