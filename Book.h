#pragma once
#include <iostream>
#include <string>

using namespace std;
class Book
{
public:
	//объект класса книга
	string NameBook;
	string Author;
	string Publisher;
	string Genre;
	int PublishYear;
	int CountPage;
	int Rating;
	float ExpPrice;
	float ImpPrice;
	int Count;

	//перегрузка оператора сравнения данных о книге
	bool operator ==(Book& other)
	{}
	//методы работы с объектом книга
	//создание записи о новой книге
	void SetNewBook()
	{}

	//вывод данных книги на экран
	void ShowBook(Book book)
	{}

};
