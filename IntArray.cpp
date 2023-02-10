#include "IntArray.h"

const char* bad_range::what() const noexcept
{
	return "Выход за пределы массива";
}

const char* bad_length::what() const noexcept
{
	return "Недопустимый размер массива";
}

IntArray::IntArray(int length) : m_length{ length }
{
	//assert(length >= 0); // ASSERT
	if (length <= 0)
	{
		throw bad_length();
	}

	if (length > 0)
		m_data = new int [length] {};
}

void IntArray::erase()
{
	delete[] m_data;

	m_data = nullptr;
	m_length = 0;
}

int& IntArray::operator[](int index)
{
	//assert(index >= 0 && index < m_length);		// ASSERT
	if (index <= 0 && index > m_length)
	{
		throw bad_range();
	}
	return m_data[index];
}

int IntArray::getLength() const
{
	return m_length;
}

void IntArray::reallocate(int newLenght)
{
	erase();

	if (newLenght <= 0)
		return;

	m_data = new int[newLenght];
	m_length = newLenght;
}

void IntArray::resize(int newLength)
{
	if (newLength == m_length)
	{
		return;
	}

	if (newLength <= 0)
	{
		erase();
		return;
	}

	int* data{ new int[newLength] };

	if (m_length > 0)
	{
		int elementsToCopy{ (newLength > m_length ? m_length : newLength) };

		for (int index{ 0 }; index < elementsToCopy; ++index)
		{
			data[index] = m_data[index];
		}
	}

	delete[] m_data;

	m_data = data;
	m_length = newLength;
}

IntArray::IntArray(const IntArray& a)
{
	reallocate(a.getLength());

	for (int index{ 0 }; index < m_length; ++index)
	{
		m_data[index] = a.m_data[index];
	}
}

IntArray& IntArray::operator=(const IntArray& a)
{
	if (&a == this)
		return *this;

	reallocate(a.getLength());

	for (int index{ 0 }; index < m_length; ++index)
		m_data[index] = a.m_data[index];

	return *this;
}

void IntArray::insertBefore(int value, int index)
{
	//assert(index >= 0 && index <= m_length);	//ASSERT
	if (index < 0 || index > m_length)
	{
		throw bad_range();
	}

	int* data{ new int[m_length + 1] };

	for (int befor{ 0 }; befor < index; ++befor)
	{
		data[befor] = m_data[befor];
	}

	data[index] = value;

	for (int after{ index }; after < m_length; ++after)
	{
		data[after + 1] = m_data[after];
	}

	delete[] m_data;
	m_data = data;
	++m_length;
}

void IntArray::remove(int index)
{
	//assert(index >= 0 && index < m_length);	//ASSERT
	if (index < 0 || index >= m_length)
	{
		throw bad_range();
	}

	if (m_length == 1)
	{
		erase();
		return;
	}

	int* data{ new int[m_length - 1] };

	for (int befor{ 0 }; befor < index; ++befor)
	{
		data[befor] = m_data[befor];
	}

	for (int after{ index + 1 }; after < m_length; ++after)
	{
		data[after - 1] = m_data[after];
	}

	delete[] m_data;
	m_data = data;
	--m_length;
}

void IntArray::insertAtBeginning(int value)
{
	insertBefore(value, 0);
}

void IntArray::insertAtEnd(int value)
{
	insertBefore(value, m_length);
}
