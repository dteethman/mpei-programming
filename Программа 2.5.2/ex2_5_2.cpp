#include <iostream>
#include "../teethlib.cpp"

using namespace std;

int main(void) {
    MatrixS<double> A;
    int N;

    cout << "\nВведите размер квадратной матрицы: ";
    cin >> N;

    A.create(N, N);
    cout << "\nВведите матрицу A:\n";
    A.get_from_keyboard();
    cout << "\nИсходная матрица A:\n";
    A.display();

    double averageOfArray = 0;
    double sumOfNegativeRows = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j< N; j++) {
            averageOfArray += A.at(i,j);
            if (A.at(j,j) < 0) {
                sumOfNegativeRows += A.at(i,j);
            }
        }
    }

    averageOfArray /= N * N;

    cout << "\nСреднее арифметическое элементов матрицы: " << averageOfArray;
    if (sumOfNegativeRows > 0) {
        cout << "\nСумма элементов столбцов, которые содержат отрицательный элемент на главной диагонали: " << sumOfNegativeRows;
    } else {
        cout << "\nНет отрицательных элементов на главной диагонали";
    }

    cout << endl << endl;

    return 0;
}
