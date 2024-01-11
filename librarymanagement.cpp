#include <iostream>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;

using std::string;

class Book
{
public:
    void setTitle(string title);
    void setAuthor(string author);
    void setISBN(string isbn);
    void setAvailable(bool flag);
    string getTitle();
    string getAuthor();
    string getISBN();
    void borrowBook();
    void returnBook();
    string getAvailable();

private:
    string title, author, isbn;
    bool available;
};

void Book::setTitle(string title)
{

    this->title = title;
}

void Book::setAuthor(string author)
{

    this->author = author;
}

void Book::setISBN(string isbn)
{

    this->isbn = isbn;
}
// The setAvailable function should take a boolean argument and
// set the available member variable to true if the book is available or false if it is checked out.
void Book::setAvailable(bool available)
{
    this->available = available;
}

string Book::getTitle()
{
    return title;
}

string Book::getAuthor()
{
    return author;
}

string Book::getISBN()
{
    return isbn;
}

string Book::getAvailable()
{
    if (available == true)
    {
        return "Available";
    }
    else
    {
        return "checked out";
    }
}

int main()
{

    std::vector<Book> b(100);

    while (true)
    {
        cout << "----------------------------------------------\n";
        cout << "Welcome to the library management system!\n\n";
        cout << "Menu:\n";
        cout << "1. Add book \n"
             << "2. Remove book\n"
             << "3. Search for book\n"
             << "4. Exit\n";

        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        switch (choice)
        {

        // for adding book
        case 1:
        {
            cout << "Enter book title: ";
            string title;
            cin >> title;

            cout << "Enter book author: ";
            string author;
            cin >> author;

            cout << "Enter book ISBN: ";
            string isbn;
            cin >> isbn;

            // find an empty slot in the array to add the book
            for (auto &book : b)
            {
                if (book.getISBN().empty())
                {

                    book.setTitle(title);
                    book.setAuthor(author);
                    book.setISBN(isbn);
                    book.setAvailable(true);
                    cout << "Book added successfully!\n";
                    break;
                }
                cout << "Error: Library is Full. Cannot add more books.\n";
            }
        }
        break;

            // for removing book

        case 2:
        {
            cout << "Enter book ISBN: ";
            string isbn;
            cin >> isbn;

            bool found = false;
            for (auto it = b.begin(); it != b.end(); ++it)
            {
                if (it->getISBN() == isbn)
                {

                    b.erase(it);
                    found = true;
                    cout << "Book removed successfully!\n";
                    break; // break out of loop once the book is found and removed
                }
            }
            if (!found)
            {
                cout << "Error: Book not found.\n";
            }
        }
        break;

        // for searching book;
        case 3:
        {
            cout << "Enter book ISBN: ";
            string isbn;
            cin >> isbn;

            bool found = false;
            for (auto it = b.begin(); it != b.end(); ++it)
            {
                if (it->getISBN() == isbn)
                {
                    cout << "Book Information:\n";
                    cout << "Title: " << it->getTitle() << '\n';
                    cout << "Author: " << it->getAuthor() << '\n';
                    cout << "ISBN: " << it->getISBN() << '\n';
                    cout << "Availability: " << it->getAvailable();

                    found = true;

                    break; // break out of loop once the book is found and removed
                }
            }
            if (!found)
            {
                cout << "Error: Book not found.\n";
            }
        }
        break;

            // case exit

        case 4:
            cout << "Thank you for using the library management system!\n";
            exit(1);
            break;

        default:
            cout << "Please enter correct choice!\n";
            break;
        }
    }
    return 0;
}
