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

	~ IntArray()	// ����������
	{
		delete[] m_data;
	}

	void erase();	//������� �������

	int& operator[](int index);		//���������� ���������� �������

	int getLength() const;	//����� �������� ����� �������

	void reallocate(int newLenght);	//��������� ������� � ����������� ������

	void resize(int newLength);		//��������� ������� ������� ��� ������ ����������� ���������

	IntArray(const IntArray& a);		//����������� �����������

	IntArray& operator=(const IntArray& a);		//��������������� ��������� ����������

	void insertBefore(int value, int index);		//������� �������� 

	void remove(int index);		//�������� ������� �� �������
		
	void insertAtBeginning(int value); 	//������� � ������

	void insertAtEnd(int value); 		//������� � �����
};

