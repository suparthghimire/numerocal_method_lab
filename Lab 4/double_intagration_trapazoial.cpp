#include<iostream>
#include<iomanip>
#include<math.h>
#define n 2
#define m 2
using namespace std;

float func(float x, float y) {
    return x + y;
}
float trapazoial(float a, float b, float c, float d) {
    float h = (b - a) / n, k = (d - c) / m;
    float temp_h = h, temp_k = k;

    float x_val[n + 1], y_val[m + 1];
    int count = 0;
    for (float i = a;i <= b;i += temp_h)
        x_val[count++] = i;

    count = 0;
    for (float i = c;i <= d;i += temp_k)
        y_val[count++] = i;


    float function_table[n + 1][m + 1];
    for (int i = 0;i < n + 1;i++)
        for (int j = 0;j < m + 1;j++)
            function_table[i][j] = func(x_val[i], y_val[j]);

    float sum = 0;
    for (int i = 0;i < n;i++)
        for (int j = 0;j < m;j++)
            sum += function_table[i][j] + function_table[i][j + 1] + function_table[i + 1][j + 1] + function_table[i + 1][j];
    return ((h * k) / (float)4) * sum;
}

int main() {
    system("cls");
    float a = 1, b = 3, c = 0, d = 2;
    cout << "   | | f(x,y)dxdy = " << trapazoial(a, b, c, d) << endl;
}
