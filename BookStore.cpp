// BookStore.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <istream>
#include "Product.h"
#include "Category.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");

        Category_Book books("D:\BookShop\Books.txt");
        books.GetFileBook();//чтение вектора книг из файла
        Work_books _books;
        _books.using_book();//работа с вектором книг
        books.SetFileBook();//запись вектора книг в файл
};

