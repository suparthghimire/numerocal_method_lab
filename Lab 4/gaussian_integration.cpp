#include<iostream>
#include<math.h>
using namespace std;
float func(float x) {
	float exp_num =float((1)/(x+2));
    return exp_num;
}
int main() {
    cout << "Two Point: " << func(((float)-1 / sqrt(3))) + func((float)1 / sqrt(3)) << endl;
    cout << "Three Point: " << ((float)5 / 9) * func(-sqrt((float)3 / 5)) + ((float)8 / 9) * func(0) + ((float)5 / 9) * func(sqrt((float)3 / 5));
}
