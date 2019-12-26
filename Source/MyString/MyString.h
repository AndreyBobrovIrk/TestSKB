#pragma once

#include <iostream>

class MyString
{
public:
	MyString();

	MyString(const char* a_p_str);

	size_t size();

	~MyString();

	friend std::ostream& operator<< (std::ostream& a_stream, MyString &a_value);
	friend bool operator==(const MyString& lhs, const MyString& rhs);

private:
	char* m_p_str;
	rsize_t m_size;
};

