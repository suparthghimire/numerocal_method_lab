#include<math.h>
float func(float x) {
    return exp(-x);
}
float trapazoial_composite(float h, int i, float a, float b) {
    int k = pow(2, i) + 1;
    float sum = func(a) + func(b);
    float temp_h = h;
    for (float i = a + temp_h;i < b;i += temp_h) {
        sum += 2 * func(i);
    }
    return sum * h * 0.5;
}