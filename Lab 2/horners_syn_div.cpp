#include <iostream>
#define MAX 5
using namespace std;


void horners(float fx[], float x) {
    float finalArr[MAX];
    finalArr[0] = fx[0];

    for (int i = 1;i < MAX;i++) {
        finalArr[i] = finalArr[i - 1] * x + fx[i];
    }

    cout << "Quotient: ";
    int j = MAX - 2;
    for (int i = 0;i < MAX - 1;i++) {
        if (i != MAX - 2) {
            cout << finalArr[i] << "x^" << j;
            if (finalArr[i + 1] > 0) cout << " + ";
            else cout << " ";
            j--;
        }
        else cout << finalArr[i];
    }
    cout << endl << "Remainder: " << finalArr[MAX - 1] << endl;

}

int main() {
    float fx[MAX] = { 1,0,2,-16, 5 };
    float x = 2;

    horners(fx, x);

}
