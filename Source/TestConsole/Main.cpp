// MyStringTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>

#include "pch.h"
#include "../MyString/MyString.h"

void print_string(MyString& a_value)
{
	std::cout << "String: " << a_value << std::endl;
	std::cout << "Size: " << a_value.size() << std::endl;
	std::cout << std::endl;
}

int main()
{
	MyString str1("String1 ");

  print_string(str1);

  for (int i = 0; i <= str1.size() - 1; ++i) {
    std::cout << "ch " << i << ": " << str1[i] << std::endl;
  }

  std::cout << std::endl;

//	MyString str2 = "123";
//
////	MyString str3 = str1 + str2;
//
//  print_string(str2);

	system("pause");
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
