#ifndef BOOKLIST_H
#define BOOKLIST_H

#include "book.h"


class BookList
{
private:
    Book *lastBook;
    void addToEmptyList(Book *);
public:
    BookList();
    void addAfter(Book * , Book *);
    void addEnd(Book *);
    void addBegin(Book *);
    void remove(Book *);
    Book* search(String , String);


};

#endif // BOOKLIST_H
