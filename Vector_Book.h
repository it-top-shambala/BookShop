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
	//������ ������ � �������� ������ ����
        //������� ��������� ����� � ������(������)
	void SetBookToVector(Book book)
	{}
	//������� ����������� ���������� ���� �� ������
	int CountBooks()
	{}

	//������� ������ ������� ������ ����� � ������(�������)
	int FindBook(Book book)
	{}
	//������� ���������� ������ ����� �� ������(�������)	
	void GetBook(Book book)
	{}
	//������� ��������� ������� ���� �����
	void ChangePriceBook(Book book, float new_price)
	{}
	//������� ��������� �������� ���� �����
	void ChangePriceBook(Book book, float new_price)
	{}
	//������� ��������� �������� �����
	void ChangePriceBook(Book book, int new_rat)
	{}
	//������� ������ �� ����� ������� ���� �� ������
	void ExtractBook_Author(Book book, string author)
	{}
};
