#include <iostream>
#include <exception>
#include "IntArray.h"

int main()
{
    setlocale(LC_ALL, "");

    try
    {
        IntArray array(10);


        for (int i{ 0 }; i < 10; ++i)
            array[i] = i + 1;

        array.resize(10);
        array.insertBefore(20, 7);
        array.remove(3);
        array.insertAtEnd(30);
        array.insertAtBeginning(40);


        {
            IntArray b{ array };
            b = array;
            b = b;
            array = array;
        }

        for (int i{ 0 }; i < array.getLength(); ++i)
            std::cout << array[i] << ' ';

        std::cout << '\n'; 
    }
    catch (exception& ex)
    {
        cout << ex.what();
    }
    return 0;
    
}

//
//
//#pragma once
//
//#include <iostream>
//#include <cassert> // for assert()
//
//using namespace std;
//
//class bad_range : public std::exception
//{
//public:
//	virtual const char* what() const noexcept override
//	{
//		return "����� �� ������� �������";
//	}
//};
//
//class bad_length : public std::exception {
//public:
//	virtual const char* what() const noexcept override {
//		return "������������ ������ �������";
//	}
//};
//
//class IntArray
//{
//private:
//	int m_length{};
//	int* m_data{};
//
//public:
//	IntArray() = default;
//
//
//	IntArray(int length)
//	{
//		//assert(length >= 0); // ASSERT
//		if (length <= 0)
//		{
//			throw bad_length();
//		}
//
//		if (length > 0)
//			m_data = new int [length] {};
//	}
//
//	~IntArray()	// ����������
//	{
//		delete[] m_data;
//	}
//
//	void erase()	//������� �������
//	{
//		delete[] m_data;
//
//		m_data = nullptr;
//		m_length = 0;
//	}
//
//	int& operator[](int index)		//���������� ���������� �������
//	{
//		//assert(index >= 0 && index < m_length);		// ASSERT
//		if (index <= 0 && index > m_length)
//		{
//			throw bad_range();
//		}
//		return m_data[index];
//	}
//
//	int getLength() const	//����� �������� ����� �������
//	{
//		return m_length;
//	}
//
//	void reallocate(int newLenght)	//��������� ������� � ����������� ������
//	{
//		erase();
//
//		if (newLenght <= 0)
//			return;
//
//		m_data = new int[newLenght];
//		m_length = newLenght;
//	}
//
//	void resize(int newLength)		//��������� ������� ������� ��� ������ ����������� ���������
//	{
//		if (newLength == m_length)
//		{
//			return;
//		}
//
//		if (newLength <= 0)
//		{
//			erase();
//			return;
//		}
//
//		int* data{ new int[newLength] };
//
//		if (m_length > 0)
//		{
//			int elementsToCopy{ (newLength > m_length ? m_length : newLength) };
//
//			for (int index{ 0 }; index < elementsToCopy; ++index)
//			{
//				data[index] = m_data[index];
//			}
//		}
//
//		delete[] m_data;
//
//		m_data = data;
//		m_length = newLength;
//	}
//
//	IntArray(const IntArray& a)		//����������� �����������
//	{
//		reallocate(a.getLength());
//
//		for (int index{ 0 }; index < m_length; ++index)
//		{
//			m_data[index] = a.m_data[index];
//		}
//	}
//
//	IntArray& operator=(const IntArray& a)		//��������������� ��������� ����������
//	{
//		if (&a == this)
//			return *this;
//
//		reallocate(a.getLength());
//
//		for (int index{ 0 }; index < m_length; ++index)
//			m_data[index] = a.m_data[index];
//
//		return *this;
//	}
//
//	void insertBefore(int value, int index)		//������� �������� 
//	{
//		//assert(index >= 0 && index <= m_length);	//ASSERT
//		if (index < 0 || index > m_length)
//		{
//			throw bad_range();
//		}
//
//		int* data{ new int[m_length + 1] };
//
//		for (int befor{ 0 }; befor < index; ++befor)
//		{
//			data[befor] = m_data[befor];
//		}
//
//		data[index] = value;
//
//		for (int after{ index }; after < m_length; ++after)
//		{
//			data[after + 1] = m_data[after];
//		}
//
//		delete[] m_data;
//		m_data = data;
//		++m_length;
//	}
//
//	void remove(int index)		//�������� ������� �� �������
//	{
//		//assert(index >= 0 && index < m_length);	//ASSERT
//		if (index < 0 || index >= m_length)
//		{
//			throw bad_range();
//		}
//
//		if (m_length == 1)
//		{
//			erase();
//			return;
//		}
//
//		int* data{ new int[m_length - 1] };
//
//		for (int befor{ 0 }; befor < index; ++befor)
//		{
//			data[befor] = m_data[befor];
//		}
//
//		for (int after{ index + 1 }; after < m_length; ++after)
//		{
//			data[after - 1] = m_data[after];
//		}
//
//		delete[] m_data;
//		m_data = data;
//		--m_length;
//	}
//
//	void insertAtBeginning(int value) { insertBefore(value, 0); }		//������� � ������
//	void insertAtEnd(int value) { insertBefore(value, m_length); }		//������� � �����
//
//};
//
