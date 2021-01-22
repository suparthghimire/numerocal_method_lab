#include<iostream>
#include<math.h>
#define ERROR 0.05
using namespace std;


float func(float x) {
    return x * x * x - sin(x) - 5;
}
float func_der(float x) {
    return 3 * x * x - cos(x);
}
float abs_(float x) {
    return x > 0 ? x : -x;
}

struct data {
    float root;
    float func_val;
    float it;
};

struct data raphson(float x0) {
    struct data d;
    float err = 999;
    float x1;
    int count = 0;
    int i = 0;
    do {
        count++;
        if (func(x0) == 0) {
            d.root = x0;
            d.func_val = 0;
            d.it = count;
            return d;
        }
        else {
            x1 = x0 - (func(x0) / func_der(x0));
        }
        err = abs_((x1 - x0) / x1);
        x0 = x1;
        i++;
    } while (err > ERROR);

    d.root = x0;
    d.func_val = func(x0);
    d.it = count;
    return d;
}
int main() {
    float x0;
    cout << "Enter initial guess: ";
    cin >> x0;

    if (func(x0) == 0) {
        cout << "Root: " << x0 << endl;
        cout << "Functional Value " << 0 << endl;
        cout << "Count " << 0 << endl;
    }
    else {
        cout << "Root: " << raphson(x0).root << endl;
        cout << "Function Value: " << raphson(x0).func_val << endl;
        cout << "Count: " << raphson(x0).it << endl;
    }
}
