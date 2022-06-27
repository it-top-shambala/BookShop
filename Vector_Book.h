#pragma once

#include <iostream>
#include <string>
#include "Book.h"
#include <vector>

using namespace std;
class Vector_Book : Book
{
public:
	vector <Book> _book;
	//методы работы с объектом вектор книг
        //функция помещения книги в список(вектор)
	void SetBookToVector(Book book)
	{}
	//функция определения количества книг на складе
	int CountBooks()
	{}

	//функция поиска позиции данной книги в списке(векторе)
	int FindBook(Book book)
	{}
	//функция ликвидации данной книги из списка(вектора)	
	void GetBook(Book book)
	{}
	//функция изменения входной цены книги
	void ChangePriceBook(Book book, float new_price)
	{}
	//функция изменения выходной цены книги
	void ChangePriceBook(Book book, float new_price)
	{}
	//функция изменения рейтинга книги
	void ChangePriceBook(Book book, int new_rat)
	{}
	//функция вывода на экран выборки книг по автору
	void ExtractBook_Author(Book book, string author)
	{}
};
