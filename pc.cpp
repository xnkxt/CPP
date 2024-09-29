#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip> // for std::setw
using namespace std;

// Class representing a book
class Book {
private:
    string title;
    string author;
    string isbn;
    int year;
    bool available;

public:
    // Constructor
    Book(string t, string a, string i, int y) : title(t), author(a), isbn(i), year(y), available(true) {}

    // Getters
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getISBN() const { return isbn; }
    int getYear() const { return year; }
    bool isAvailable() const { return available; }

    // Setters
    void setAvailability(bool status) { available = status; }

    // Display book details
    void displayBookInfo() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Publication Year: " << year << endl;
        cout << "Availability: " << (available ? "Available" : "Checked Out") << endl;
    }

    // Save book data to file
    void saveToFile(ofstream &outFile) const {
        outFile << title << endl << author << endl << isbn << endl << year << endl << available << endl;
    }
};

// Class representing a user
class User {
private:
    string name;
    string userID;

public:
    User(string n, string id) : name(n), userID(id) {}

    string getName() const { return name; }
    string getUserID() const { return userID; }
};

// Class representing the library catalog
class Library {
private:
    vector<Book> books;  // Collection of books
    vector<User> users;  // Collection of users

public:
    // Add a book to the library
    void addBook(const Book &b) {
        books.push_back(b);
        cout << "Book added successfully!" << endl;
    }

    // Remove a book from the library
    void removeBook(const string &isbn) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->getISBN() == isbn) {
                books.erase(it);
                cout << "Book removed successfully!" << endl;
                return;
            }
        }
        cout << "Book not found." << endl;
    }

    // Search for a book by title
    void searchBookByTitle(const string &title) const {
        bool found = false;
        for (const Book &b : books) {
            if (b.getTitle() == title) {
                cout << "Book found!" << endl;
                b.displayBookInfo();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Book not found." << endl;
        }
    }

    // Check out a book
    void checkOutBook(const string &isbn) {
        for (Book &b : books) {
            if (b.getISBN() == isbn) {
                if (b.isAvailable()) {
                    b.setAvailability(false);
                    cout << "You have checked out the book: " << b.getTitle() << endl;
                } else {
                    cout << "Book is currently checked out." << endl;
                }
                return;
            }
        }
        cout << "Book not found." << endl;
    }

    // Return a book
    void returnBook(const string &isbn) {
        for (Book &b : books) {
            if (b.getISBN() == isbn) {
                if (!b.isAvailable()) {
                    b.setAvailability(true);
                    cout << "You have returned the book: " << b.getTitle() << endl;
                } else {
                    cout << "This book was not checked out." << endl;
                }
                return;
            }
        }
        cout << "Book not found." << endl;
    }

    // Display all books in the library
    void displayAllBooks() const {
        if (books.empty()) {
            cout << "No books available in the library." << endl;
        } else {
            cout << "Library Catalog:" << endl;
            for (const Book &b : books) {
                b.displayBookInfo();
                cout << "------------------" << endl;
            }
        }
    }

    // Load books from a file
    void loadBooksFromFile(const string &filename) {
        ifstream inFile(filename);
        if (!inFile) {
            cout << "Could not open the file!" << endl;
            return;
        }
        string title, author, isbn;
        int year;
        bool available;

        while (getline(inFile, title)) {
            getline(inFile, author);
            getline(inFile, isbn);
            inFile >> year >> available;
            inFile.ignore(); // Ignore newline after the boolean
            addBook(Book(title, author, isbn, year));
            books.back().setAvailability(available);
        }
        inFile.close();
        cout << "Books loaded successfully!" << endl;
    }

    // Save books to a file
    void saveBooksToFile(const string &filename) const {
        ofstream outFile(filename);
        if (!outFile) {
            cout << "Could not open the file!" << endl;
            return;
        }
        for (const Book &b : books) {
            b.saveToFile(outFile);
        }
        outFile.close();
        cout << "Books saved successfully!" << endl;
    }
};

// Main function to demonstrate the library catalog
int main() {
    Library myLibrary;
    int choice;
    string title, author, isbn;
    int year;

    // Load books from file at the start
    myLibrary.loadBooksFromFile("library_catalog.txt");

    do {
        cout << "\nLibrary Catalog Menu:" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Remove Book" << endl;
        cout << "3. Search Book by Title" << endl;
        cout << "4. Check Out Book" << endl;
        cout << "5. Return Book" << endl;
        cout << "6. Display All Books" << endl;
        cout << "7. Save Books to File" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter author: ";
            getline(cin, author);
            cout << "Enter ISBN: ";
            getline(cin, isbn);
            cout << "Enter publication year: ";
            cin >> year;
            myLibrary.addBook(Book(title, author, isbn, year));
            break;

        case 2:
            cout << "Enter ISBN of the book to remove: ";
            cin.ignore();
            getline(cin, isbn);
            myLibrary.removeBook(isbn);
            break;

        case 3:
            cout << "Enter the title of the book to search: ";
            cin.ignore();
            getline(cin, title);
            myLibrary.searchBookByTitle(title);
            break;

        case 4:
            cout << "Enter ISBN of the book to check out: ";
            cin.ignore();
            getline(cin, isbn);
            myLibrary.checkOutBook(isbn);
            break;

        case 5:
            cout << "Enter ISBN of the book to return: ";
            cin.ignore();
            getline(cin, isbn);
            myLibrary.returnBook(isbn);
            break;

        case 6:
            myLibrary.displayAllBooks();
            break;

        case 7:
            myLibrary.saveBooksToFile("library_catalog.txt");
            break;

        case 8:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 8);

    return 0;
}