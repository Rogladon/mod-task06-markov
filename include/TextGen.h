#pragma once
#include <istream>
#include <deque>
#include <vector>
#include <map>

using namespace std;
typedef deque<string> prefix; 

const string END_TEXT = "END_TEXT";

class TextGen {
public:
	TextGen(string text, int nref);
	TextGen(map<prefix, vector<string> > map, vector<string> words, int nref);
	string GetText(int maxGen);

private:
	int nref = 2; 
	map<prefix, vector<string> > statetab; 
	vector<string> words;
};
