#pragma once
#include <iostream>
#include <string>

using namespace std;
class Book
{
public:
	//������ ������ �����
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

	//���������� ��������� ��������� ������ � �����
	bool operator ==(Book& other)
	{}
	//������ ������ � �������� �����
	//�������� ������ � ����� �����
	void SetNewBook()
	{}

	//����� ������ ����� �� �����
	void ShowBook(Book book)
	{}

};
