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
	strcpy_s(m_p_str, m_size, a_p_str);
}

MyString::MyString(const MyString& a_p_str) :
  MyString(a_p_str.m_p_str)
{
  
}

size_t MyString::size() {
	return m_size - 1;
}

MyString::~MyString()
{
	delete[] m_p_str;
}

const char& MyString::operator[] (size_t a_pos) const
{
  if (a_pos < 0 || a_pos >= m_size) {
    throw ("Invalid index");
  }

  return *(m_p_str + a_pos);
}

//MyString& Insert(int a_index, const char* a_value)
//{
//}

//MyString& Insert(int a_index, const MyString& a_value)
//{
//
//}

std::ostream& operator << (std::ostream& a_stream, MyString &a_value)
{
	for (int i = 0; i < a_value.size(); i++) {
    a_stream << a_value[i];
  }

	return a_stream;
}

bool operator==(const MyString& lhs, const MyString& rhs)
{
	return std::strcmp(lhs.m_p_str, rhs.m_p_str) == 0;
}

bool operator!=(const MyString& lhs, const MyString& rhs)
{
	return !(lhs == rhs);
}

bool operator==(const MyString& lhs, const char* rhs)
{
	return std::strcmp(lhs.m_p_str, rhs) == 0;
}

bool operator!=(const MyString& lhs, const char* rhs)
{
	return !operator==(lhs.m_p_str, rhs);
}

MyString& MyString::operator=(const MyString& a_obj)
{
	if (&a_obj == this) {
        return *this;
	}

  delete[] m_p_str;
  m_size = strlen(a_obj.m_p_str) + 1;
  m_p_str = new char[m_size];
  strcpy_s(m_p_str, m_size, a_obj.m_p_str);
  return *this;
}

MyString& MyString::operator+(const char* a_value)
{
  size_t size = m_size + strlen(a_value);

  char* tmp = new char[size];

  _snprintf_s(tmp, size, size, "%s%s", m_p_str, a_value);

  MyString *result = new MyString(tmp);
  return *result;
}

MyString& MyString::operator+(MyString& a_value)
{
  return operator+(a_value.m_p_str);
}
