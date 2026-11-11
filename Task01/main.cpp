#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class Book {
    string title;
    int copies;
public:
    Book() : Book("Untitled", 0) {}
    explicit Book(const string& t) : Book(t, 1) {}
    Book(const string& t, int c) : title(t), copies(c) {
        if (c < 0) throw invalid_argument("copies cannot be negative");
    }
    void show() const { cout << title << " : " << copies << '\n'; }
};
int main() {
    Book a;
    Book b("C++ Basics");
    Book c("Data Structures", 5);
    a.show(); b.show(); c.show();
    try { Book bad("Wrong", -2); bad.show(); }
    catch (const invalid_argument& e) { cout << "Error: " << e.what() << '\n'; }
}
