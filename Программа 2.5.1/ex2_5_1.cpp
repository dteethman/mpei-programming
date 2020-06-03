#include <iostream>
#include "../teethlib.cpp"

using namespace std;

int main(void) {
    MatrixS<double> A;
    double control;
    int count = 0;

    A.create(3, 7);
    cout << "\nВведите массив A из 3 строк и 7 столбцов:\n";
    A.get_from_keyboard();

    cout << "\nИсходный массив A:\n";
    A.display();

    cout << "\nВведите контрольное число: ";
    cin >> control;

    cout << endl;

    for (int col = 0; col < 7; col++) {
        if (A.sum_in_col(col) > control) {
            count++;
            cout << "Сумма элементов " << col + 1 << "-го столбца больше контрольного числа\n"; 
        }
    }

    if (count > 0) {
        cout << "-------\nВсего столбцов: " << count << endl << endl;
    } else {
        cout << "\nСумма элементов в каждом из столбцов меньше контрольного числа\n\n";
    }

    return 0;
}