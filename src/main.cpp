#include "../include/textgen.h"
#include <string>
#include <deque>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>

using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    string line;
    string text = "";
    ifstream in("text.txt");
    if (in.is_open())
    {
        while (getline(in, line))
        {
            text = text + line + " ";
        }
    }
    in.close();
    TextGen t = TextGen(text, 2);
    cout << t.GetText(1000) << endl;
	return 0;
}