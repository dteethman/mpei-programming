#include <iostream>
#include "../teethlib.cpp"

using namespace std;

int main(void) {
    MatrixS<double> A;

    A.create(5, 5);
    cout << "\nВведите матрицу A из 5 строк и 5 столбцов:\n";
    A.get_from_keyboard();
    cout << "\nИсходная матрица A:\n";
    A.display();

    Index indOfMax = A.index_of_max();

    if (indOfMax.getY() > indOfMax.getX()) {
        cout << "\nСумма элементов под главной диагональю матрицы: " << A.sum_below_MD() << endl << endl;
    } else {
        cout << "\nМаксимальный элемент матрицы расположен не над главной диагональю\n\n";
    }

    return 0;
}
