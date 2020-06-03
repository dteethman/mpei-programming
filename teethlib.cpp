#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Index {
    private:
    int x, y = 0;

    public:
    Index(int xCord, int yCord) {
        if ((xCord >= 0) && (yCord >= 0))
        x = xCord;
        y = yCord;
    }


    void setX(int xCord) {
        if (xCord >= 0) {
            x = xCord;
        }
    }

    void setY(int yCord) {
        if (yCord >= 0) {
            y = yCord;
        }
    }

    int getX() {
        return x;
    }

    int getY(){
        return y;
    }
};

template< class T > 
class MatrixS {
    private:
        vector<T> v;
        bool isSet, isMatrix, isEmpty;
        int r, c;

    public:
    MatrixS() {
        r, c = 0;
        isSet = false;
        isEmpty = true;
    }


    void create(int rows, int cols = 1) {
        r = rows;
        c = cols;

        if ((r > 0) && (c > 0)) { 
            isSet = true;
        } else {
            cout << "MatrixS create() ERROR: incorect size of vector";
        }
    }


    void push_back(T element){
        v.push_back(element);
    }


    void get_from_keyboard() {
        if (!v.empty()) { v.erase(v.begin()); }

        if (!isSet) {
            cout << "MatrixS getFromKeyboard() ERROR: Container is not set for use" << endl;
            return;
        }

        for (int i = 0; i < r * c; i++) {
            T buf;
            cin >> buf;
            push_back(buf);
        }

        isEmpty = v.empty();
    }

    T at(int row, int col = 0) {
        int point;
        if (c > 1) {
            point = (row * c) + col;
            return v.at(point);

        } else {
            point = row;
            return v.at(point);
        }
    }

    void display() {
        if (c > 1) {
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    cout << at(i, j) << " ";
                }
                cout << endl;
            }

        } else {
            for (int i = 0; i < r; i++) {
                cout << at(i) << " ";
            }
            cout << endl;
        }

    }

    float average() {
        T buf = 0;

        for (int i = 0; i < v.size(); i++) {
            buf += at(i);
        }

        return float(buf) / v.size();
    }

    T min() {
        T min = at(0); 
        for (int i = 0; i < r * c; i++ ) {
            if (at(i) < min) {
                min = at(i);
            }
        }
        return min;
    }

    T max() {
        T max = at(0); 
        for (int i = 0; i < r * c; i++ ) {
            if (at(i) > max) {
                max = at(i);
            }
        }
        return max;
    }

    T sum_in_col(int col){
        T sum = 0;
        for (int i = 0; i < r; i++) {
            sum += at(i, col);
        }

        return sum;
    }

    Index index_of_max() {
        T max = at(0,0);
        Index ind = Index(0, 0);

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (at(i, j) > max) {
                    max = at(i, j);
                    ind = Index(i, j);
                }
            }
        }

        return ind;
    }

    Index index_of_min() {
        T min = at(0,0);
        Index ind = Index(0, 0);

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (at(i, j) < min) {
                    min = at(i, j);
                    ind = Index(i, j);
                }
            }
        }

        return ind;
    }

    T sum_below_MD() {
        T sum = 0;
        for (int i = 1; i < r; i++) {
            for (int j = 0; j < i; j++) {
                sum += at(i,j);
            }
        }

        return sum;
    }

    T sum_above_MD() {
        T sum = 0;
        for (int i = 0; i < r - 1; i++) {
            for (int j = i + 1; j < c; j++) {
                sum += at(i,j);
            }
        }
        
        return sum;
    }

    int index_of_min_col() {
        int index = 0;
        T min = sum_in_col(0);
        for (int col = 1; col < c; col++) {
            if (sum_in_col(col) < min) {
                min = sum_in_col(col);
                index = col;
            }
        }
        return index;
    }

    T sum_in_range_of_cols(int first_col, int last_col) {
        T sum = 0;

        for (int col = first_col; col <= last_col; col++) {
            sum += sum_in_col(col);
        }

        return sum;
    }

    
};

