#include<iostream>
#include<math.h>
#define MAX 4
using namespace std;

float cb_spl(float x[], float fx[], float xi) {
    float h[MAX];
    h[0] = 0;
    int count = 1;
    for (int i = 0;i < MAX - 1;i++) {
        h[count++] = x[i + 1] - x[i];
    }


    float range[2];
    int itCount = 0;
    for (int i = 0;i < MAX;i++) {
        if (x[i] <= xi && x[i] <= x[i + 1]) {
            range[0] = x[0];
            range[1] = x[1];
            itCount++;
        }
    }

    cout << itCount << endl;
    float u[MAX - 1];
    for (int i = 0;i < MAX - 1;i++) {
        u[i] = xi - range[i];
    }


    return left + right;
}

int main() {
    system("CLS");
    float xn[MAX] = { 4,9,16,25 };
    float fxn[MAX] = { 2,3,4,5 };

    float x = 7;

    cout << endl << "S(" << x << ") = " << cb_spl(xn, fxn, x);
}
