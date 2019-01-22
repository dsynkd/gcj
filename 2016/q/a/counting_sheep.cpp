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
		vector<char> digits = {'0','1','2','3','4','5','6','7','8','9'};
		int N, i = 1;
		cin >> N;
		cout << "Case #" << c << ": ";
		bool solved = false;
		if(N == 0) {
			cout << "INSOMNIA";
		}
		else {
			int temp;
			while(!solved) {
				temp = i * N;
				string stemp = to_string(temp);
				for(char& ch : stemp) {
					if(find(digits.begin(), digits.end(), ch) != digits.end()) {
						digits.erase(find(digits.begin(), digits.end(), ch));
					}
				}
				if(digits.size() == 0)
					solved = true;
				i++;
			}
			cout << temp;
		}
		cout << endl;
	}
	return 0;
}
