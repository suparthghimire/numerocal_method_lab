#include<iostream>
#include<math.h>
#define ERR 0
using namespace std;
float funcX(float y, float z) {
    return ((float)1 / 6) * (11 - 2*y - z);
}
float funcY(float x, float z) {
    return ((float)1 / 7) * (5 + 2*x - z);
}
float funcZ(float x, float y) {
    return (-(float)1 / 5) * (-1 - 2*y - x);
}
struct data { float x, y, z; };


struct data jacobi() {
    float x = 0, y = 0, z = 0;
    float errX = 1, errY = 1, errZ = 1;
    do {
        float prevX = x;
        float prevY = y;
        float prevZ = z;
        x = funcX(prevY, prevZ);
        y = funcY(prevX, prevZ);
        z = funcZ(prevX, prevY);
        errX = fabs((x - prevX));
        errY = fabs((x - prevY));
        errZ = fabs((z - prevZ));
    } while (errX > ERR && errY > ERR && errZ > ERR);

    struct data d;
    d.x = x;
    d.y = y;
    d.z = z;
    return d;
};
int main() {
    system("cls");
    cout << "x = " << jacobi().x << endl;
    cout << "y = " << jacobi().y << endl;
    cout << "z = " << jacobi().z << endl;

}
