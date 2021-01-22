#include<iostream>
#include<math.h>
#define ERROR 0.05

using namespace std;


float func(float x) {
    return x * x * x - sin(x) - 5;
}
float abs_(float x) {
    return x > 0 ? x : -x;
}

struct data {
    float root;
    float func_val;
    float it;
};

struct data bisection(float a, float  b) {
    float err;
    int count = 1;
    float m = (a + b) / 2;
    struct data d;
    int i = 0;
    do {
        count++;
        if (func(m) == 0) {
            d.root = m;
            d.func_val = func(m);
            d.it = count;
            return d;
        }
        else if (func(m) < 0) {
            a = m;
        }
        else if (func(m) > 0) {
            b = m;
        }
        m = (a + b) / 2;
        err = abs_((b - a) / b);
        i++;
    } while (err > ERROR);
    d.root = m;
    d.func_val = func(m);
    d.it = count;
    return d;
}

int main() {
    system("CLS");
    float a;
    float b;

    cout << "Enter lower Guess: ";
    cin >> a;
    cout << "Enter Upper Guess: ";
    cin >> b;

    if (func(a) * func(b) > 0) {
        cout << "Starting Parameters not correct" << endl;
    }
    else if (func(a) == 0) {
        cout << "Root: " << a << endl;
    }
    else if (func(b) == 0) {
        cout << "Root: " << b << endl;
    }
    else {
        cout << endl << "Root of equation: " << bisection(a, b).root << endl;
        cout << endl << "Function Value at Root: " << bisection(a, b).func_val << endl;
        cout << endl << "Total Iteration: " << bisection(a, b).it << endl;
    }

}

