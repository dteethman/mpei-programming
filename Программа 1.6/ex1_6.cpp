#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(void) {
    int N;
    float A;
    cout << "\nВведите N: ";
    cin >> N;
    cout << "Введите A: ";
    cin >> A;
    
    float x1 = -6 * A;
    float dX = 3 * A;
    float x = 0;
    float y = 0;
    cout << "\nx1 = -6A = " << x1 << endl;
    cout << "dX = 3A / 10 = " << dX << endl;

    if (N <= 0) {
        cout << "\nПрограмма не может быть выполнена с заданным набором параметров\n";
        return 0;
    } else {
        cout << "\nN       X          Y\n";
        for (int i = 1; i <= N; i++) {
            x = x1 + (dX * (i - 1));
            if (x < 0) {
                y = sqrt(pow(A * A, 1.0/3) + pow(x * x, 1.0/3));
            } else {
                y = A + sqrt(pow(x, 3)/ (2 * A + x));
            }

            cout << i << "       " << fixed << setprecision(2) << x << "    " << y << endl;
        }
    }
    cout << endl;

    return 0;
}