#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Book {
    private:
        string isbn;
        string title;
        string author;
    public:
        Book(string _isbn, string _title, string _author) {
            isbn = _isbn;
            title = _title;
            author = _author;
        }
        string getISBN() {
            return isbn;
        }
        string getTitle() {
            return title;
        }
        string getAuthor() {
            return author;
        }
};

class Library {
    private:
        vector<Book> books;
        map<string, string> loans;
    public:
        void addBook(string isbn, string title, string author) {
            Book book(isbn, title, author);
            books.push_back(book);
        }
        void removeBook(string isbn) {
            for (int i = 0; i < books.size(); i++) {
                if (books[i].getISBN() == isbn) {
                    books.erase(books.begin() + i);
                    loans.erase(isbn);
                    return;
                }
            }
        }
        void loanBook(string isbn, string loanee) {
            loans[isbn] = loanee;
        }
        void returnBook(string isbn) {
            loans.erase(isbn);
        }
        string getLoanee(string isbn) {
            if (loans.count(isbn) > 0) {
                return loans[isbn];
            } else {
                return "";
            }
        }
        void printAllBooks() {
            for (int i = 0; i < books.size(); i++) {
                cout << books[i].getTitle() << " de " << books[i].getAuthor() << " con ISBN " << books[i].getISBN() << endl;
            }
        }
};

int main() {
    Library library;
    
    // Agregar algunos libros
    library.addBook("9780451524935", "1984", "George Orwell");
    library.addBook("9780307356543", "The Catcher in the Rye", "J.D. Salinger");
    library.addBook("9788491051530", "El nombre del viento", "Patrick Rothfuss");
    
    // Prestar un libro
    library.loanBook("9780451524935", "Juan Perez");
    
    // Obtener el nombre de la persona que ha tomado prestado un libro
    string loanee = library.getLoanee("9780451524935");
    if (loanee != "") {
        cout << "El libro con ISBN 9780451524935 ha sido tomado prestado por " << loanee << endl;
    } else {
        cout << "El libro con ISBN 9780451524935 no ha sido tomado prestado" << endl;
    }
    
    library.returnBook("9780451524935");
    
    // Eliminar un libro
    library.removeBook("9788491051530");
    
    // Mostrar todos los libros de la biblioteca
    library.printAllBooks();
    
    return 0;
}