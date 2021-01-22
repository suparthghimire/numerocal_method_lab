#include<iostream>
#include<math.h>
#define ERROR 0.05
using namespace std;


float func(float x) {
    return x * x * x - sin(x) - 5;
}
float func_x(float x) {
    return cbrt(sin(x) + 5);
}

struct data {
    float root;
    float func_val;
    int count;
};


struct data fixed_point(float x0) {
    float err;
    float x1;
    struct data d;
    int count = 0;
    int i = 0;
    do {
        count++;
        if (func(x1) == 0) {
            d.root = x1;
            d.func_val = func(x1);
            d.count = count;
            return d;
        }
        x1 = func_x(x0);
        err = fabs((x1 - x0) / x1);
        x0 = x1;
        i++;
    } while (err > ERROR);


    d.root = x1;
    d.func_val = func(x1);
    d.count = count;
    return d;
}

int main() {
    float x0;
    cout << "Enter x0 ";
    cin >> x0;

    if (func(x0) == 0) {
        cout << "Root: " << x0 << " Function value: " << func(x0) << " count " << 0 << endl;
    }
    else {
        cout << "Root: " << fixed_point(x0).root << endl;
        cout << "Function Value: " << fixed_point(x0).func_val << endl;
        cout << "Count: " << fixed_point(x0).count << endl;
    }
}