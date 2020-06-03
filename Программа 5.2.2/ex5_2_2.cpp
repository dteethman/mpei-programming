#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Book {
    public: 
    string author, title;
    int year;

    Book() {
        author, title = "";
        year = 0;
    }

    void display() {
        cout << "\e[1m" << title << "\e[0m\n";
        cout << "Автор: " << "\e[1m" << author << "\e[0m\n";
        cout << "Год издания: " << "\e[1m" << year << "\e[0m\n";

    }

};

class BookParser {
    private:
    string fileURL;

    public:
    BookParser(string URL) {
        fileURL = URL;
    }

    vector<Book> parse(){
        vector<Book> books;

        ifstream file;
        file.open(fileURL);

        string author;
        string title;
        string year;
        while (getline(file, author, ';')) {
            Book book;
            book.author = author;
            getline(file, title, ';');
            book.title = title;
            getline(file, year, '\n');
            book.year = stoi(year);
            books.push_back(book);
        }

        file.close();
        return books;
    }
};

int main(void) {
    vector<Book> books;

    BookParser parser("books.csv");
    books = parser.parse();

    if (books.size() > 0) {
        cout << "\nВ программу успешно загруженно \e[1m" << books.size() << "\e[0m книг\n";
    } else {
        cout << "\nОшибка загрузки базы книг в программу\n\n";
        return 0;
    }

    cout << "\nВведите слово для поиска: ";
    string keyword;
    cin >> keyword;

    cout << "Введите начальный год публикации: ";
    int f_year;
    cin >> f_year;

    cout << "Введите конечный год публикации: ";
    int l_year;
    cin >> l_year;
    cout << endl;

    bool is_found = false;
    for (int i = 0; i < books.size(); i++) {
        if ((books.at(i).title.find(keyword) != string::npos) 
        && (books.at(i).year >= f_year) && (books.at(i).year <= l_year)) {
            books.at(i).display();
            cout << endl;
            is_found = true;
        }
    }

    if (!is_found) {
        cout << "По вашему запросу ничего не найдено\n";
        cout << endl;
    }
    
    return 0;
}
 