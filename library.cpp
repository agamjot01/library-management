#include<iostream>
#include<string>
using namespace std;

class Book {
public:
    string title;
    string author;
    int bookID;
    bool isAvailable;
    Book* next;

    Book(string title, string author, int bookID)
        : title(title), author(author), bookID(bookID), isAvailable(true), next(nullptr) {}

    void display() {
        cout << "Book ID: " << bookID << "\n";
        cout << "Title: " << title << "\n";
        cout << "Author: " << author << "\n";
        cout << "Status: " << (isAvailable ? "Available" : "Checked Out") << "\n";
    }
};

class Library 
{
    private:
    Book* head;
    public:
    void addBook(string title, string author) 
    {
        int bookID = (head != NULL ? head->bookID + 1 : 1);
        Book* newBook = new Book(title, author, bookID);
        newBook->next = head;
        head = newBook;
        cout << "Book added successfully."<<endl;;
    }
    void displayAllBooks() 
    {
        if (!head)
        {
            cout << "The library is empty." << endl;
        }
        else
        {
            Book* current = head;
            while (current) 
            {
                current->display();
                cout << "-------------------\n";
                current = current->next;
            }
        }
    }

    Book* findBookByID(int bookID) 
    {
        Book* current = head;
        while (current)
        {
            if (current->bookID == bookID)
            {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    void checkoutBook(int bookID) 
    {
        Book* book = findBookByID(bookID);
        if (book && book->isAvailable) 
        {
            book->isAvailable = false;
            cout << "Book " << bookID << " has been checked out."<<endl;
        } 
        else 
        {
            cout << "Book " << bookID << " is not available or does not exist."<<endl;;
        }
    }
    void returnBook(int bookID) 
    {
        Book* book = findBookByID(bookID);
        if (book && !book->isAvailable) 
        {
            book->isAvailable = true;
            cout << "Book " << bookID << " has been returned."<<endl;
        } 
        else 
        {
            cout << "Book " << bookID << " is not checked out or does not exist."<<endl;
        }
    }
    ~Library() 
    {
        Book* current = head;
        while (current != NULL) 
        {
            Book* next = current->next;
            delete current;
            current = next;
        }
    }
};
    int main()
    {
    Library library;

    while (true) 
    {
        cout << "\nLibrary Management System\n";
        cout << "1. Add a Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Checkout a Book\n";
        cout << "4. Return a Book\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string title, author;
                cout << "Enter book title: ";
                cin.ignore();
                getline(cin, title);       //inputing the string
                cout << "Enter author: ";
                getline(cin, author);      //inputting the author
                library.addBook(title, author);    //inserting the book in library
                break;
            }
            case 2: {
                library.displayAllBooks();
                break;
            }
            case 3: {
                int bookID;
                cout << "Enter the book ID to checkout: ";
                cin >> bookID;
                library.checkoutBook(bookID);
                break;
            }
            case 4: {
                int bookID;
                cout << "Enter the book ID to return: ";
                cin >> bookID;
                library.returnBook(bookID);
                break;
            }
            case 5: {
                cout << "Exiting the program. Goodbye!\n";
                return 0;
            }
            default: {
                cout << "Invalid choice. Please try again.\n";
            }
        }
    }
    }


