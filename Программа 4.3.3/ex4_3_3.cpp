#include <iostream>
#include <string>
#include "../teethlib.cpp"

using namespace std;

int main(void) {
    MatrixS<double> A;
    int N, M;

    cout << "\nВведите количество строк: ";
    cin >> N;
    cout << "Введите количество столбцов: ";
    cin >> M;

    A.create(N, M);
    cout << "\nВведите матрицу A из " << N << " строк и " << M <<" столбцов:\n";
    A.get_from_keyboard();
    cout << "\nИсходная матрица A:\n";
    A.display();

    int k;
    cout << "\nВведите номер контрольного столбца: ";
    cin >> k;
    k -= 1;

    string direction;
    int first_col, last_col;

    if (k == A.index_of_min_col()) {
        direction = "слева";
        first_col = 0; 
        last_col = k - 1;
    } else {
        direction = "справа";
        first_col = k + 1; 
        last_col = M - 1;
    }

    if ((k == 0) || (k == M)) {
        cout << "\nНет столбцов " << direction << " от " << k + 1 << "-го\n\n";
    } else {
        float sum = A.sum_in_range_of_cols(first_col, last_col);
        cout << "\nСумма элементов в столбцах " << direction << " от " << k + 1 << "-го : " << sum << endl << endl;
    }

    return 0;
}
