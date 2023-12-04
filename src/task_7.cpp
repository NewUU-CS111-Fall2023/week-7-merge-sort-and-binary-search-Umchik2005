#include <iostream>

using namespace std;

double recursivePow(double x, int n) {
    if (n == 0) {
        return 1.0;
    } else if (n > 0) {
        double half = recursivePow(x, n / 2);
        if (n % 2 == 0) {
            return half * half;
        } else {
            return x * half * half;
        }
    } else {
        return 1.0 / recursivePow(x, -n);
    }
}

int main() {
    double x;
    int n;

    cin >> x >> n;

    double result = recursivePow(x, n);

    cout << result << std::endl;

    return 0;
}