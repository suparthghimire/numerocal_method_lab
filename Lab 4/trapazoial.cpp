#include<iostream>
#include<math.h>
using namespace std;


float func(float x) {
    return x * x;
}

//float trapazoial(float a, float b) {
//    float h = (b - a) / 2;
//    return h * (func(b) + func(a));
//}

float trapazoial(float a, float b) {
    float h = 4;
    return h * (func(b) + func(a));
}


int main() {
    system("CLS");
    float a = 0;
    float b = 8;
    cout << " " << a << endl;
    cout << "|f(x)dx = " << trapazoial(a, b) << endl;
    cout << " " << b;
}
