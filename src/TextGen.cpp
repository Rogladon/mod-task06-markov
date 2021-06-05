#include "..\include\TextGen.h"

TextGen::TextGen(string text, int nref)
{
	this->nref = nref;
	vector<string> words = vector<string>();
	string word = "";
	for (int i = 0; i < text.size(); i++) {
		if (text[i] != ' ' && text[i] != '\n' && text[i] != '\r' && text[i] != '\t')
			word += text[i];
		else {
			words.push_back(word);
			word = "";
		}
	}
	this->words = words;

	for(int i = 0; i< words.size(); i++) {
		prefix prf;
		for (int j = 0; j < nref; j++) {
			if (i + j >= words.size()) {
				break;
			}
			prf.push_back(words[i + j]);
		}
		if (i + nref >= words.size()) {
			this->statetab[prf].push_back(END_TEXT);
			break;
		}
		this->statetab[prf].push_back(words[i + nref]);
	}
	
}

TextGen::TextGen(map<prefix, vector<string>> map, vector<string> words, int nref)
{
	this->statetab = map;
	this->words = words;
	this->nref = nref;
}

string TextGen::GetText(int maxGen)
{
	string result = "";
	
	prefix prf;
	for (int i = 0; i < this->nref; i++) {
		prf.push_back(this->words[i]);
		result += this->words[i]+" ";
	}
	int count = result.size()-this->nref;
	while (count < maxGen) {
		
		if (this->statetab[prf].size() == 1 && this->statetab[prf][0] == END_TEXT)
			break;
		if (this->statetab[prf].size() == 0) 
			break;
		int index = rand() % statetab[prf].size();
		while (this->statetab[prf][index] == END_TEXT) {
			index = rand() % statetab[prf].size();
		}
		string suff = statetab[prf][index];
		result += suff+" ";
		prf.pop_front();
		prf.push_back(suff);
		count += suff.size();
	}
	return result;
}
