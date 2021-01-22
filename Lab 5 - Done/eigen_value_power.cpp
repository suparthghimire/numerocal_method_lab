#include<iostream>
#include<math.h>
#define MAX 3
#define ERR 0.05
using namespace std;

void matrixMul(float a[MAX][MAX], float b[MAX][1], float(&product)[MAX][1]) {
    for (int i = 0;i < MAX;i++) {
        for (int j = 0;j < 1;j++) {
            product[i][j] = 0;
            for (int k = 0;k < MAX;k++)
                product[i][j] += a[i][k] * b[k][j];
        }
    }
}
float maxInMat(float mat[MAX][1]) {
    float max_val = 0;
    for (int i = 0;i < MAX;i++)
        for (int j = 0;j < 1;j++)
            max_val = max(mat[i][j], max_val);
    return max_val;
}
void divMatrix(float mat[MAX][1], float val, float(&res)[MAX][1]) {
    for (int i = 0;i < MAX;i++)
        for (int j = 0;j < 1;j++)
            res[i][j] = mat[i][j] / val;


}
void storeX(float X[MAX][1], float(&tempX)[MAX][1]) {
    for (int i = 0;i < MAX;i++)
        for (int j = 0;j < 1;j++)
            tempX[i][j] = X[i][j];
}
bool compErr(float a[MAX][1], float b[MAX][1]) {
    float err[MAX];
    for (int i = 0;i < MAX;i++)
        for (int j = 0;j < 1;j++)
            err[i] = fabs(a[i][j] - b[i][j] / a[i][j]);

    for (int i = 0;i < MAX;i++)
        if (err[i] > ERR) return false;

    return true;
}

int main() {
    float A[MAX][MAX] = { {1,6,1},{1,2,0},{0,0,3} };
    float X[MAX][1] = { {0},{1},{0} };
    float Y[MAX][1];
    float k;
    int i = 0;
    do {
        float temp_x[MAX][1];
        storeX(X, temp_x);
        matrixMul(A, X, Y);
        k = maxInMat(Y);
        divMatrix(Y, k, X);
        i++;
        if (compErr(X, temp_x)) break;
    } while (true);
    cout << "Eigen Value: " << k << endl << "Eigen Vector: " << endl;

    for (int i = 0; i < MAX; i++)
        for (int j = 0;j < 1;j++)
            cout << X[i][j] << " ";
    cout << endl;
}
