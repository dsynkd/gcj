#include <iostream>
#include <string>

using namespace std;

int main() {
	int n,c=0;
	int64_t w,b;
	cin >> n;
	while(c++ < n) {
		cin >> w;
		cin >> b;
		cout << "Case #" << c << ": ";
		if(w%2 == 1) {
			if(b%2 == 0)
				cout << "WHITE";
			else
				cout << "BLACK";
		}
		else {
			if(b%2 == 0)
				cout << "WHITE";
			else
				cout << "BLACK";
		}
		cout << endl;
	}
}
