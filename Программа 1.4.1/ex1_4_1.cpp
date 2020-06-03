#include <iostream>
#include "../teethlib.cpp"

using namespace std;

int main(void) {
    MatrixS<double> X, Y;
    int N;

    cout << "\nВведите размер массива: ";
    cin >> N;

    X.create(N);
    Y.create(N);

    cout << "\nВведите массив X:" << endl;
    X.get_from_keyboard();

    cout << "\nВведите массив Y:" << endl;
    Y.get_from_keyboard();

    cout << "\nИсходный массив X:" << endl;
    X.display();
    cout << "\nИсходный массив Y:" << endl;
    Y.display();

    cout << "\nОтношение среднего арифметического X к среднему арифметическому Y: " << (X.average() / Y.average()) << endl << endl;
    
    return 0;
}