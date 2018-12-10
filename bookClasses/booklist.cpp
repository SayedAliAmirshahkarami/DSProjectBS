#include "booklist.h"

BookList::BookList(){
    lastBook = NULL;
}

void BookList::clear(){
    lastBook = NULL;
}

BookList* BookList::operator =(BookList &bookList){
    Book *currentBook = bookList.lastBook->getNext();
    this->clear();
    do{
        this->addEnd(currentBook);
        currentBook = currentBook->getNext();
    }while(currentBook != lastBook->getNext());
    return this;
}

Book* BookList::getLastBook(){
    return lastBook;
}

Book* BookList::getBookAt(int i){
    qDebug(QString::number(i).toStdString().c_str());

    Book* currentBook = lastBook->getNext();
    for(int j = 0;j < i;j++){
        qDebug(currentBook->getTitle().toStdString().c_str());
        currentBook = currentBook->getNext();
    }
    qDebug(currentBook->getTitle().toStdString().c_str());
    return currentBook;
}


vector<Book*> BookList::find(QString author="" , QString title="" , int publishYear = -1, int price = -1){

//    BookList *foundedBooks = new BookList;
    vector<Book*>foundedBooks;
    foundedBooks.clear();
    Book *currentBook = lastBook->getNext();


    if(author == "" && title == "" && publishYear == -1 && price == -1){

        return foundedBooks;
    }
    else if(author == "" && title == "" && publishYear == -1 && price > -1){
        do{
            if(currentBook->getPrice() == price){
               foundedBooks.push_back(currentBook);
            }
            currentBook = currentBook->getNext();
        }while(currentBook != lastBook->getNext());
    }
    else if(author == "" && title == "" && publishYear > -1 && price == -1){
        do{
            if(currentBook->getPublishYear() == publishYear){
                foundedBooks.push_back(currentBook);
            }
            currentBook = currentBook->getNext();
        }while(currentBook != lastBook->getNext());
    }
    else if(author == "" && title == "" && publishYear > -1 && price > -1){
        do{
            if(currentBook->getPrice() == price && currentBook->getPublishYear() == publishYear){
                foundedBooks.push_back(currentBook);
            }
            currentBook = currentBook->getNext();
        }while(currentBook != lastBook->getNext());
    }
    else if(author == "" && title != "" && publishYear == -1 && price == -1){
        do{
            if(currentBook->getTitle() == title){
                foundedBooks.push_back(currentBook);
            }
            currentBook = currentBook->getNext();
        }while(currentBook != lastBook->getNext());
    }
    else if(author == "" && title != "" && publishYear == -1 && price > -1){
        do{
            if(currentBook->getPrice() == price && currentBook->getTitle() == title){
                foundedBooks.push_back(currentBook);
            }
            currentBook = currentBook->getNext();
        }while(currentBook != lastBook->getNext());
    }
    else if(author == "" && title != "" && publishYear > -1 && price == -1){
        do{
            if(currentBook->getPublishYear() == publishYear && currentBook->getTitle() == title){
                foundedBooks.push_back(currentBook);
            }
            currentBook = currentBook->getNext();
        }while(currentBook != lastBook->getNext());
    }
    else if(author == "" && title != "" && publishYear > -1 && price > -1){
        do{
            if(currentBook->getPrice() == price && currentBook->getPublishYear() == publishYear && currentBook->getTitle() == title){
               foundedBooks.push_back(currentBook);
            }
            currentBook = currentBook->getNext();
        }while(currentBook != lastBook->getNext());
    }
    else if(author != "" && title == "" && publishYear == -1 && price == -1){
        do{
            if(currentBook->getAuthor() == author){
               foundedBooks.push_back(currentBook);
            }
            currentBook = currentBook->getNext();
        }while(currentBook != lastBook->getNext());
    }
    else if(author != "" && title == "" && publishYear == -1 && price > -1){
        do{
            if(currentBook->getPrice() == price && currentBook->getAuthor() == author){
                foundedBooks.push_back(currentBook);
            }
            currentBook = currentBook->getNext();
        }while(currentBook != lastBook->getNext());
    }
    else if(author != "" && title == "" && publishYear > -1 && price == -1){
        do{
            if(currentBook->getPublishYear() == publishYear && currentBook->getAuthor() == author){
                foundedBooks.push_back(currentBook);
            }
            currentBook = currentBook->getNext();
        }while(currentBook != lastBook->getNext());
    }
    else if(author != "" && title == "" && publishYear > -1 && price > -1){
        do{
            if(currentBook->getPrice() == price  && currentBook->getPublishYear() == publishYear && currentBook->getAuthor() == author){
                foundedBooks.push_back(currentBook);
            }
            currentBook = currentBook->getNext();
        }while(currentBook != lastBook->getNext());
    }
    else if(author != "" && title != "" && publishYear == -1 && price == -1){
        do{
            if(currentBook->getTitle() == title && currentBook->getAuthor() == author){
                foundedBooks.push_back(currentBook);
            }
            currentBook = currentBook->getNext();
        }while(currentBook != lastBook->getNext());
    }
    else if(author != "" && title != "" && publishYear == -1 && price > -1){
        do{
            if(currentBook->getPrice() == price  && currentBook->getTitle() == title && currentBook->getAuthor() == author){
                foundedBooks.push_back(currentBook);
            }
            currentBook = currentBook->getNext();
        }while(currentBook != lastBook->getNext());
    }
    else if(author != "" && title != "" && publishYear > -1 && price == -1){
        do{
            if(currentBook->getPublishYear() == publishYear  && currentBook->getTitle() == title && currentBook->getAuthor() == author){
                foundedBooks.push_back(currentBook);
            }
            currentBook = currentBook->getNext();
        }while(currentBook != lastBook->getNext());
    }
    else if(author != "" && title != "" && publishYear > -1 && price > -1){
        do{
            if(currentBook->getPrice() == price && currentBook->getPublishYear() == publishYear  && currentBook->getTitle() == title && currentBook->getAuthor() == author){
                foundedBooks.push_back(currentBook);
            }
            currentBook = currentBook->getNext();
        }while(currentBook != lastBook->getNext());
    }

    return foundedBooks;


}


