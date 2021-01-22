#include<iostream>
#include<math.h>
#define MAX 10
using namespace std;
float larange(float xn[], float fxn[], float x) {
    float result = 0;
    float lSum = 1;
    for (int i = 0;i < MAX;i++) {
        for (int j = 0;j < MAX;j++) {
            if (i != j) {
                lSum *= (x - xn[j]) / (xn[i] - xn[j]);
            }
        }
        result += fxn[i] * lSum;
        lSum = 1;
    }
    return result;
}
int main() {
    system("cls");
    // /    float xn[MAX] = { 4,9,16 };
    float xn[MAX] = { 1,2,3,4,5,6,7,8,9,10 };

    float fxn[MAX] = { exp(2 * 1),exp(2 * 2),exp(2 * 3),exp(2 * 4),exp(2 * 5),exp(2 * 6),exp(2 * 7),exp(2 * 8),exp(2 * 9),exp(2 * 10) };
    float x = 3.01;
    cout << larange(xn, fxn, x);

}