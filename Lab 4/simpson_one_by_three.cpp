#include<iostream>
#include<math.h>
using namespace std;


float func(float x) {
    return x * x * x + 2;
}

float simpson_1_by_3(float a, float b) {
    float h = (b - a) / 2;
    float temp_h = h;
    float f[3];
    int j = 0;
    for (float i = a;i <= b;i = i + temp_h) {
        f[j++] = func(i);
    }
    float sum = f[0] + f[2];
    sum += 4 * f[1];

    return (h / 3) * sum;


}

int main() {
    system("cls");
    float a = 2;
    float b = 8;
    cout << "|f(x)dx = " << simpson_1_by_3(a, b) << endl;
}