Book* BookList::addEnd(Book *newBook){
    if(!lastBook){
        qDebug("bookList is empty...");
        return addToEmptyList(newBook);
    }
    Book *tempBook = new Book(newBook);
    tempBook->setNext(lastBook->getNext());
    lastBook->setNext(tempBook);

    lastBook = tempBook;
    qDebug(lastBook->getTitle().toStdString().c_str());
    qDebug(tempBook->getTitle().toStdString().c_str());
    qDebug(lastBook->getNext()->getTitle().toStdString().c_str());
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
    lastBook->setNext(lastBook);
    qDebug("LastBook title : ");
    qDebug(lastBook->getTitle().toStdString().c_str());
    return lastBook;
}

void BookList::display(){
    Book* currentBook = lastBook->getNext();
    do{
        qDebug(currentBook->getTitle().toStdString().c_str());
        currentBook = currentBook->getNext();
    }while(currentBook != lastBook->getNext());
}

int BookList::remove(Book *rmBook){
    qDebug(rmBook->getTitle().toStdString().c_str());
     Book *currentBook = lastBook->getNext();
     if(currentBook == lastBook){
         if(rmBook == lastBook){
             lastBook = NULL;
             return 1;
         }
         else{
             return 0;
         }
     }
     do{
         if(currentBook->getNext() == rmBook){
             currentBook->setNext(rmBook->getNext());
             return 1;
         }
         currentBook = currentBook->getNext();
     }while(currentBook != lastBook->getNext());
     return 0;
}

                                                                                                                                                                                                                                                                                                                                                                                    
