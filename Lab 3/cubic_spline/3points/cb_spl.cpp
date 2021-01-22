#include<iostream>
#include<math.h>
#include<time.h>
#define MAX 3
using namespace std;

float cb_spl(float x[], float fx[], float xi) {
    float h[MAX];
    h[0] = 0;
    int count = 1;
    for (int i = 0;i < MAX - 1;i++) {
        h[count++] = x[i + 1] - x[i];
    }
    float a = (6 / (2 * (h[1] + h[2]))) * (((fx[2] - fx[1]) / (h[2])) - ((fx[1] - fx[0]) / (h[1])));


    float range[2];
    int itCount = 0;
    for (int i = 0;i < MAX;i++) {
        if (x[i] <= xi && x[i] <= x[i + 1]) {
            range[0] = x[0];
            range[1] = x[1];
            itCount++;
        }
    }

    float u[MAX - 1];
    for (int i = 0;i < MAX - 1;i++) {
        u[i] = xi - range[i];
    }

    float left = ((a / (6 * h[itCount])) * ((pow(u[itCount - 1], 3)) - (pow(h[itCount], 2) * u[itCount - 1])));
    float right = (1 / h[itCount]) * ((fx[itCount] * u[itCount - 1]) - (fx[itCount - 1] * u[itCount]));




    return left + right;
}

int main() {
    system("CLS");
    float xn[MAX] = { 4,9,16 };
    float fxn[MAX] = { 2,3,4 };

    float x = 7;

    cout << endl << "S(" << x << ") = " << cb_spl(xn, fxn, x);
}
