#include <iostream>
#include "../teethlib.cpp"

using namespace std;

int main(void) {
    MatrixS<double> A;
    int N = 0;

    cout << "\nВведите размер массива: ";
    cin >> N;

    A.create(N);

    cout << "\nВведите массив A:\n";
    A.get_from_keyboard();

    cout << "\nИсходный массив A:\n";
    A.display();

    cout << "\nРазность максимального и минимального элементов: " << A.max() - A.min() << endl << endl;

    return 0;
}
