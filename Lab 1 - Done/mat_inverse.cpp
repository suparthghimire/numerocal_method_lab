#include<iostream>
#define MAX 1
using namespace std;

float identity[MAX][MAX];

void setIdentityMat() {
    for (int i = 0;i < MAX;i++) {
        for (int j = 0;j < MAX;j++) {
            if (i == j) identity[i][j] = 1;
            else identity[i][j] = 0;
        }
    }
}

void inverse(float mat[MAX][MAX]) {
    for (int i = 0;i < MAX;i++) {
        float pivot = mat[i][i];
        mat[i][i] /= pivot;
        for (int j = 0;j < MAX;j++) {
            identity[i][j] /= pivot;
        }
        for (int j = i + 1;j < MAX;j++) {

            for (int k = j;k < MAX;k++) {
                mat[i][k] = mat[i][k] / pivot;
            }

            pivot = mat[i][i];
            float x = -1 * mat[j][i] / pivot;
            for (int k = 0;k < MAX;k++) {
                mat[j][k] = mat[j][k] + x * mat[i][k];
                identity[j][k] = identity[j][k] + x * identity[i][k];
            }
        }
    }
    for (int i = MAX - 1; i >= 0;i--) {
        float pivot = mat[i][i];
        mat[i][i] /= pivot;
        for (int j = MAX - 1;j >= 0;j--) {
            identity[i][j] /= pivot;
        }
        for (int j = i - 1;j >= 0;j--) {
            for (int k = j;k < MAX;k++) {
                mat[i][k] = mat[i][k] / pivot;
            }
            pivot = mat[i][i];
            float x = -1 * mat[j][i] / pivot;
            for (int k = MAX - 1;k >= 0;k--) {
                mat[j][k] = mat[j][k] + x * mat[i][k];
                identity[j][k] = identity[j][k] + x * identity[i][k];
            }
        }
    }
}

int main() {
    system("cls");
    float mat[MAX][MAX] = {
        {5}
    };
    setIdentityMat();

    inverse(mat);
    cout << "Inverse: " << endl;
    for (int i = 0;i < MAX;i++) {
        cout << " |  ";
        for (int j = 0;j < MAX;j++) {
            cout << identity[i][j] << "  ";
        }
        cout << "| " << endl;
    }

}