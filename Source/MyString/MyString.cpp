#include "stdafx.h"
#include "MyString.h"


MyString::MyString()
{
	m_p_str = new char(0);
}

MyString::MyString(const char* a_p_str) {
  if (a_p_str == nullptr) {
    throw "NULL value!";
  }
 
  m_p_str = new char(0);

  Add(a_p_str);
}

MyString::MyString(const MyString& a_p_str) :
  MyString(a_p_str.m_p_str)
{
  
}

MyString::~MyString()
{
	delete[] m_p_str;
}

size_t MyString::size() {
  return strlen(m_p_str);
}

void MyString::Clear()
{
  delete[] m_p_str;
  m_p_str = new char();
}

const char& MyString::operator[] (size_t a_index)
{
  if (a_index < 0 || a_index >= MyString::size()) {
    throw ("Invalid index");
  }

  return *(m_p_str + a_index);
}

void MyString::Add(const char* a_value)
{
  if (a_value == nullptr) {
    throw "NULL value!";
  }

  size_t size = MyString::size() + strlen(a_value) + 1;

  char* tmp = new char[size];
  _snprintf_s(tmp, size, size, "%s%s", m_p_str, a_value);

  delete[] m_p_str;
  m_p_str = new char[size];

  strcpy_s(m_p_str, size, tmp);
  delete[] tmp;
}

void MyString::Add(const MyString& a_value)
{
  Add(a_value.m_p_str);
}

void MyString::Insert(size_t a_index, const char* a_value)
{
  if (a_index < 0 || a_index > size()) {
    throw ("Invalid index");
  }

  rsize_t size = this->size() + strlen(a_value) + 1;

  size_t size_left = a_index;
  char* cp_left = new char[size_left + 1];

  strncpy_s(cp_left, size_left + 1, m_p_str, size_left);

  char* cp_right = m_p_str + a_index;
  size_t size_right = size - a_index;

  char* tmp = new char[size];
  _snprintf_s(tmp, size, size, "%s%s%s", cp_left, a_value, cp_right);

  delete[] m_p_str;
  m_p_str = new char[size];

  strcpy_s(m_p_str, size, tmp);

  delete[] tmp;
}

void MyString::Insert(size_t a_index, const MyString& a_value)
{
  Insert(a_index, a_value.m_p_str);
}

void MyString::Remove(size_t a_index, size_t a_count)
{
  if (a_index < 0 || a_index > size()) {
    throw ("Invalid index");
  }

  if (a_index + a_count < 0 || a_index + a_count > size()) {
    throw ("Invalid count");
  }

  char* cp_left = new char[a_index + 1];
  char* cp_right = new char[size() - a_index - a_count + 1];
  *cp_left = '\0';
  *cp_right = '\0';

  size_t size = this->size();

  for (size_t i = 0; i < size; i++)
  {
    if (i == a_index) {
      strncpy_s(cp_left, i + 1, m_p_str, i);
    }

    if (a_index + 1 < size && i == a_index + a_count) {
      strncpy_s(cp_right, size - a_index - a_count + 1, m_p_str + i, size - a_index - a_count);
    }
  }

  size = this->size() + 1 - a_count;
  delete[] m_p_str;
  m_p_str = new char[size + 1];

  char* tmp = new char[size + 1];
  _snprintf_s(tmp, size, size, "%s%s", cp_left, cp_right);
  strcpy_s(m_p_str, size, tmp);

  delete[] tmp;
  delete[] cp_left;
  delete[] cp_right;
}

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
  size_t size = strlen(a_obj.m_p_str) + 1;
  m_p_str = new char[size];
  strcpy_s(m_p_str, size, a_obj.m_p_str);
  return *this;
}

MyString& MyString::operator+(const char* a_value)
{
  if (a_value == nullptr) {
    throw "NULL value!";
  }

  size_t size = MyString::size() + strlen(a_value) + 1;
  char* tmp = new char[size];
  _snprintf_s(tmp, size, size, "%s%s", m_p_str, a_value);
  MyString *result = new MyString(tmp);
  delete[] tmp;
  return *result;
}

MyString& MyString::operator+(MyString& a_value)
{
  return operator+(a_value.m_p_str);
}

MyString& MyString::operator+=(const char* a_value)
{
  m_p_str = operator+(a_value).m_p_str;
  return *this;
}

MyString& MyString::operator+=(MyString& a_value)
{
  m_p_str = operator+(a_value).m_p_str;
  return *this;
}
