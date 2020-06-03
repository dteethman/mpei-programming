#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main(void) {
    float result, x = 0;
    int n = 0;

    cout << "\nВведите x: "; 
    cin >> x;
    cout << "Введите n: "; 
    cin >> n;

    if (n <= 0) {
        if (n == 0) {
            cout << "\nРезультат: " << result << endl << endl;
        } else {
            cout << "\nПрограмма не может быть выполнена с заданными параметрами\n\n";
        }
    } else {
        for (int k = 0; k < n; k++) { 
            result += (fabs(x-(k+1)) * (cos(exp(1 / 3) * log(x * (k+1))) / 2));
        }
        result *= (log(x) - 2 / 9);
        cout << "\nРезультат: " << fixed << setprecision(2) << result << endl << endl;
    }

    return 0;
}