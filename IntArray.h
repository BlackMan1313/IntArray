#pragma once

#include <iostream>
#include <cassert> // for assert()

using namespace std;

class bad_range : public std::exception 
{
public:
	virtual const char* what() const noexcept override;
};

class bad_length : public std::exception 
{
public:
	virtual const char* what() const noexcept override;
};

class IntArray
{
private:
	int m_length{};
	int* m_data{};
public:
	IntArray() = default;

	IntArray(int length);

	~ IntArray()	// деструктор
	{
		delete[] m_data;
	}

	void erase();	//очистка массива

	int& operator[](int index);		//перегрузка опереатора массива

	int getLength() const;	//метод возврата длины массива

	void reallocate(int newLenght);	//изменение массива и уничтожение данных

	void resize(int newLength);		//изменение размера массива при помощи копирования элементов

	IntArray(const IntArray& a);		//конструктор копирования

	IntArray& operator=(const IntArray& a);		//переопределение оператора присвоения

	void insertBefore(int value, int index);		//вставка элемента 

	void remove(int index);		//удаление элмента по индексу
		
	void insertAtBeginning(int value); 	//вставка в начало

	void insertAtEnd(int value); 		//вставка в конец
};

