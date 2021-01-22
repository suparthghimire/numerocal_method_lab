#include<iostream>
#include<math.h>
#define ERR 0.0001
using namespace std;
float funcX(float y, float z) {
    return ((float)1 / 6) * (11 + 2*y - z);
}
float funcY(float x, float z) {
    return ((float)1 / 7) * (5 + 2*x - 2*z);
}
float funcZ(float x, float y) {
    return ((float)1 / 5) * (1 + 2*y + x);
}
struct data { float x, y, z,count; };

struct data sidel() {
    float x = 0, y = 0, z = 0;

    float errX = 1, errY = 1, errZ = 1;
	int count = 0;
    do {
        float prevX = x;
        float prevY = y;
        float prevZ = z;
        x = funcX(y, z);
        y = funcY(x, z);
        z = funcZ(x, y);
        errX = fabs((x - prevX));
        errY = fabs((x - prevY));
        errZ = fabs((z - prevZ));
        count++;
    } while (errX > ERR && errY > ERR && errZ > ERR);

    struct data d;
    d.x = x;
    d.y = y;
    d.z = z;
    d.count = count;
    return d;
};


int main() {
    system("cls");
    cout << "x = " << sidel().x << endl;
    cout << "y = " << sidel().y << endl;
    cout << "z = " << sidel().z << endl;
	cout << "Count = " << sidel().count << endl;
}
