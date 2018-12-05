#include "booklist.h"

BookList::BookList(){
    lastBook = NULL;
}

//Book* BookList::search()

Book* BookList::addAfter(Book *newBook, Book *previousBook){

}

Book* BookList::addEnd(Book *newBook){
    if(!lastBook){
        return addToEmptyList(newBook);
    }
    Book *tempBook = new Book(newBook);
    tempBook->setNext(lastBook->getNext());
    lastBook->setNext(tempBook);

    lastBook = tempBook;

    return lastBook;
}

Book* BookList::addBegin(Book *newBook){
  if(!lastBook){
      return addToEmptyList(newBook);
  }
  Book *tempBook = new Book(newBook);
  tempBook->setNext(lastBook->getNext());
  lastBook->setNext(tempBook);

  return lastBook;
}

Book* BookList::addToEmptyList(Book *newBook){
    if(lastBook){
        qDebug("BookList is not Empty but you consider it empty!!!\n");
        return lastBook;
    }
    lastBook = new Book(newBook);
    return lastBook;
}

                                                                                                                                                                                                                                                                                                                                                                                    
