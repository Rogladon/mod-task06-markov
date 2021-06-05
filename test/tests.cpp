// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include "../include/textgen.h"


TEST(task1, test1)
{
	TextGen gn = TextGen("123 234 567 1234", 3);
	string result = gn.GetText(1000);
	char* ch = new char[result.size() + 1];
	strcpy(ch, result.c_str());
	ASSERT_STREQ("123 234 567 1234 ", ch);
}
TEST(task1, test2)
{
	map<deque<string>, vector<string> > str;
	str[{"123", "567"}].push_back("234");
	TextGen gn = TextGen(str, { "123","567","234" }, 2);
	string result = gn.GetText(1000);
	char* ch = new char[result.size() + 1];
	strcpy(ch, result.c_str());
	ASSERT_STREQ("123 567 234 ", ch);
}
TEST(task1, test3)
{
	map<deque<string>, vector<string> > str;
	str[{"123", "567"}].push_back("234");
	str[{"123", "567"}].push_back("000");
	str[{"123", "567"}].push_back("888");
	TextGen gn = TextGen(str, { "123","567","234", "000", "888" }, 2);
	string result = gn.GetText(1000);
	bool res = false;
  if (result == "123 567 234 " || result == "123 567 000 " || result == "123 567 888 ") {
		res = true;
  }
	ASSERT_STREQ(true, res);
}
TEST(task1, test4)
{
	map<deque<string>, vector<string> > str;
	str[{"123", "567"}].push_back("234");
	str[{"567", "234"}].push_back("000");
	str[{"234", "000"}].push_back("888");
	TextGen gn = TextGen(str, { "123","567","234", "000", "888" }, 2);
	string result = gn.GetText(10);
	char* ch = new char[result.size() + 1];
	strcpy(ch, result.c_str());
	ASSERT_STREQ("123 567 234 000 ", ch);
}
