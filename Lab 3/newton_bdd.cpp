#include<iostream>
#include<iomanip>
#define MAX 4
using namespace std;


float calcS(float s, float n) {
    float temp = s;
    for (int i = 1; i < n; i++)
        temp = temp * (s + i);
    return temp;
}
int fact(int n) {
    if (n <= 0)return 1;
    return n * fact(n - 1);
}
float newton_backward_dIff(float xn[], float fxn[][MAX], float x) {
    for (int i = 1; i < MAX; i++)
        for (int j = MAX - 1; j >= i; j--)
            fxn[j][i] = fxn[j][i - 1] - fxn[j - 1][i - 1];

    float p = fxn[MAX - 1][0];
    float s = (x - xn[MAX - 1]) / (xn[1] - xn[0]);
    for (int i = 1;i < MAX;i++)
        p += (calcS(s, (float)i) * fxn[MAX - 1][i]) / fact(i);
    return p;
}

int main() {
    system("CLS");
    float xn[MAX] = { 0.3,0.5,0.7,0.9 };
    float fxn[MAX][MAX];


    fxn[0][0] = 0.067;
    fxn[1][0] = 0.148;
    fxn[2][0] = 0.248;
    fxn[3][0] = 0.370;
    

    float ans = newton_forward_dIff(xn, fxn, 0.6);
    cout << endl << "Function: " << ans;
}
