#include <iostream>
#include <string>
#include <map>
#include <cmath>

using namespace std;

int convert_base(int v, int b){ 
	if (v == 0)
		return 0;
	else
		return (v%b+10*convert_base(v/b,b));
}

int main() {
	int N,c=0;
	cin >> N;
	while(c++<N) {
		string input, middle = "", output = "";
		string source_lang_str, target_lang_str;
		cin >> input >> source_lang_str >> target_lang_str;
		map<char, int> src, tgt;
		int t = 0;
		for(char& ch : source_lang_str)
			src.insert(pair<char,int>(ch, t++));
		t = 0;
		for(char& ch : target_lang_str) {
			tgt.insert(pair<int,char>(t++, ch));
		}
		// middle language
		for(char& ch : input) {
			middle += char(src[ch] + 33);
		}
		// convert to decimal
		int src_base = source_lang_str.length();
		unsigned long dec = 0;
		for(int i = middle.length()-1; i >= 0; i--) {
			dec += pow(src_base,middle.length()-1-i) * (int(middle[i]) - 33);
		}
		// convert to target base but with target characters
		int target_base = target_lang_str.length();
		unsigned long b = target_base;
		while(b <= dec)
			b *= target_base;
		b /= target_base;
		while(b > 1) {
			output += tgt[dec/b];
			dec %= b;
			b /= target_base;
		}
		output += tgt[dec/b];
		cout << "Case #" << c << ": " << output << endl;
	}
}
