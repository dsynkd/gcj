#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int t, c = 0;
	cin >> t;
	while(c++<t) {
		string line;
		cin >> line;
		char lastch;
		int y = 0, x = 0;
		for(char &ch : line) {
			if(x == 0) {
				lastch = ch;
			}
			if(ch != lastch) {
				y++;
				lastch = ch;
			}
			x++;
			if(ch == '-' && x == line.size())
				y++;
		}
		cout << "Case #" << c << ": " << y << endl;
	}
}
