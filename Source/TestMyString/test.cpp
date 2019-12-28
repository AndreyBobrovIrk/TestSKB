#include "pch.h"

#include "..\MyString\MyString.h"

TEST(TestMyString, Init) {
  MyString str1("String1");
  EXPECT_EQ(str1, "String1");
  EXPECT_EQ(str1.size(), 7);

  EXPECT_EQ(str1[0], 'S');
  EXPECT_EQ(str1[1], 't');
  EXPECT_EQ(str1[2], 'r');
  EXPECT_EQ(str1[3], 'i');
  EXPECT_EQ(str1[4], 'n');
  EXPECT_EQ(str1[5], 'g');
  EXPECT_EQ(str1[6], '1');
  EXPECT_EQ(str1[7], '\0');

  MyString str2 = "12345";
  EXPECT_EQ(str2, "12345");
  EXPECT_EQ(str2.size(), 5);

  EXPECT_EQ(str2[0], '1');
  EXPECT_EQ(str2[1], '2');
  EXPECT_EQ(str2[2], '3');
  EXPECT_EQ(str2[3], '4');
  EXPECT_EQ(str2[4], '5');
  EXPECT_EQ(str2[5], '\0');

  EXPECT_NE(str1, str2);

  str1 = str2;
  EXPECT_EQ(str1, "12345");
  EXPECT_EQ(str1.size(), 5);

  EXPECT_EQ(str1[0], '1');
  EXPECT_EQ(str1[1], '2');
  EXPECT_EQ(str1[2], '3');
  EXPECT_EQ(str1[3], '4');
  EXPECT_EQ(str1[4], '5');
  EXPECT_EQ(str1[5], '\0');
  EXPECT_EQ(str1, str2);

  MyString str3;
  EXPECT_EQ(str3, "");
  EXPECT_EQ(str3.size(), 0);
}

TEST(TestMyString, TestPlus) {
  MyString str1("111");
  MyString str2("222");

  MyString str3 = str1 + "aaa";
  str3 = str3 + "sss";
  EXPECT_EQ(str3, "111aaasss");

  str3 = str1 + str3;
  EXPECT_EQ(str3, "111111aaasss");

  str3 = str3 + "";
  EXPECT_EQ(str3, "111111aaasss");
}

TEST(TestMyString, TestAdd) {
  MyString str1;
  MyString str2("222");

  str1.Add("111");
  EXPECT_EQ(str1, "111");
  str1.Add("222");
  EXPECT_EQ(str1, "111222");

  str1.Add("333");
  EXPECT_EQ(str1, "111222333");

  str1.Add("");
  EXPECT_EQ(str1, "111222333");

  str1.Add(str2);
  EXPECT_EQ(str1, "111222333222");

  str1.Add("");
  EXPECT_EQ(str1, "111222333222");

}

TEST(TestMyString, TestInsert) {
  MyString str1;
  MyString str2;

  str1.Insert(0, "1");
  EXPECT_EQ(str1, "1");

  str1.Insert(1, "2");
  EXPECT_EQ(str1, "12");

  str1.Insert(0, "3");
  EXPECT_EQ(str1, "312");

  str1.Insert(0, "");
  EXPECT_EQ(str1, "312");

  str1.Insert(3, "");
  EXPECT_EQ(str1, "312");

  str2 = "123";
  str1.Insert(0, str2);
  EXPECT_EQ(str1, "123312");

  str2 = "aaa";
  str1.Insert(6, str2);
  EXPECT_EQ(str1, "123312aaa");
}

TEST(TestMyString, TestRemove) {
  MyString str1("1234567890");
  MyString str2;


}