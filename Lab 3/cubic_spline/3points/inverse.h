#include<iostream>
#define MAX_VAL 3
struct data {
    float a[MAX_VAL];
};

void inverse(float mat[MAX_VAL][MAX_VAL], float identity[MAX_VAL][MAX_VAL]) {

    for (int i = 0;i < MAX_VAL;i++) {
        for (int j = 0;j < MAX_VAL;j++) {
            std::cout << mat[i][j] << " ";
        }
        std::cout << std::endl;
    }


    for (int i = 0;i < MAX_VAL;i++) {
        float pivot = mat[i][i];
        mat[i][i] /= pivot;
        for (int j = 0;j < MAX_VAL;j++) {
            identity[i][j] /= pivot;
        }
        for (int j = i + 1;j < MAX_VAL;j++) {

            for (int k = j;k < MAX_VAL;k++) {
                mat[i][k] = mat[i][k] / pivot;
            }

            pivot = mat[i][i];
            float x = -1 * mat[j][i] / pivot;
            for (int k = 0;k < MAX_VAL;k++) {
                mat[j][k] = mat[j][k] + x * mat[i][k];
                identity[j][k] = identity[j][k] + x * identity[i][k];
            }
        }
    }
    for (int i = MAX_VAL - 1; i >= 0;i--) {
        float pivot = mat[i][i];
        mat[i][i] /= pivot;
        for (int j = MAX_VAL - 1;j >= 0;j--) {
            identity[i][j] /= pivot;
        }
        for (int j = i - 1;j >= 0;j--) {
            for (int k = j;k < MAX_VAL;k++) {
                mat[i][k] = mat[i][k] / pivot;
            }
            pivot = mat[i][i];
            float x = -1 * mat[j][i] / pivot;
            for (int k = MAX_VAL - 1;k >= 0;k--) {
                mat[j][k] = mat[j][k] + x * mat[i][k];
                identity[j][k] = identity[j][k] + x * identity[i][k];
            }
        }
    }



    struct data d;
    for (int i = 0;i < MAX_VAL;i++) {
        for (int j = 0;j < MAX_VAL;j++) {
            if (j == 0) {
                d.a[i] = identity[i][j];
            }
        }
    }

}