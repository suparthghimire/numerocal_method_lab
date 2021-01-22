#include<iostream>
#include "inverse.h"

#define MAX_VAL 4

using namespace std;

float cb_spl(float x[], float fx[], float xi) {
    float h[MAX_VAL];
    h[0] = 0;
    int count = 1;
    for (int i = 0;i < MAX_VAL - 1;i++) {
        h[count++] = x[i + 1] - x[i];
    }
    for (int i = 0;i < MAX_VAL;i++) {
        cout << h[i] << " " << endl;
    }

    float calc_f[MAX_VAL];
    count = 0;
    for (int i = 1;i < MAX;i++)
        calc_f[count++] = 6 * (((fx[i + 1] - fx[i]) / h[i + 1]) - ((fx[i] - fx[i - 1]) / h[i]));


    float h_mat[MAX_VAL - 1][MAX_VAL - 1];

    for (int i = 0;i < MAX_VAL - 1;i++) {
        for (int j = 0;j < MAX_VAL - 1;j++) {
            if (i == MAX_VAL - 2) h_mat[i][j] = 1;
            else {
                if (j == 0) h_mat[i][j] = h[i];
                else if (j == 1) h_mat[i][j] = 2 * (h[i] + h[i + 1]);
                else if (j == 2) h_mat[i][j] = h[i + 1];
            }
        }
    }
    float f_mat[MAX_VAL - 1][MAX_VAL - 1];
    for (int i = 0;i < MAX_VAL - 1;i++) {
        for (int j = 0;j < MAX_VAL - 1;j++) {
            if (i == MAX_VAL - 2) f_mat[i][j] = 1;

            else if (j == 0) {
                f_mat[i][j] = calc_f[i + j];
            }
            else f_mat[i][j] = 1;
        }
    }


    // for (int i = 0;i < MAX_VAL - 1;i++) {
    inverse(h_mat, f_mat);
    // }


    float u[MAX];
    for (int i = 0;i < MAX_VAL;i++) u[i] = xi - x[i];

    return 1;
}

int main() {
    system("CLS");
    float xn[MAX_VAL] = { 7,9,12,14 };
    float fxn[MAX_VAL] = { 1.94,2.19,2.48,2.63 };

    float x = 7;

    cout << "S(" << x << ") = " << cb_spl(xn, fxn, x);
}
