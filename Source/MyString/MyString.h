#pragma once

#include <iostream>
#include <memory>

class MyString
{
public:
  MyString();

  MyString(const char* a_p_str);
  MyString(const MyString& a_p_str);

  size_t size();

  ~MyString();

  void Add(const char* a_value);
  void Add(const MyString& a_value);

  void Insert(size_t a_index, const char* a_value);
  void Insert(size_t a_index, const MyString& a_value);

  void Remove(size_t a_index, size_t a_count);

  void Clear();

  const char& operator[] (size_t pos);
  friend std::ostream& operator<<(std::ostream& a_stream, MyString& a_value);
  friend bool operator==(const MyString& lhs, const MyString& rhs);
  friend bool operator!=(const MyString& lhs, const MyString& rhs);
  friend bool operator==(const MyString& lhs, const char* rhs);
  friend bool operator!=(const MyString& lhs, const char* rhs);
  MyString& operator=(const MyString& obj);
  MyString& operator+(const char* a_value);
  MyString& operator+(MyString& a_value);
  MyString& operator+=(const char* a_value);
  MyString& operator+=(MyString& a_value);

private:
  char* m_p_str;
};

