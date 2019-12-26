#include "pch.h"

#include "..\MyString\MyString.h"

TEST(TestMyString, Test1) {

	MyString str("String1");

	EXPECT_EQ(str, "String1");
  EXPECT_TRUE(true);
}