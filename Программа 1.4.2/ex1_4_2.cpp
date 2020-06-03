#include <iostream>
#include "../teethlib.cpp"

using namespace std;

int main(void) {
    MatrixS<double> X, Y;
    double avg = 0;
    int N, equal = 0;

    cout << "\nВведите размер массива: ";
    cin >> N;

    X.create(N);
    Y.create(N);

    cout << "\nВведите массив X:\n";
    X.get_from_keyboard();

    cout << "\nВведите массив Y:\n";
    Y.get_from_keyboard();

    cout << "\nИсходный массив X:\n";
    X.display();
    cout << "\nИсходный массив Y:\n";
    Y.display();

    for (int i = 0; i < N; i++) {
        if (X.at(i) == Y.at(i)) {
            equal++;
        }
        avg += X.at(i);
    }

    cout << "\nКоличество равных пар элементов: " << equal;
    cout << "\nСреднее арифметическое X: " <<  (avg / double(N)) << endl << endl;
    
    return 0;
}