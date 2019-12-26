#include "stdafx.h"
#include "MyString.h"


MyString::MyString()
{
	m_p_str = NULL;
	m_size = 0;
}

MyString::MyString(const char* a_p_str) {
	m_size = strlen(a_p_str) + 1;
	m_p_str = new char[m_size];
	strcpy_s(m_p_str, sizeof(a_p_str) + 1, a_p_str);
}

size_t MyString::size() {
	return m_size;
}

MyString::~MyString()
{
	delete[] m_p_str;
}

std::ostream& operator << (std::ostream& a_stream, MyString &a_value)
{
	for (int i = 0; i < a_value.size(); i++)
		a_stream << a_value.m_p_str[i];
	return a_stream;
}

bool operator==(const MyString& lhs, const MyString& rhs)
{
	return true;
}

//
//inline bool operator!=(const X& lhs, const X& rhs) 
//{
//	return !(lhs == rhs); 
//}

//MyString& operator+ (MyString& a_value1, MyString& a_value2)
//{
//  return 
//}

