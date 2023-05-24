#include <iostream>
#include <cstring>

using namespace std;

struct Books
{
    char title[50];
    int bookId;
};

typedef struct TBooks
{
    char title[50];
    int bookId;
} TBooks;

void initBook();
void printBook(struct Books book);
void printPBook(struct Books *book);
void printTBook(TBooks *book);

int main()
{
    initBook();
    return 0;
}

void initBook()
{
    Books b1, b2;
    strcpy(b1.title, "c++");
    b1.bookId = 123;
    strcpy(b2.title, "golang");
    b2.bookId = 124;

    cout << "b1 id:" << b1.bookId << ", title:" << b1.title << endl;
    printBook(b2);
    printPBook(&b2);

    TBooks b3;
    strcpy(b3.title, "cpp");
    b3.bookId = 125;
    printTBook(&b3);

    return;
}

void printBook(struct Books book)
{
    cout << "b2 id:" << book.bookId << ", title:" << book.title << endl;
}

void printPBook(struct Books *book)
{
    cout << "b2 ptr id:" << book->bookId << ", ptr title:" << book->title << endl;
}

void printTBook(TBooks *book)
{
    cout << "b3 ptr id:" << book->bookId << ", ptr title:" << book->title << endl;
}