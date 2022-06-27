#pragma once


#include <string>
#include <io.h>  //библиотека для работы с файлами в плане доступа 
#include "Book.h"
#include "Vector_Book.h"


using namespace std;
class Work_books : public Vector_Book, Book
{
public:
	void using_book()
	{
		cout << R"(Работа с книгами:
1. Cоздание записи о новой книге
2. Количество книг на складе
3. Выход)";
		int task;
		cout << "Введите номер задания: ";
		cin >> task;// ввод номер задания
		switch (task)
		{
		case 1:
			Book::SetNewBook();
			break;
		case 2:
			CountBooks();
			break;
		case 3:
			return;
		default:
			cout << "Такого задания не существует!" << endl;
			return;
		}
	}
};





