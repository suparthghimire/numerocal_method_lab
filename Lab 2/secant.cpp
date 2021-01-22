#include<iostream>
#include<math.h>
#define ERR 0.02
using namespace std;
float func(float x) {
    return x * sin(x) - 1;
}
struct data {
    float root;
    float func_val;
    float it;
};

struct data secant(float x0, float x1) {
    struct data d;
    float err;
    float x2;
    int count = 0;
    do {
        count++;
        if (func(x2) == 0) {
            d.root = x2;
            d.func_val = func(x2);
            d.it = count;
            return d;
        }
        else {
            float numerator = x1 - x0;
            float denominator = func(x1) - func(x0);
            x2 = x1 - (func(x1) * numerator / denominator);
        }

        err = fabs((x2 - x1) / x1);

        x0 = x1;
        x1 = x2;
    } while (err > ERR);

    d.root = x2;
    d.func_val = func(x2);
    d.it = count;
    return d;
}

int main() {
    float x0;
    float x1;

    cout << "Lower Input: ";
    cin >> x0;

    cout << "Upper Input: ";
    cin >> x1;

    if (func(x0) == 0) {
        cout << "Root: " << x0 << endl;
        cout << "Function Value: " << func(x0) << endl;
        cout << "Count: " << 0 << endl;
    }
    else if (func(x1) == 0) {
        cout << "Root: " << x1 << endl;
        cout << "Function Value: " << func(x1) << endl;
        cout << "Count: " << 0 << endl;
    }
    else {
        cout << "Root: " << secant(x0, x1).root << endl;
        cout << "Function Value: " << secant(x0, x1).func_val << endl;
        cout << "Count: " << secant(x0, x1).it << endl;
    }
}

