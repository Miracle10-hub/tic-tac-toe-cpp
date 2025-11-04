
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Book {
    string title;
    string author;
    int id;
};

vector<Book> library;

void addBook() {
    Book newBook;
    cout << "Enter book title: ";
    getline(cin >> ws, newBook.title);
    cout << "Enter author name: ";
    getline(cin, newBook.author);
    cout << "Enter book ID: ";
    cin >> newBook.id;

    library.push_back(newBook);
    cout << "Book added successfully!\n\n";
}

void displayBooks() {
    if(library.empty()) {
        cout << "No books in the library.\n\n";
        return;
    }
    cout << "Library Books:\n";
    for(int i = 0; i < library.size(); i++) {
        cout << i+1 << ". " << library[i].title << " by "
             << library[i].author << " (ID: " << library[i].id << ")\n";
    }
    cout << "\n";
}

void searchBook() {
    string searchTitle;
    cout << "Enter book title to search: ";
    getline(cin >> ws, searchTitle);
    bool found = false;
    for(int i = 0; i < library.size(); i++) {
        if(library[i].title == searchTitle) {
            cout << "Found: " << library[i].title << " by "
                 << library[i].author << " (ID: " << library[i].id << ")\n\n";
            found = true;
        }
    }
    if(!found) {
        cout << "Book not found.\n\n";
    }
}

int main() {
    int choice;
    do {
        cout << "Mini Library System Menu:\n";
        cout << "1. Add Book\n2. Display Books\n3. Search Book\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice, try again.\n\n";
        }
    } while(choice != 4);

    return 0;
}
